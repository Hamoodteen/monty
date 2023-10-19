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
	int read = 1;
	int l_n = 0;

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
		read = getline(&line, (size_t *)8192, f);
		l_n++;
		free(line);
	}
	(void)read;
	fclose(f);
	return (0);
}
