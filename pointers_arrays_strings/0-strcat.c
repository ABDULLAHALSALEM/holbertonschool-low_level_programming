#include "main.h"

/**
 * _strcat - يدمج src في آخر dest
 * @dest: السلسلة الهدف (فيها مساحة كافية)
 * @src:  السلسلة المصدر
 *
 * Return: مؤشر إلى dest
 */
char *_strcat(char *dest, char *src)
{
    int i = 0;  /* نمشي حتى نهاية dest */
    int j = 0;  /* نمشي على src وننسخ */

    /* 1) نصل لنهاية dest بدون لمس محتواها */
    while (dest[i] != '\0')
        i++;

    /* 2) ننسخ src حرفاً حرفاً بعد نهاية dest */
    while (src[j] != '\0')
    {
        dest[i] = src[j];
        i++;
        j++;
    }

    /* 3) نضيف حرف النهاية الجديد */
    dest[i] = '\0';

    return dest;
}
