#ifndef FUNCTION_POINTERS_H
#define FUNCTION_POINTERS_H

/* منصّة التصحيح توفّر _putchar؛ استخدمه فقط إذا احتجته في ملفات أخرى */
int _putchar(char c);

/* بروتوتايب المطلوب في هذا التمرين */
void print_name(char *name, void (*f)(char *));

#endif /* FUNCTION_POINTERS_H */
