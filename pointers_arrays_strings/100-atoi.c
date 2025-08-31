#include "main.h"
#include <limits.h>

/**
 * _atoi - converts the first number found in a string to an integer
 * @s: pointer to the string
 *
 * Description: Handles any number of '+' and '-' signs that appear
 * before the first digit. If no digits are present, returns 0.
 * Return: the converted integer
 */
int _atoi(char *s)
{
	int i = 0;
	int sign = 1;
	unsigned int num = 0;
	int started = 0;

	while (s[i] != '\0')
	{
		if (!started)
		{
			if (s[i] == '-')
				sign *= -1;
			else if (s[i] >= '0' && s[i] <= '9')
			{
				started = 1;
				num = (unsigned int)(s[i] - '0');
			}
			/* '+' وأي رموز أخرى قبل الأرقام تُتجاهل */
		}
		else
		{
			if (s[i] >= '0' && s[i] <= '9')
			{
				unsigned int digit = (unsigned int)(s[i] - '0');
				num = (num * 10U) + digit; /* تجميع آمن (unsigned) */
			}
			else
			{
				break;
			}
		}
		i++;
	}

	if (!started)
		return (0);

	/* معالجة INT_MIN بأمان: -2147483648 = -(INT_MAX + 1) */
	if (sign == -1)
	{
		if (num == (unsigned int)INT_MAX + 1U)
			return (INT_MIN);
		return (-(int)num);
	}

	/* في الجانب الموجب: التحويل العادي (سلوك مثل atoi) */
	return ((int)num);
}
