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
	int value;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	value = (*stack)->n;

	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (char)value);
}
