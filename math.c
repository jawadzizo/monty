#include "monty.h"

/**
 * add - adds the top node's value to the second one, and pops the top node
 * @stack: the head pointer to the stack
 * @line_number: the line number in the file
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (global.size < 2)
	{
		fprintf(stderr, "L%i: can't add, stack too short\n", line_number);
		free_stack();
		exit(EXIT_FAILURE);
	}

	*stack = (*stack)->next;
	(*stack)->n += temp->n;

	free(temp);
	temp = NULL;

	global.size--;
}

/**
 * mul - multiplies the top node's value to by second one, and pops the top node
 * @stack: the head pointer to the stack
 * @line_number: the line number in the file
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (global.size < 2)
	{
		fprintf(stderr, "L%i: can't mul, stack too short\n", line_number);
		free_stack();
		exit(EXIT_FAILURE);
	}

	*stack = (*stack)->next;
	(*stack)->n *= temp->n;

	free(temp);
	temp = NULL;

	global.size--;
}

/**
 * divide - divides the top node's value to by second one, and pops the top node
 * @stack: the head pointer to the stack
 * @line_number: the line number in the file
 */
void divide(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (global.size < 2)
	{
		fprintf(stderr, "L%i: can't div, stack too short\n", line_number);
		free_stack();
		exit(EXIT_FAILURE);
	}

	if (temp->n == 0)
	{
		fprintf(stderr, "L%i: division by zero\n", line_number);
		free_stack();
		exit(EXIT_FAILURE);
	}

	*stack = (*stack)->next;
	(*stack)->n /= temp->n;

	free(temp);
	temp = NULL;

	global.size--;
}

/**
 * mod - mod the top node's value to by second one, and pops the top node
 * @stack: the head pointer to the stack
 * @line_number: the line number in the file
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (global.size < 2)
	{
		fprintf(stderr, "L%i: can't mod, stack too short\n", line_number);
		free_stack();
		exit(EXIT_FAILURE);
	}

	if (temp->n == 0)
	{
		fprintf(stderr, "L%i: division by zero\n", line_number);
		free_stack();
		exit(EXIT_FAILURE);
	}

	*stack = (*stack)->next;
	(*stack)->n %= temp->n;

	free(temp);
	temp = NULL;

	global.size--;
}

/**
 * sub - subtracts the top node's value to from second one, and pops the top node
 * @stack: the head pointer to the stack
 * @line_number: the line number in the file
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (global.size < 2)
	{
		fprintf(stderr, "L%i: can't sub, stack too short\n", line_number);
		free_stack();
		exit(EXIT_FAILURE);
	}

	*stack = (*stack)->next;
	(*stack)->n -= temp->n;

	free(temp);
	temp = NULL;

	global.size--;
}

