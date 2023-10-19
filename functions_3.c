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
