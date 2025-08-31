#include "main.h"

/**
 * rev_string - reverses a string in place
 * @s: pointer to the string buffer to reverse (must be writable)
 *
 * Return: nothing
 */
void rev_string(char *s)
{
	int i = 0;
	int j = 0;
	char tmp;

	/* احسب الطول للوصول لآخر حرف قبل '\0' */
	while (s[j] != '\0')
	{
		j++;
	}

	/* الآن j يشير لعدد الأحرف؛ خلّه يرجع لآخر حرف */
	j = j - 1;

	/* بدّل من الطرفين حتى المنتصف */
	while (i < j)
	{
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
		i++;
		j--;
	}
}
