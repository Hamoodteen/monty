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
	stack_t *st = NULL;
	char *line = NULL;
	int rtn = 1, cnt = 0;

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
	while (rtn > 0)
	{
		_getline(&line, (size_t *)8192, f);
		cnt++;
		if (rtn > 0)
			rtn = run(line, &st, cnt, f);
		free(line);
	}
	free_st(st);
	fclose(f);
	return (0);
}
