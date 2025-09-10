#include <stdio.h>
#include <stdlib.h>

/**
 * main - multiplies two numbers given as command-line arguments
 * @argc: number of arguments
 * @argv: array of argument strings
 *
 * Return: 0 on success; 1 if the program does not receive two arguments.
 */
int main(int argc, char *argv[])
{
	int a, b, product;

	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}

	a = atoi(argv[1]);
	b = atoi(argv[2]);
	product = a * b;

	printf("%d\n", product);
	return (0);
}
