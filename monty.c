#include "monty.h"

/**
 * main - f
 * @argc: argc
 * @argv: argv
 * Return: 0 or 1
*/
int main(int argc, char *argv[])
{
	FILE *f;
	char *line = NULL;
	int l_n = 0;
	int rtn = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	f = fopen(argv[1], "r");
	if (!f)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		while (fgets(line, 8192, f) != NULL)
		{
			rtn = run();
		}
		l_n++;
		free(line);
	}
	fclose(f);
	return (rtn);
}
