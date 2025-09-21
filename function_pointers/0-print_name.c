#include "function_pointers.h"

/**
 * print_name - يستدعي دالة الطباعة الممرّرة لطباعة الاسم.
 * @name: الاسم المراد طباعته.
 * @f: مؤشّر لدالة تستقبل (char *) ولا تعيد قيمة.
 *
 * Return: لا شيء.
 */
void print_name(char *name, void (*f)(char *))
{
	if (!name || !f)
		return;

	f(name);
}
