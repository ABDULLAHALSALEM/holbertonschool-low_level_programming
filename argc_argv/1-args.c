#include <stdio.h>

/**
 * main - prints how many arguments were passed (excluding program name)
 * @argc: number of command-line arguments
 * @argv: array of argument strings (unused)
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	(void)argv;            /* avoid unused-parameter warning */
	printf("%d\n", argc - 1);
	return (0);
}
