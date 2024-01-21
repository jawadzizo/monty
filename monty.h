#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


#define BUFFSIZE 128


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
		char *opcode;
		void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct stack_meta_s - struct to store the needed global variables
 * @file: a file pointer to the fiven file (argv[1])
 * @head: a pointer to the first node in the linked list
 * @tail: a pointer to the last node in the linked list
 * @size: the size of the stack
 * @line: the line returned by getline
 * @line_number: the line number in the file
 * @mode: the mode of inserting new nodes (either stack or queue)
 * @value: the value of the new node to be pushed to the stack
 */
typedef struct stack_meta_s
{
	FILE *file;
	stack_t *head;
	stack_t *tail;
	unsigned int size;
	char *line;
	unsigned int line_number;
	int mode;
	int value;
} stack_meta_t;

extern stack_meta_t global;


void push(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void add_node(stack_t **head);
void add_node_end(stack_t **tail);

void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);

void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void divide(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);

void swap(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);

int check_choice(instruction_t *ptr);
int set_opcode(char **ptr);
int move_on(char *str);
int _isnum(char *str, int len);
void free_stack(void);

#endif

