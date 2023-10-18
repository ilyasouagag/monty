#include "monty.h"
char** tokens = NULL;
/**
 * main - The point were everything bigen
 *
 * @ac: Arguments counter
 * @av: arguments vectory
 * Return: 0
 */
int main(int ac, char **av)
{
	stack_t* stack = NULL;
	char* line = NULL;
	size_t len =0;
	int read;
	int curr_line = 0;
	FILE *file = fopen(av[1],"r");
	(void)ac;
	if (!file)
	{
		fprintf(stderr,"Error: Can't open file %s\n",av[1]);
		exit(EXIT_FAILURE);
	}
	 tokens = (char**)malloc(3 * sizeof(char*));

    if (tokens == NULL)
    {
        fprintf(stderr, "Error: Memory allocation for tokens failed\n");
        exit(EXIT_FAILURE);
    }
	while((read = _getline(&line,&len,file) != -1))
	{
		curr_line ++;
		tokens[0] = strtok(line," \n\t");
		tokens[1] = strtok(NULL," \n\t");
		tokens[2] = strtok(NULL," \n\t");
		if(!change(curr_line,&stack))
		{
			/*handle line filled with space*/
			fprintf(stderr,"L%d: unknown instruction %s\n",curr_line,tokens[0]);
			exit(EXIT_FAILURE);
		}

	}
	free(tokens);
	fclose(file);
	return (0);
}

