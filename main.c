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

		if (strncmp(tokens[0], "#", 1) == 0)
		{
			continue;
		}
		check_args(line, file, curr_line, stack);
		check_args2(line, file, curr_line, stack);
		check_args3(line, file, curr_line, stack);
		if (!change(curr_line, &stack))
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", curr_line, tokens[0]);
			free_before_exit(file, line, tokens, stack);
			exit(EXIT_FAILURE);
		}
	}
	free_before_exit(file, line, tokens, stack);
}
