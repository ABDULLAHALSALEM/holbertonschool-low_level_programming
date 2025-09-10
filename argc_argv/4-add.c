#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * is_positive_number - checks if a string has only digits (at least one)
 * @s: input C-string
 *
 * Return: 1 if s contains only '0'..'9' and not empty, otherwise 0.
 */
static int is_positive_number(const char *s)
{
	int i = 0;

	if (s[0] == '\0')
		return (0);

	while (s[i] != '\0')
	{
		if (!isdigit((unsigned char)s[i]))
			return (0);
		i++;
	}
	return (1);
}

/**
 * main - adds positive numbers passed as command-line arguments
 * @argc: number of command-line arguments
 * @argv: array of argument strings
 *
 * Return: 0 on success; 1 if a non-digit symbol appears in any argument.
 */
int main(int argc, char *argv[])
{
	int i, sum = 0;

	if (argc == 1)
	{
		printf("0\n");
		return (0);
	}

	for (i = 1; i < argc; i++)
	{
		if (!is_positive_number(argv[i]))
		{
			printf("Error\n");
			return (1);
		}
		sum += atoi(argv[i]);
	}

	printf("%d\n", sum);
	return (0);
}
