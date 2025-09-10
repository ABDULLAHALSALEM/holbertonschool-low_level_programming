#include "main.h"

/**
 * _pow_recursion - Returns x raised to the power of y.
 * @x: base value
 * @y: exponent value
 *
 * Return: x^y, or -1 if y < 0
 */
int _pow_recursion(int x, int y)
{
	if (y < 0)
		return (-1);      /* Error for negative exponent */

	if (y == 0)
		return (1);       /* Base case: x^0 = 1 */

	return (x * _pow_recursion(x, y - 1)); /* Recursive step */
}
