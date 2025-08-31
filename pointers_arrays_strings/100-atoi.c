#include "main.h"
#include <limits.h>

/**
 * _atoi - converts the first number found in a string to an integer
 * @s: pointer to the string
 *
 * Description: Flips sign for each '-' before the first digit.
 * Builds the number from consecutive digits. If no digits exist,
 * returns 0. Handles INT_MIN safely using (INT_MAX + 1U).
 * Return: the converted integer
 */
int _atoi(char *s)
{
	int i = 0;
	int sign = 1;
	unsigned int num = 0;
	int started = 0;

	/* مرّ على المقدمة: اقلب الإشارة عند '-'، وابدأ عند أول رقم */
	while (s[i] != '\0' && !started)
	{
		if (s[i] == '-')
			sign = -sign;
		else if (s[i] >= '0' && s[i] <= '9')
		{
			started = 1;
			num = (unsigned int)(s[i] - '0');
		}
		i++;
	}

	if (!started)
		return (0);

	/* أجمع بقية الأرقام المتتالية */
	while (s[i] >= '0' && s[i] <= '9')
	{
		num = (num * 10U) + (unsigned int)(s[i] - '0');
		i++;
	}

	/* طبّق الإشارة مع معالجة خاصة لـ INT_MIN */
	if (sign < 0)
	{
		if (num == (unsigned int)INT_MAX + 1U)
			return (INT_MIN);
		return (-(int)num);
	}
	return ((int)num);
}
