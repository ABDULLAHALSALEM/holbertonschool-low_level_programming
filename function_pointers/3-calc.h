#ifndef _3_CALC_H_
#define _3_CALC_H_

/**
 * struct op - maps an operator string to its function
 * @op: the operator as a string ("+", "-", "*", "/", "%")
 * @f:  pointer to the function that performs the operation
 */
typedef struct op
{
	char *op;
	int (*f)(int a, int b);
} op_t;

int op_add(int a, int b);
int op_sub(int a, int b);
int op_mul(int a, int b);
int op_div(int a, int b);
int op_mod(int a, int b);

int (*get_op_func(char *s))(int, int);

#endif /* _3_CALC_H_ */
