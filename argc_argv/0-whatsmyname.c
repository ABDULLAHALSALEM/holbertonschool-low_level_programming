#include <stdio.h>

/**
 * main - prints the program name (including path), then a newline
 * @argc: argument count (unused)
 * @argv: argument vector; argv[0] is the invoked program name
 * Return: 0
 */
int main(int argc, char *argv[])
{
    (void)argc;          /* نتجاهل argc لتفادي تحذير -Wall/-Werror */
    printf("%s\n", argv[0]);
    return (0);
}`
