#include "monty.h"

/**
 * run - f
 * @line: line
 * @st: stack
 * @cnt: counter
 * @f: file
 * Return: return
*/
int run(char *line, stack_t **st, unsigned int cnt, FILE *f)
{
	char *prc;
	int i = 0;
	instruction_t ops[] = {
			{"nop", mynop},
			{NULL, NULL}
			};

	prc = strtok(line, " \n\t");
	if (prc && prc[0] == '#')
		return (0);
	prc = strtok(NULL, " \n\t");
	while (ops[i].opcode && prc)
	{
		if (strcmp(prc, ops[i].opcode) == 0)
		{
			ops[0].f(st, cnt);
			return (0);
		}
		i++;
	}
	if (prc && ops[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", cnt, prc);
		fclose(f);
		free(line);
		free(*st);
		exit(EXIT_FAILURE);
	}
	return (1);
}
