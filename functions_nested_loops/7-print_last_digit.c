#include "main.h"

/**
 * print_last_digit - prints the last digit of a number
 * @n: the number to process
 *
 * Return: the value of the last digit (always non-negative)
 */
int print_last_digit(int n)
{
	int d;

	d = n % 10;        /* خذ الباقي = آخر رقم */
	if (d < 0)
		d = -d;       /* لو سالب نخليه موجب */

	_putchar('0' + d); /* نطبع الرقم كحرف */
	return (d);        /* ونرجعه كقيمة */
}
