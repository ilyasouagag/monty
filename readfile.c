#include "header.h"
/**
 * main - The point were everything bigen
 *
 * @ac: Arguments counter
 * @av: arguments vectory
 * Return: 0
 */
int main(int ac, char **av)
{
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
	char *token[2];
	FILE *file = fopen(file_name, "r");
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	if (file == NULL) 
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}


	while ((read = getline(&line, &len, file)) != -1)
	{
		line_tok(line, token);
	}
	free(line);
	fclose(file);
}
