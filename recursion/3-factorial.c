#include "main.h"

/**
 * factorial - Returns the factorial of a given number.
 * @n: integer value
 *
 * Return: n! if n >= 0, or -1 if n < 0 (error)
 */
int factorial(int n)
{
	if (n < 0)
		return (-1); /* Error for negative input */

	if (n == 0)
		return (1);  /* Base case: 0! = 1 */

	return (n * factorial(n - 1)); /* Recursive case */
}
