#include "monty.h"


/**
 * pall - prints all values in the stack starting from the top
 * @stack: the head pointer to first node
 * @line_number: the line number in the file
 */
void pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *ptr = *stack;

	while (ptr != NULL)
	{
		printf("%i\n", ptr->n);
		ptr = ptr->next;
	}
}

/**
 * pint - prints value of the top node
 * @stack: the head pointer to first node
 * @line_number: the line number in the file
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (global.size == 0)
	{
		fprintf(stderr, "L%i: can't pint, stack empty\n", line_number);
		free_stack();
		exit(EXIT_FAILURE);
	}

	printf("%i\n", (*stack)->n);
}

/**
 * pchar - prints value of the top node as a character
 * @stack: the head pointer to first node
 * @line_number: the line number in the file
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (global.size == 0)
	{
		fprintf(stderr, "L%i: can't pchar, stack empty\n", line_number);
		free_stack();
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%i: can't pchar, value out of range\n", line_number);
		free_stack();
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*stack)->n);
}

/**
 * pstr - prints te value of nodes as a string, starting from top
 * @stack: the head pointer to first node
 * @line_number: the line number in the file
 */
void pstr(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *temp = *stack;

	while ((temp != NULL) && (temp->n > 0) && (temp->n <= 127))
	{
		putchar(temp->n);
		temp = temp->next;
	}

	putchar('\n');
}

