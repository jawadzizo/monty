#include "monty.h"


/**
 * check_choice - checks for the appropriate function to call
 * @ptr: a pointer to set instructions for the function to use
 * Return: 0 if the function found, -1 to ignore the line, or exit failed
 */
int check_choice(instruction_t *ptr)
{
	int i;
	char *opcodes[] = {"push", "pall", "pint", "pop", "swap", "add",
	"sub", "div", "mul", "mod", "pchar", "pstr", "rotl", "rotr", NULL};

	void (*f[])(stack_t **stack, unsigned int) = {push, pall, pint, pop,
	swap, add, sub, divide, mul, mod, pchar, pstr, rotl, rotr};

	if (set_opcode(&(ptr->opcode)) == -1)
		return (-1);

	if (move_on(ptr->opcode) == -1)
		return (-1);

	for (i = 0; opcodes[i] != NULL; i++)
	{
		if ((strlen(ptr->opcode) == strlen(opcodes[i])) && strcmp(ptr->opcode, opcodes[i]) == 0)
		{
			ptr->f = f[i];
			return (0);
		}
	}

	fprintf(stderr, "L%i: unknown instruction %s\n", global.line_number, ptr->opcode);
	free_stack();
	exit(EXIT_FAILURE);

	return (0);
}

/**
 * move_on - checks if the returned opcode is worth to get processed
 * @str: the opcode to check
 * Return: 0 to process the opcode, or -1 to ignore it
 */
int move_on(char *str)
{
	if (str == NULL)
		return (-1);

	if (str[0] == '#')
		return (-1);

	if ((strlen(str) == strlen("nop")) && strcmp(str, "nop") == 0)
		return (-1);

	if ((strlen(str) == strlen("stack")) && strcmp(str, "stack") == 0)
	{
		global.mode = 0;
		return (-1);
	}

	if ((strlen(str) == strlen("queue")) && strcmp(str, "queue") == 0)
	{
		global.mode = 1;
		return (-1);
	}

	return (0);
}

/**
 * set_opcode - sets the opcode from the file line
 * @ptr: pointer to the opcode
 * Return: 0 if the opcode is found in the file, or -1 if the line is empty
 */
int set_opcode(char **ptr)
{
	char *str = global.line;
	char *token;
	char *delimiters = "\t ";
	char *value;

	token = strtok(str, delimiters);

	if (token == NULL)
		return (-1);

	if (strcmp(token, "") != 0)
		*ptr = token;

	if (strlen(*ptr) == strlen("push") && strcmp(*ptr, "push") == 0)
	{
		value = strtok(NULL, delimiters);

		if (value == NULL || _isnum(value, strlen(value)) == -1)
		{
			fprintf(stderr, "L%i: usage: push integer\n", global.line_number);
			free_stack();
			exit(EXIT_FAILURE);
		}

		global.value = atoi(value);
	}

	return (0);
}

/**
 * _isnum - checks if the given string has only digits
 * @str: the string to check
 * @len: the length of the string
 * Return: 0 if the string only contains digits, or -1 otherwise
 */
int _isnum(char *str, int len)
{
	int i;

	for (i = 0; i < len; i++)
	{
		if (str[i] > '9' || str[i] < '0')
			return (-1);
	}

	return (0);
}

/**
 * free_stack - frees the allocated memory for the linked list of stack
 */
void free_stack(void)
{
	stack_t *temp;

	while (global.head != NULL)
	{
		temp = global.head;
		global.head = global.head->next;
		free(temp);
	}

	temp = NULL;
	global.head = NULL;

	free(global.line);
	global.line = NULL;

	fclose(global.file);
	global.file = NULL;
}

