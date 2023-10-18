#include "monty.h"
/**
 * main - The point were everything bigen
 *
 * @ac: Arguments counter
 * @av: arguments vectory
 * Return: 0
 */
int main(int ac, char **av)
{
	(void)av;
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}	
	get_line("do.m");
	return 0;
}

char **line_tok(char *line, char **token)
{

	token[0] = strtok(line, " \n");
	token[1] = strtok(NULL, " \n");
	token[2] = strtok(NULL, " \n");
	return (token);
}

void get_line(char *file_name)
{
	char *token[3];
	char** str;
	FILE *file = fopen(file_name, "r");
	char *line;
	int read;
	int curr_line = 1;

	line = malloc(100);
	if (file == NULL) 
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}


	while ((read = _getline(file, line)))
	{
		str = line_tok(line, token);
		change(str, &curr_line);
		curr_line++;
	}
	free(line);
	fclose(file);
}
