#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

/* ----- helpers: endian swap when file is big-endian ----- */
static unsigned short swap16(unsigned short x)
{
	return ((x >> 8) | (x << 8));
}

static unsigned int swap32(unsigned int x)
{
	return ((x >> 24) |
		((x >> 8) & 0x0000FF00) |
		((x << 8) & 0x00FF0000) |
		(x << 24));
}

static unsigned long swap64(unsigned long x)
{
	return ((x >> 56) |
		((x >> 40) & 0x000000000000FF00UL) |
		((x >> 24) & 0x0000000000FF0000UL) |
		((x >> 8)  & 0x00000000FF000000UL) |
		((x << 8)  & 0x000000FF00000000UL) |
		((x << 24) & 0x0000FF0000000000UL) |
		((x << 40) & 0x00FF000000000000UL) |
		(x << 56));
}

/* ----- maps ----- */
static const char *osabi_name(unsigned char osabi)
{
	switch (osabi)
	{
	case ELFOSABI_SYSV: return "UNIX - System V";
	case ELFOSABI_HPUX: return "UNIX - HP-UX";
	case ELFOSABI_NETBSD: return "UNIX - NetBSD";
	case ELFOSABI_GNU: return "UNIX - GNU";
	case ELFOSABI_SOLARIS: return "UNIX - Solaris";
	case ELFOSABI_AIX: return "UNIX - AIX";
	case ELFOSABI_IRIX: return "UNIX - IRIX";
	case ELFOSABI_FREEBSD: return "UNIX - FreeBSD";
	case ELFOSABI_TRU64: return "UNIX - TRU64";
	case ELFOSABI_ARM: return "ARM";
	case ELFOSABI_STANDALONE: return "Standalone App";
	default: return "<unknown: %u>";
	}
}

static const char *type_name(unsigned int t)
{
	switch (t)
	{
	case ET_NONE: return "NONE (None)";
	case ET_REL: return "REL (Relocatable file)";
	case ET_EXEC: return "EXEC (Executable file)";
	case ET_DYN: return "DYN (Shared object file)";
	case ET_CORE: return "CORE (Core file)";
	default: return "<unknown: %u>";
	}
}

/**
 * print_header - Print the requested header fields like readelf -h.
 * @e: pointer to bytes containing an ELF header (64 bytes at least).
 */
static void print_header(const unsigned char *e)
{
	int i;
	int is64 = (e[EI_CLASS] == ELFCLASS64);
	int msb = (e[EI_DATA] == ELFDATA2MSB);
	unsigned int type, version;
	unsigned char osabi, abiver;
	unsigned long entry;

	printf("ELF Header:\n");
	printf("  Magic:  ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x%s", e[i], i + 1 == EI_NIDENT ? "\n" : " ");

	printf("  Class:                             %s\n",
		(e[EI_CLASS] == ELFCLASS64) ? "ELF64" :
		(e[EI_CLASS] == ELFCLASS32) ? "ELF32" : "Invalid class");

	printf("  Data:                              %s\n",
		(e[EI_DATA] == ELFDATA2LSB) ?
		"2's complement, little endian" :
		(e[EI_DATA] == ELFDATA2MSB) ?
		"2's complement, big endian" : "Invalid data encoding");

	version = e[EI_VERSION];
	printf("  Version:                           %u (current)\n",
	       version);

	osabi = e[EI_OSABI];
	printf("  OS/ABI:                            ");
	if (osabi_name(osabi)[0] == '<')
		printf(osabi_name(osabi), osabi), printf("\n");
	else
		printf("%s\n", osabi_name(osabi));

	abiver = e[EI_ABIVERSION];
	printf("  ABI Version:                       %u\n", abiver);

	/* type is 16-bit at offset 16, entry at 0x18 (32) or 0x18 (64) */
	if (is64)
	{
		const Elf64_Ehdr *h = (const Elf64_Ehdr *)e;
		type = h->e_type;
		entry = h->e_entry;
	} else
	{
		const Elf32_Ehdr *h = (const Elf32_Ehdr *)e;
		type = h->e_type;
		entry = h->e_entry;
	}

	if (msb)
	{
		type = swap16((unsigned short)type);
		entry = is64 ? swap64(entry) : swap32((unsigned int)entry);
	}

	printf("  Type:                              ");
	if (type_name(type)[0] == '<')
		printf(type_name(type), type), printf("\n");
	else
		printf("%s\n", type_name(type));

	printf("  Entry point address:               0x%lx\n", entry);
}

/**
 * main - Display information from the ELF header.
 * @ac: argc
 * @av: argv
 * Return: 0 on success, 98 on any error.
 */
int main(int ac, char **av)
{
	int fd;
	ssize_t n;
	unsigned char hdr[sizeof(Elf64_Ehdr)];

	if (ac != 2)
	{
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n");
		return (98);
	}

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", av[1]);
		return (98);
	}

	n = read(fd, hdr, sizeof(hdr));
	if (n < (ssize_t)EI_NIDENT)
	{
		dprintf(STDERR_FILENO, "Error: File too small to be ELF: %s\n", av[1]);
		close(fd);
		return (98);
	}

	if (!(hdr[EI_MAG0] == 0x7f && hdr[EI_MAG1] == 'E' &&
	      hdr[EI_MAG2] == 'L' && hdr[EI_MAG3] == 'F'))
	{
		dprintf(STDERR_FILENO, "Error: Not an ELF file: %s\n", av[1]);
		close(fd);
		return (98);
	}

	print_header(hdr);

	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		return (98);
	}
	return (0);
}
