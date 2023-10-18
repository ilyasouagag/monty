#include "monty.h"

int change(int n,stack_t**t)
{
	int i;
	
	instruction_t specific[] = {
		{"push",push},
		{"pall",pall},
		{"pint",pint},
		{NULL, NULL}};
	if (strcmp(tokens[0], "push") == 0  && tokens[1] == NULL) 
	{
	
		fprintf(stderr,"L%d: unknown instruction %s\n",n,tokens[0]);
		exit(EXIT_FAILURE);
	}
	i = 0;

	while (specific[i].opcode)
	{
		if (strcmp(specific[i].opcode,tokens[0]) == 0)
		{
			specific[i].f(t,n);
			return(1);
		}
		i++;
	}
	return (0); 
}
