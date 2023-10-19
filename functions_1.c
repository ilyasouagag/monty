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

	(void)line_number;

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
	printf("%d\n", (*stack)->n);
}
/**
 * pop - Remove the top element from the stack.
 * @stack: A pointer to the stack.
 * @line_number: The line number in the script (unused here).
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;
	(void)line_number;

	*stack = top->next;

	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}

	free(top);
}
/**
 * swap - Swap the top two elements of the stack.
 * @stack: A pointer to the stack.
 * @line_number: The line number in the script (unused here).
 */
void swap(stack_t **stack, unsigned int line_number)
{

	stack_t *top1 = *stack;
	stack_t *top2 = (*stack)->next;
	(void)line_number;

	top1->prev = top2;
	top1->next = top2->next;
	top2->prev = NULL;
	top2->next = top1;

	*stack = top2;
}
