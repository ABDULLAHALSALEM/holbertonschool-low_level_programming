#include "function_pointers.h"

/**
 * print_name - يستدعي دالة الطباعة الممرّرة لطباعة الاسم
 * @name: الاسم
 * @f:    مؤشّر لدالة تأخذ (char *) ولا ترجع شيئاً
 *
 * Return: لا شيء.
 */
void print_name(char *name, void (*f)(char *))
{
	if (!name || !f)
		return;

	f(name);
}
