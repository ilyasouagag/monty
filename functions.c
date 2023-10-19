#include "monty.h"
/**
 * push - Insert an new element to the head of stack
 *
 * @stack: Pointer to the head of DLL
 * @line_number: The currnet line number
 * Return: Nothing
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *top;

	if (!check_digit(tokens[1]) || !tokens[1])
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free(tokens);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	top = malloc(sizeof(stack_t));
	if (top == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(tokens);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	top->prev = NULL;
	top->n = atoi(tokens[1]);
	top->next = NULL;
	if (*stack == NULL)
	{
		(*stack) = top;
	}
	else
	{
		top->next = (*stack);
		(*stack)->prev = top;
		(*stack) = top;
	}
}

/**
 * pall - Print that data of stack
 *
 * @stack: Pointer to the head of the stack
 * @line_number: THe currnet line number
 * Return: Nothing
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number;
	for (; current != NULL; current = current->next)
	{
		printf("%d\n", current->n);
	}
}

/**
 * pint - Print that data of stack
 *
 * @stack: Pointer to the head of the stack
 * @line_number: THe currnet line number
 * Return: Nothing
 */
void pint(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty", line_number);
		free(tokens);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
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
