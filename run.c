#include "monty.h"

/**
 * run - f
 * @line: line
 * Return: return
*/
int run(char *line)
{
	stack_t **st = NULL;
	int cnt = 0;
	char *op, *args;
	instruction_t ops[] = {
			{"nop", mynop},
			{NULL, NULL}
			};

	op = strtok(line, " \n\t");
	if (op && op[0] == '#')
		return (0);
	args = strtok(NULL, " \n\t");
	ops[0].f(st, cnt);
	return (0);
}
