#include "monty.h"


stack_meta_t global = {NULL, NULL, NULL, 0, NULL, 0, 0, 0};


/**
 * main - the starting point of the program
 * @argc: arguments count
 * @argv: arguments content
 * Return: 0 if succeeded, or 1 if failed
 */
int main(int argc, char *argv[])
{
	ssize_t characters;
	size_t buffsize = BUFFSIZE;
	instruction_t instruction;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	global.file = fopen(argv[1], "r");
	if (global.file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	global.line = malloc(sizeof(char) * BUFFSIZE);
	if (global.line == NULL)
		exit(EXIT_FAILURE);

	while ((characters = getline(&global.line, &buffsize, global.file)) != -1)
	{
		if (global.line[characters - 1] == '\n')
			global.line[characters - 1] = '\0';

		global.line_number++;

		if (check_choice(&instruction) == -1)
			continue;

		instruction.f(&global.head, global.line_number);
	}

	free_stack();

	return (0);
}

