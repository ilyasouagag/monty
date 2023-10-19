#include "monty.h"
/**
 * mod - Calculate the modulo of the top two elements of the stack.
 * @stack: A pointer to the stack.
 * @line_number: The line number in the script (unused here).
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *top1 = *stack;
	stack_t *top2 = (*stack)->next;
	(void)line_number;

	top2->n %= top1->n;

	*stack = top2;
	if (top1->next != NULL)
	{
		top1->next->prev = NULL;
	}
	free(top1);
}
/**
 * pchar - Print the character representation of the top element on the stack.
 * @stack: A pointer to the stack.
 * @line_number: The line number in the script.
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	int value = (*stack)->n;
	(void)line_number;

	printf("%c\n", (char)value);
}
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;
	(void)line_number;

	while (top != NULL)
	{
		if (top->n == 0 || top->n < 0 || top->n > 127)
		{
			break;
		}
		printf("%c", (char)top->n);
		top = top->next;
	}
	printf("\n");
}
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;
	stack_t *current = *stack;
	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return;
	(*stack) = (*stack)->next;
	(*stack)->prev = NULL;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = top;
	top->prev = current;
	top->next = NULL;
}
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;
	stack_t *current = *stack;
	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->prev->next = NULL;
	current->prev = NULL;
	top->prev = current;
	current->next = top;
	(*stack) = current;
}
