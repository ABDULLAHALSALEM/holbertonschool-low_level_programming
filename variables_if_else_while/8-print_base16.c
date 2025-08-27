#include <stdio.h>

/**
 * main  base 16 (0-9 «Ù… a-f)
 * Return: Always 0
 */
int main(void)
{
	int num;
	char ch;

	for (num = 0; num < 10; num++)
	{
		putchar(num + '0');
	}

	for (ch = 'a'; ch <= 'f'; ch++)
	{
		putchar(ch);
	}

	putchar('\n');

	return (0);
}

