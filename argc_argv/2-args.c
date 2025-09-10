#include <stdio.h>

/**
 * main - prints all arguments it receives, one per line
 * @argc: number of command-line arguments
 * @argv: array of argument strings (argv[0] is the program name)
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	int i;

	for (i = 0; i < argc; i++)
		printf("%s\n", argv[i]);

	return (0);
}
