#include "monty.h"

/**
 * swap - swaps the top 2 nodes values
 * @stack: the head pointer to the stack
 * @line_number: the line number in the file
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (global.size < 2)
	{
		fprintf(stderr, "L%i: can't swap, stack too short\n", line_number);
		free_stack();
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

/**
 * rotl - rotates the top 2 nodes to the left
 * @stack: the head pointer to the stack
 * @line_number: the line number in the file
 */
void rotl(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *temp = *stack;

	if (global.size < 2)
		return;

	(*stack) = (*stack)->next;
	(*stack)->prev = NULL;

	temp->prev = global.tail;
	temp->next = NULL;

	global.tail->next = temp;
	global.tail = temp;
}

/**
 * rotr - rotates the top 2 nodes to the right
 * @stack: the head pointer to the stack
 * @line_number: the line number in the file
 */
void rotr(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *temp = global.tail;

	if (global.size < 2)
		return;

	global.tail = global.tail->prev;
	global.tail->next = NULL;

	temp->prev = NULL;
	temp->next = *stack;

	(*stack)->prev = temp;
	*stack = temp;
}

