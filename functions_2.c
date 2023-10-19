#include "monty.h"
/**
 * add - Add the top two elements of the stack.
 * @stack: A pointer to the stack.
 * @line_number: The line number in the script (unused here).
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *top1 = *stack;
	stack_t *top2 = (*stack)->next;
	(void)line_number;

	top2->n += top1->n;

	*stack = top2;
	if (top1->next != NULL)
		top1->next->prev = NULL;
	free(top1);
}
/**
 * nop - Do nothing (placeholder).
 * @stack: A pointer to the stack (unused here).
 * @line_number: The line number in the script (unused here).
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
/**
 * sub - Subtract the top two elements of the stack.
 * @stack: A pointer to the stack.
 * @line_number: The line number in the script (unused here).
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *top1 = *stack;
	stack_t *top2 = (*stack)->next;
	(void)line_number;

	top2->n -= top1->n;

	*stack = top2;
	if (top1->next != NULL)
		top1->next->prev = NULL;
	free(top1);
}
/**
 * m_div - Divide the top two elements of the stack.
 * @stack: A pointer to the stack.
 * @line_number: The line number in the script (unused here).
 */
void m_div(stack_t **stack, unsigned int line_number)
{
	stack_t *top1 = *stack;
	stack_t *top2 = (*stack)->next;
	(void)line_number;

	top2->n /= top1->n;

	*stack = top2;
	if (top1->next != NULL)
		top1->next->prev = NULL;
	free(top1);
}
/**
 * mul - Multiply the top two elements of the stack.
 * @stack: A pointer to the stack.
 * @line_number: The line number in the script (unused here).
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *top1 = *stack;
	stack_t *top2 = (*stack)->next;
	(void)line_number;

	top2->n *= top1->n;

	*stack = top2;
	if (top1->next != NULL)
		top1->next->prev = NULL;
	free(top1);
}
