#include <stdio.h>
#include "main.h"

/**
 * main - prints the numbers from 1 to 100 with FizzBuzz rules
 *
 * Return: Always 0
 */
int main(void)
{
    int i;

    for (i = 1; i <= 100; i++)
    {
        if (i % 3 == 0 && i % 5 == 0)
            printf("FizzBuzz");
        else if (i % 3 == 0)
            printf("Fizz");
        else if (i % 5 == 0)
            printf("Buzz");
        else
            printf("%d", i);

        if (i < 100) /* put a space after every output except the last one */
            printf(" ");
    }

    printf("\n"); /* newline at the end */
    return (0);
}
