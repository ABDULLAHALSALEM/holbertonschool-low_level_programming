#include <stdio.h>

/**
 * main - يطبع الحروف الإنجليزية من a إلى z
 * Return: Always 0
 */
int main(void)
{
	char ch;

	for (ch = 'a'; ch <= 'z'; ch++)
	{
		putchar(ch);
	}
	putchar('\n'); /* عشان يطبع سطر جديد */

	return (0);
}
