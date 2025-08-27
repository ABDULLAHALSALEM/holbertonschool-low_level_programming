#include <stdio.h>

/**
 * main - يطبع كل الأرقام مع فاصلة ومسافة
 * Return: Always 0
 */
int main(void)
{
	int num;

	for (num = 0; num < 10; num++)
	{
		putchar(num + '0'); /* نحول الرقم لحرف */

		if (num != 9) /* عشان آخر رقم ما يكون بعده فاصلة */
		{
			putchar(',');
			putchar(' ');
		}
	}

	putchar('\n');
	return (0);
}
