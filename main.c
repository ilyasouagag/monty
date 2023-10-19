#include "monty.h"
char **tokens;
/**
 * main - The point were everything bigen
 *
 * @ac: Arguments counter
 * @av: arguments vectory
 * Return: 0
 */
int main(int ac, char **av)
{
	char *line = NULL;
	FILE *file;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(av[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	tokens = (char **)malloc(3 * sizeof(char *));
	if (tokens == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	loop_into_lines(line, file);
	return (0);
}

/**
 * loop_into_lines - loop through lines of a file
 *
 * @line: The buffer that will contains a line charachters (sting)
 * @file: Pointer to a file descriptive
 * Return: Nothing
 */
void loop_into_lines(char *line, FILE *file)
{
	int read, curr_line = 0;
	stack_t *stack = NULL;
	size_t len;

	while ((read = getline(&line, &len, file) != -1))
	{
		if (!check_empty(line))
			continue;
		curr_line++;

		tokens[0] = strtok(line, " \n\t");
		tokens[1] = strtok(NULL, " \n\t");
		tokens[2] = strtok(NULL, " \n\t");
		if (!change(curr_line, &stack))
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", curr_line, tokens[0]);
			free_before_exit(file, line, tokens, stack);
			exit(EXIT_FAILURE);
		}
	}
	free_before_exit(file, line, tokens, stack);
}
/**
 * free_before_exit - Free the allocated memory in heap
 *
 * @file: file discriptive
 * @token: Array of stings
 * @stack: Header of the stack
 * @line: Buffer contains line chracters
 * Return: Nothing
 */
void free_before_exit(FILE *file, char *line, char **token, stack_t *stack)
{
	free(line);
	free(token);
	free_stack(stack);
	fclose(file);
}
/**
 * check_empty - checks the case of emptyline
 *
 * @arg: THe currnet line
 * Return: 0 if it is empty and 1 if everything gose ok!
 */
int check_empty(char *arg)
{
	size_t longueur;
	int alert = 0, j;

	longueur = strlen(arg);
	if (longueur > 0 && arg[longueur - 1] == '\n')
	{
		arg[longueur - 1] = '\0';
	}
	alert = 0;
	for (j = 0; arg[j] != '\0'; j++)
	{
		if (arg[j] != ' ')
		{
			alert = 1;
			break;
		}
	}
	return (alert);
}
