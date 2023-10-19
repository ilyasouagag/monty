#include "monty.h"
/**
 * change - Call function based on the Opcode
 *
 * @current_line: As its name said :>
 * @s: Pointer to the head of the stack
 * Return: Integer
 */
int change(int current_line, stack_t **s)
{
	int i;

	instruction_t specific[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", m_div},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}};
	if (strcmp(tokens[0], "push") == 0 && tokens[1] == NULL)
	{

		fprintf(stderr, "L%d: unknown instruction %s\n", current_line, tokens[0]);
		exit(EXIT_FAILURE);
	}
	i = 0;

	while (specific[i].opcode)
	{
		if (strcmp(specific[i].opcode, tokens[0]) == 0)
		{
			specific[i].f(s, current_line);
			return (1);
		}
		i++;
	}
	return (0);
}
