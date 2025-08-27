#include <stdio.h>

/**
 * main - يطبع الحروف a-z ما عدا e و q
 * Return: Always 0
 */
int main(void)
{
	char ch;

	for (ch = 'a'; ch <= 'z'; ch++)
	{
		if (ch != 'e' && ch != 'q') /* تجاهل e و q */
		{
			putchar(ch);
		}
	}
	putchar('\n'); /* سطر جديد */

	return (0);
}
