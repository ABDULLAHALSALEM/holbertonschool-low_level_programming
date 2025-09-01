#include "main.h"

/**
 * cap_string - capitalizes all words of a string
 * @str: pointer to the string
 *
 * Return: pointer to the modified string
 */
char *cap_string(char *str)
{
	int i = 0;
	int j;

	char sep[] = " \t\n,;.!?\"(){}";

	while (str[i] != '\0')
	{
		/* check if first char or after a separator */
		if (i == 0 && (str[i] >= 'a' && str[i] <= 'z'))
		{
			str[i] -= 32;
		}
		else
		{
			for (j = 0; sep[j] != '\0'; j++)
			{
				if (str[i - 1] == sep[j] && (str[i] >= 'a' && str[i] <= 'z'))
				{
					str[i] -= 32;
					break;
				}
			}
		}
		i++;
	}
	return (str);
}
