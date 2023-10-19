#include "monty.h"

/**
 * run - f
 * Return: return
*/
int run(void)
{
	stack_t **st = NULL;
	int cnt = 0;
	instruction_t ops[] = {
			{"nop", mynop},
			{NULL, NULL}
			};
	ops[0].f(st, cnt);
	return (0);
}
void mynop(stack_t **st, unsigned int cnt)
{
	(void)st;
	(void)cnt;
}
