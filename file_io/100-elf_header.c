#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <elf.h>

/* ----- helpers: byte swap (for big endian files on little-endian host) ----- */
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
	unsigned int hi = (unsigned int)(x >> 32);
	unsigned int lo = (unsigned int)(x & 0xFFFFFFFFul);

	return (((unsigned long)swap32(lo) << 32) | (unsigned long)swap32(hi));
}

/* ------------------------- pretty printers (Betty) ------------------------- */
static void print_magic(unsigned char *e)
{
	int i;

	printf("ELF Header:\n");
	printf("  Magic:  ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x%s", e[i], i == EI_NIDENT - 1 ? "" : " ");
	printf("\n");
}

static void print_class(unsigned char c)
{
	printf("  Class:                             ");
	if (c == ELFCLASS32)
		printf("ELF32\n");
	else if (c == ELFCLASS64)
		printf("ELF64\n");
	else
		printf("<unknown: %x>\n", c);
}

static void print_data(unsigned char d)
{
	printf("  Data:                              ");
	if (d == ELFDATA2LSB)
		printf("2's complement, little endian\n");
	else if (d == ELFDATA2MSB)
		printf("2's complement, big endian\n");
	else
		printf("none\n");
}

static void print_version(unsigned char v)
{
	printf("  Version:                           %d (current)\n", v);
}

static void print_osabi(unsigned char o)
{
	const char *name = NULL;

	switch (o)
	{
	case ELFOSABI_SYSV: name = "UNIX - System V"; break;
	case ELFOSABI_HPUX: name = "UNIX - HP-UX"; break;
	case ELFOSABI_NETBSD: name = "UNIX - NetBSD"; break;
	case ELFOSABI_LINUX: name = "UNIX - Linux"; break;
	case ELFOSABI_SOLARIS: name = "UNIX - Solaris"; break;
	case ELFOSABI_FREEBSD: name = "UNIX - FreeBSD"; break;
	case ELFOSABI_OPENBSD: name = "UNIX - OpenBSD"; break;
	default: break;
	}
	printf("  OS/ABI:                            ");
	if (name)
		printf("%s\n", name);
	else
		printf("<unknown: %x>\n", o);
}

static void print_abiversion(unsigned char v)
{
	printf("  ABI Version:                       %d\n", v);
}

static void print_type(unsigned short t, int is_msb)
{
	if (is_msb)
		t = swap16(t);

	printf("  Type:                              ");
	switch (t)
	{
	case ET_NONE: printf("NONE (None)\n"); break;
	case ET_REL:  printf("REL (Relocatable file)\n"); break;
	case ET_EXEC: printf("EXEC (Executable file)\n"); break;
	case ET_DYN:  printf("DYN (Shared object file)\n"); break;
	case ET_CORE: printf("CORE (Core file)\n"); break;
	default:      printf("<unknown: %x>\n", t); break;
	}
}

static void print_entry_32(unsigned int e, int is_msb)
{
	if (is_msb)
		e = swap32(e);
	printf("  Entry point address:               0x%x\n", e);
}

static void print_entry_64(unsigned long e, int is_msb)
{
	if (is_msb)
		e = swap64(e);
	printf("  Entry point address:               0x%lx\n", e);
}

/* ---------------------------------- main ---------------------------------- */
/**
 * main - Display the information in the ELF header of a given file.
 * @ac: argument count.
 * @av: argument vector.
 *
 * Return: 0 on success. On error, prints to STDERR and exits with 98.
 */
int main(int ac, char **av)
{
	int fd, is_msb;
	ssize_t nread;
	unsigned char ident[EI_NIDENT];
	Elf64_Ehdr h64;

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

	/* read ident first to validate ELF, then read full header once */
	nread = read(fd, ident, EI_NIDENT);
	if (nread != EI_NIDENT ||
	    ident[EI_MAG0] != ELFMAG0 || ident[EI_MAG1] != ELFMAG1 ||
	    ident[EI_MAG2] != ELFMAG2 || ident[EI_MAG3] != ELFMAG3)
	{
		dprintf(STDERR_FILENO, "Error: Not an ELF file: %s\n", av[1]);
		close(fd);
		exit(98);
	}

	/* we already read EI_NIDENT; read the rest of header into h64 */
	lseek(fd, 0, SEEK_SET);
	nread = read(fd, &h64, sizeof(h64));
	if (nread < (ssize_t)sizeof(Elf32_Ehdr))
	{
		dprintf(STDERR_FILENO, "Error: Short read on ELF header: %s\n", av[1]);
		close(fd);
		exit(98);
	}

	is_msb = (ident[EI_DATA] == ELFDATA2MSB);

	print_magic(ident);
	print_class(ident[EI_CLASS]);
	print_data(ident[EI_DATA]);
	print_version(ident[EI_VERSION]);
	print_osabi(ident[EI_OSABI]);
	print_abiversion(ident[EI_ABIVERSION]);

	if (ident[EI_CLASS] == ELFCLASS32)
	{
		Elf32_Ehdr *h32 = (Elf32_Ehdr *)&h64;

		print_type(h32->e_type, is_msb);
		print_entry_32(h32->e_entry, is_msb);
	}
	else if (ident[EI_CLASS] == ELFCLASS64)
	{
		print_type(h64.e_type, is_msb);
		print_entry_64(h64.e_entry, is_msb);
	}
	else
	{
		dprintf(STDERR_FILENO, "Error: Unknown ELF class in %s\n", av[1]);
		close(fd);
		exit(98);
	}

	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(98);
	}
	return (0);
}
