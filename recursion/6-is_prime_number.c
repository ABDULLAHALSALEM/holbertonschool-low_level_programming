#include "main.h"

/* Forward declaration of the helper */
int prime_check(int n, int d);

/**
 * is_prime_number - Checks if an integer is a prime number.
 * @n: integer to check
 *
 * Return: 1 if n is prime, otherwise 0
 */
int is_prime_number(int n)
{
	if (n <= 1)
		return (0);
	if (n == 2)
		return (1);
	if (n % 2 == 0)
		return (0);

	/* Start checking odd divisors from 3 upward */
	return (prime_check(n, 3));
}

/**
 * prime_check - Recursively tests odd divisors up to sqrt(n).
 * @n: target number
 * @d: current odd divisor candidate
 *
 * Return: 1 if prime, 0 otherwise
 */
int prime_check(int n, int d)
{
	/* If d*d > n, no divisors left -> n is prime */
	if (d > n / d)
		return (1);

	if (n % d == 0)
		return (0);

	/* Skip even numbers by jumping in steps of 2 */
	return (prime_check(n, d + 2));
}
