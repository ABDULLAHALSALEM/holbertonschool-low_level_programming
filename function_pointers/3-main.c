#include "3-calc.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - entry point for the simple calculator
 * @argc: argument count
 * @argv: argument vector ["calc", num1, op, num2]
 *
 * Return: 0 on success, or exits with 98/99/100 on errors
 */
int main(int argc, char **argv)
{
	int a, b, res;
	int (*op)(int, int);

	if (argc != 4) /* if #args is wrong */
	{
		printf("Error\n");
		exit(98);
	}

	op = get_op_func(argv[2]);
	if (op == NULL || argv[2][1] != '\0') /* invalid operator or length>1 */
	{
		printf("Error\n");
		exit(99);
	}

	a = atoi(argv[1]);
	b = atoi(argv[3]);
	if ((argv[2][0] == '/' || argv[2][0] == '%') && b == 0) /* div/mod by 0 */
	{
		printf("Error\n");
		exit(100);
	}

	res = op(a, b);
	printf("%d\n", res);
	return (0);
}
