#include <stdio.h>

/**
 * main - يطبع أرقام base 16 (0-9 ثم a-f)
 * Return: Always 0
 */
int main(void)
{
	int num;
	char ch;

	/* اطبع الأرقام من 0 إلى 9 */
	for (num = 0; num < 10; num++)
	{
		putchar(num + '0');
	}

	/* اطبع الحروف من a إلى f */
	for (ch = 'a'; ch <= 'f'; ch++)
	{
		putchar(ch);
	}

	/* اطبع سطر جديد */
	putchar('\n');

	return (0);
}
