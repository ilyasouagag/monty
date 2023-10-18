#include "monty.h"
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *top;

	if (!check_digit(tokens[1]) || !tokens[1])
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	top = malloc(sizeof(stack_t));
	if (top == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
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
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number;
	for (; current != NULL; current = current->next)
	{
		printf("%d\n", current->n);
	}
}
void pint(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	if((*stack) == NULL)
	{
		fprintf(stderr,"L%d: can't pint, stack empty",line_number);
		free(tokens);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
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