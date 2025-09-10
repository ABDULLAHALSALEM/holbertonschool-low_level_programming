#include <stdio.h>

/**
 * main - prints the name used to invoke the program
 * @argc: number of command-line arguments
 * @argv: array of argument strings (argv[0] is the program name)
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	/* avoid unused-parameter warning */
	(void)argc;

	printf("%s\n", argv[0]);
	return (0);
}
