#include "main.h"

/**
 * _atoi - converts the first number found in a string to an integer
 * @s: pointer to the string
 *
 * Description: Takes into account any number of '+' and '-' signs
 * that appear before the first digit. If the string contains no
 * digits, the function returns 0.
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
			/* '+' وأي شيء آخر قبل الأرقام نتجاهله */
		}
		else
		{
			if (s[i] >= '0' && s[i] <= '9')
				num = (num * 10) + (unsigned int)(s[i] - '0');
			else
				break;
		}
		i++;
	}

	if (!started)
		return (0);

	return (sign * (int)num);
}
