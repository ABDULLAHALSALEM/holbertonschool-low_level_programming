#include "main.h"

/* Forward declaration */
int sqrt_search(int n, int low, int high);

/**
 * _sqrt_recursion - Returns the natural square root of a number.
 * @n: integer input
 *
 * Return: sqrt(n) if n is a perfect square, else -1
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	if (n == 0 || n == 1)
		return (n);

	/* Upper bound: for n >= 2, sqrt(n) <= n / 2 + 1 */
	return (sqrt_search(n, 1, n / 2 + 1));
}

/**
 * sqrt_search - Binary-searches for the integer sqrt of n.
 * @n: target number
 * @low: lower bound
 * @high: upper bound
 *
 * Return: sqrt(n) if found, else -1
 */
int sqrt_search(int n, int low, int high)
{
	int mid;

	if (low > high)
		return (-1);

	mid = low + (high - low) / 2;

	/* Avoid overflow: compare mid to n / mid */
	if (mid == n / mid && mid * mid == n)
		return (mid);

	if (mid > n / mid)            /* mid^2 > n */
		return (sqrt_search(n, low, mid - 1));
	else                           /* mid^2 < n */
		return (sqrt_search(n, mid + 1, high));
}
