#include "monty.h"
/**
 * check_args - Check the validity of arguments and stack conditions.
 * @line: The line from the input file.
 * @file: The file pointer to the input file.
 * @curr_line: The current line number in the script.
 * @stack: A pointer to the stack.
 */
void check_args(char *line, FILE *file, int curr_line, stack_t *stack)
{
	if (strcmp(tokens[0], "push") == 0)
	{
		if (!check_digit(tokens[1]) || !tokens[1])
		{
			fflush(stdout);
			fprintf(stderr, "L%d: usage: push integer\n", curr_line);
			free_before_exit(file, line, tokens, stack);
			exit(EXIT_FAILURE);
		}
	}
	if (strcmp(tokens[0], "pint") == 0 && stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", curr_line);
		free_before_exit(file, line, tokens, stack);
		exit(EXIT_FAILURE);
	}
	if (strcmp(tokens[0], "pop") == 0 && stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", curr_line);
		free_before_exit(file, line, tokens, stack);
		exit(EXIT_FAILURE);
	}
	if (strcmp(tokens[0], "swap") == 0 && (stack == NULL || stack->next == NULL))
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", curr_line);
		free_before_exit(file, line, tokens, stack);
		exit(EXIT_FAILURE);
	}
	if (strcmp(tokens[0], "add") == 0 && (stack == NULL || stack->next == NULL))
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", curr_line);
		free_before_exit(file, line, tokens, stack);
		exit(EXIT_FAILURE);
	}
}
/**
 * check_args2 - Check the validity of arguments and stack conditions.
 * @line: The line from the input file.
 * @file: The file pointer to the input file.
 * @curr_line: The current line number in the script.
 * @stack: A pointer to the stack.
 */
void check_args2(char *line, FILE *file, int curr_line, stack_t *stack)
{
	if (strcmp(tokens[0], "div") == 0 && (stack == NULL || stack->next == NULL))
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", curr_line);
		free_before_exit(file, line, tokens, stack);
		exit(EXIT_FAILURE);
	}
	if (strcmp(tokens[0], "div") == 0 && stack->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", curr_line);
		free_before_exit(file, line, tokens, stack);
		exit(EXIT_FAILURE);
	}
	if (strcmp(tokens[0], "mul") == 0 && (stack == NULL || stack->next == NULL))
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", curr_line);
		free_before_exit(file, line, tokens, stack);
		exit(EXIT_FAILURE);
	}
	if (strcmp(tokens[0], "mod") == 0 && (stack == NULL || stack->next == NULL))
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", curr_line);
		free_before_exit(file, line, tokens, stack);
		exit(EXIT_FAILURE);
	}
	if (strcmp(tokens[0], "mod") == 0 && stack->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", curr_line);
		free_before_exit(file, line, tokens, stack);
	}
	if (strcmp(tokens[0], "sub") == 0 && (stack == NULL || stack->next == NULL))
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", curr_line);
		free_before_exit(file, line, tokens, stack);
		exit(EXIT_FAILURE);
	}
}
