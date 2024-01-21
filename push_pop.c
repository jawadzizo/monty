#include "monty.h"


/**
 * add_node - adds a node to the beginning of the stack
 * @head: the head pointer to the first node in the stack
 */
void add_node(stack_t **head)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		free_stack();
		exit(EXIT_FAILURE);
	}

	new->n = global.value;
	new->next = *head;
	new->prev = NULL;

	if (*head != NULL)
		(*head)->prev = new;

	else
		global.tail = new;

	*head = new;
}

/**
 * add_node_end - adds a node to the end of the stack
 * @tail: the tail pointer to the last node in the stack
 */
void add_node_end(stack_t **tail)
{
	stack_t *new;

	if (*tail == NULL)
	{
		add_node(&global.head);
		return;
	}

	new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		free_stack();
		exit(EXIT_FAILURE);
	}

	new->n = global.value;
	new->next = NULL;
	new->prev = *tail;

	(*tail)->next = new;
	*tail = new;
}

/**
 * push - pushes a new node to the stack
 * @stack: a pointer to either the first or last node in the stack
 * @line_number: the line number in the file
 */
void push(stack_t **stack __attribute__((unused)),
			unsigned int line_number __attribute__((unused)))
{
	if (global.mode == 0)
		add_node(&global.head);

	else
		add_node_end(&global.tail);

	global.size++;
}

/**
 * pop - pops the top node in the stack
 * @stack: the head pointer to first node
 * @line_number: the line number in the file
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (global.size == 0)
	{
		fprintf(stderr, "L%i: can't pop an empty stack\n", line_number);
		free_stack();
		exit(EXIT_FAILURE);
	}

	*stack = (*stack)->next;
	free(temp);
	temp = NULL;

	if (global.size == 1)
		global.tail = NULL;

	global.size--;
}

