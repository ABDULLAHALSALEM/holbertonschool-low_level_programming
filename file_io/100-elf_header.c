#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <elf.h>

/* ---------- helpers for endianness ---------- */

/**
 * bswap16 - swap bytes in 16-bit value (MSB <-> LSB).
 * @x: value.
 * Return: swapped value.
 */
static unsigned short bswap16(unsigned short x)
{
	return ((x >> 8) | (x << 8));
}

/**
 * bswap32 - swap bytes in 32-bit value.
 * @x: value.
 * Return: swapped value.
 */
static unsigned int bswap32(unsigned int x)
{
	return ((x >> 24) | ((x >> 8) & 0x0000FF00) |
		((x << 8) & 0x00FF0000) | (x << 24));
}

/**
 * bswap64 - swap bytes in 64-bit value.
 * @x: value.
 * Return: swapped value.
 */
static unsigned long long bswap64(unsigned long long x)
{
	return ((unsigned long long)bswap32(x & 0xFFFFFFFFULL) << 32) |
		(bswap32((x >> 32) & 0xFFFFFFFFULL));
}

/* ---------- printing helpers ---------- */

/**
 * print_osabi - print OS/ABI string like readelf.
 * @osabi: EI_OSABI value.
 */
static void print_osabi(unsigned char osabi)
{
	switch (osabi)
	{
	case ELFOSABI_SYSV:   printf("UNIX - System V\n"); break;
	case ELFOSABI_HPUX:   printf("UNIX - HP-UX\n"); break;
	case ELFOSABI_NETBSD: printf("UNIX - NetBSD\n"); break;
	case ELFOSABI_LINUX:  printf("UNIX - Linux\n"); break;
	case ELFOSABI_SOLARIS:printf("UNIX - Solaris\n"); break;
	case ELFOSABI_IRIX:   printf("UNIX - IRIX\n"); break;
	case ELFOSABI_FREEBSD:printf("UNIX - FreeBSD\n"); break;
	case ELFOSABI_TRU64:  printf("UNIX - TRU64\n"); break;
	case ELFOSABI_ARM:    printf("ARM\n"); break;
	case ELFOSABI_STANDALONE: printf("Standalone App\n"); break;
	default: printf("<unknown: %u>\n", osabi); break;
	}
}

/**
 * print_type - print file type like readelf.
 * @etype: e_type value (host-endian).
 */
static void print_type(unsigned short etype)
{
	switch (etype)
	{
	case ET_NONE: printf("NONE (None)\n"); break;
	case ET_REL:  printf("REL (Relocatable file)\n"); break;
	case ET_EXEC: printf("EXEC (Executable file)\n"); break;
	case ET_DYN:  printf("DYN (Shared object file)\n"); break;
	case ET_CORE: printf("CORE (Core file)\n"); break;
	default: printf("<unknown: %u>\n", etype); break;
	}
}

/**
 * main - Display information from the ELF header.
 * @ac: argument count.
 * @av: argument vector.
 *
 * Return: 0 on success, exits 98 on error (with message to STDERR).
 */
int main(int ac, char **av)
{
	int fd;
	ssize_t r;
	Elf64_Ehdr hdr;
	unsigned int is_be;
	unsigned short etype;
	unsigned long long entry;

	if (ac != 2)
	{
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n");
		exit(98);
	}

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", av[1]);
		exit(98);
	}

	r = read(fd, &hdr, sizeof(hdr));
	if (r != (ssize_t)sizeof(hdr))
	{
		dprintf(STDERR_FILENO, "Error: Can't read ELF header %s\n", av[1]);
		close(fd);
		exit(98);
	}

	if (hdr.e_ident[EI_MAG0] != ELFMAG0 || hdr.e_ident[EI_MAG1] != ELFMAG1 ||
	    hdr.e_ident[EI_MAG2] != ELFMAG2 || hdr.e_ident[EI_MAG3] != ELFMAG3)
	{
		dprintf(STDERR_FILENO, "Error: Not an ELF file: %s\n", av[1]);
		close(fd);
		exit(98);
	}

	printf("ELF Header:\n");
	/* Magic */
	printf("  Magic:  ");
	for (int i = 0; i < EI_NIDENT; i++)
		printf("%02x%s", hdr.e_ident[i],
		       i + 1 == EI_NIDENT ? "\n" : " ");

	/* Class */
	printf("  Class:                             ");
	if (hdr.e_ident[EI_CLASS] == ELFCLASS32)
		printf("ELF32\n");
	else if (hdr.e_ident[EI_CLASS] == ELFCLASS64)
		printf("ELF64\n");
	else
		printf("<unknown: %u>\n", hdr.e_ident[EI_CLASS]);

	/* Data */
	printf("  Data:                              ");
	if (hdr.e_ident[EI_DATA] == ELFDATA2LSB)
		printf("2's complement, little endian\n");
	else if (hdr.e_ident[EI_DATA] == ELFDATA2MSB)
		printf("2's complement, big endian\n");
	else
		printf("Invalid data encoding\n");

	/* Version */
	printf("  Version:                           ");
	if (hdr.e_ident[EI_VERSION] == EV_CURRENT)
		printf("1 (current)\n");
	else
		printf("%u\n", hdr.e_ident[EI_VERSION]);

	/* OS/ABI */
	printf("  OS/ABI:                            ");
	print_osabi(hdr.e_ident[EI_OSABI]);

	/* ABI Version */
	printf("  ABI Version:                       %u\n",
	       hdr.e_ident[EI_ABIVERSION]);

	/* Endianness-aware fields */
	is_be = (hdr.e_ident[EI_DATA] == ELFDATA2MSB);

	etype = hdr.e_type;
	if (is_be)
		etype = bswap16(etype);

	printf("  Type:                              ");
	print_type(etype);

	/* Entry point (32/64 + endianness) */
	if (hdr.e_ident[EI_CLASS] == ELFCLASS32)
	{
		unsigned int e32 = ((Elf32_Ehdr *)&hdr)->e_entry;

		if (is_be)
			e32 = bswap32(e32);
		printf("  Entry point address:               0x%x\n", e32);
	}
	else
	{
		entry = hdr.e_entry;
		if (is_be)
			entry = bswap64(entry);
		printf("  Entry point address:               0x%lx\n",
		       (unsigned long)entry);
	}

	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(98);
	}
	return (0);
}
