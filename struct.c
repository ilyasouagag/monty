#include "monty.h"

void change(char* s[],int* n)
{
	stack_t** t = NULL;
	unsigned int a = atoi(s[1]);
	int i;

	instruction_t specific[] = {
		{"push",push},
		{NULL, NULL}};
	if (strcmp(s[0], "push") == 0  && s[1] == NULL && 0) 
	{
	
		fprintf(stderr,"L%d: unknown instruction %s\n",*n,s[0]);
		exit(EXIT_FAILURE);
	}
	else if(s[1] !=NULL && strcmp(s[0],"push") != 0)
	{
		fprintf(stderr,"L%d: unknown instruction %s\n",*n,s[0]);
		exit(EXIT_FAILURE);
	}
	i = 0;

	while (specific[i].opcode)
	{
		if (strcmp(specific[i].opcode,s[0]) == 0)
				specific[i].f(t,a);
		i++;
	}
}
void push(stack_t**stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	printf("you got me!\n");
}