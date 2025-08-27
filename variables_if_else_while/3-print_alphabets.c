#include <stdio.h>

/**
 * main - يطبع الحروف a-z ثم A-Z
 * Return: Always 0
 */
int main(void)
{
	char ch;

	/* اطبع الحروف الصغيرة */
	for (ch = 'a'; ch <= 'z'; ch++)
	{
		putchar(ch);
	}

	/* اطبع الحروف الكبيرة */
	for (ch = 'A'; ch <= 'Z'; ch++)
	{
		putchar(ch);
	}

	/* اطبع سطر جديد */
	putchar('\n');

	return (0);
}
