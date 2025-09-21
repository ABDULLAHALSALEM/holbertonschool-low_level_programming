#include "3-calc.h"

/**
 * op_add - returns a + b
 * @a: first operand
 * @b: second operand
 * Return: sum
 */
int op_add(int a, int b) { return (a + b); }

/**
 * op_sub - returns a - b
 * @a: first operand
 * @b: second operand
 * Return: difference
 */
int op_sub(int a, int b) { return (a - b); }

/**
 * op_mul - returns a * b
 * @a: first operand
 * @b: second operand
 * Return: product
 */
int op_mul(int a, int b) { return (a * b); }

/**
 * op_div - returns a / b (no zero check here; main handles it)
 * @a: first operand
 * @b: second operand
 * Return: quotient
 */
int op_div(int a, int b) { return (a / b); }

/**
 * op_mod - returns a % b (no zero check here; main handles it)
 * @a: first operand
 * @b: second operand
 * Return: remainder
 */
int op_mod(int a, int b) { return (a % b); }
