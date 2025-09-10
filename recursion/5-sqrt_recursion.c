#include "main.h"

/**
 * sqrt_helper - Recursively tries integer guesses for sqrt(n).
 * @n: the original number
 * @g: current guess (candidate root)
 *
 * Return: g if g*g == n, -1 if g*g is greater than n,
 *         otherwise keep trying with g + 1.
 */
static int sqrt_helper(int n, int g)
{
	if (g * g == n)
		return (g);
	if (g * g > n)
		return (-1);
	return (sqrt_helper(n, g + 1));
}

/**
 * _sqrt_recursion - Returns the natural square root of a number.
 * @n: integer input
 *
 * Return: the natural square root of n, or -1 if none exists or n < 0
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
        return (-1);
	if (n == 0 || n == 1)
		return (n);
	return (sqrt_helper(n, 1));
}
