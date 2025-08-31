#include "main.h"

/**
 * puts_half - prints the second half of a string, then a new line
 * @str: pointer to the string
 *
 * Return: nothing
 */
void puts_half(char *str)
{
	int len = 0;
	int start;
	int i;

	/* احسب الطول */
	while (str[len] != '\0')
	{
		len++;
	}

	/* حدّد نقطة البداية حسب طول النص */
	if ((len % 2) == 0)
	{
		start = len / 2;
	}
	else
	{
		start = (len + 1) / 2;
	}

	/* اطبع من start إلى آخر حرف */
	for (i = start; i < len; i++)
	{
		_putchar(str[i]);
	}
	_putchar('\n');
}
