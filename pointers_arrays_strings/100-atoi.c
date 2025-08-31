#include "main.h"

/**
 * _atoi - converts the first number found in a string to an integer
 * @s: pointer to the string
 *
 * Description: Skips non-digits first. Each '-' before the first
 * digit flips the sign. Once digits start, builds the number until
 * a non-digit is met. If no digits exist, returns 0.
 * Return: the converted integer
 */
int _atoi(char *s)
{
	int i = 0;
	int sign = 1;
	unsigned int num = 0;
	int started = 0;

	/* مرّ على ما قبل الرقم: اقلب الإشارة عند '-' وتجاهل غير ذلك */
	while (s[i] != '\0' && !started)
	{
		if (s[i] == '-')
			sign *= -1;
		else if (s[i] >= '0' && s[i] <= '9')
		{
			started = 1;
			num = (unsigned int)(s[i] - '0');
		}
		i++;
	}

	/* لو ما بدأنا أبدًا، ما فيه أرقام */
	if (!started)
		return (0);

	/* أكمل تجميع الأرقام المتتالية */
	while (s[i] >= '0' && s[i] <= '9')
	{
		num = (num * 10U) + (unsigned int)(s[i] - '0');
		i++;
	}

	/* طبّق الإشارة (النمط المعتاد في مشاريع هولبرتون) */
	if (sign < 0)
		return (-(int)num);
	return ((int)num);
}
