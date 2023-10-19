#include "monty.h"
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
/**
 * check_digit - Checks if string contains digits
 *
 * @string: String
 * Return: 1 if stinng is digit, and 0 else
 */
int check_digit(char *string)
{
	int i;

	if (string == NULL)
		return (0);

	for (i = 0; string[i] != '\0'; i++)
	{
		if (string[i] == '-' && i == 0)
			continue;
		if (!(string[i] >= '0' && string[i] <= '9'))
			return (0);
	}

	return (1);
}
/**
 * free_stack - free DLL
 *
 * @stack: head of th DLL
 * Return: Nothing
 */
void free_stack(stack_t *stack)
{
	stack_t *curr = stack;
	stack_t *tmp = NULL;

	while (curr != NULL)
	{
		tmp = curr;
		curr = curr->next;
		free(tmp);
	}
}
