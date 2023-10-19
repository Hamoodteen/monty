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
			{"push", mypush},
			{"pall", mypall},
			{"pint", mypint},
			{"pop", mypop},
			{"swap", myswap},
			{"add", myadd},
			{"nop", mynop},
			{"sub", mysub},
			{"div", mydiv},
			{"mul", mymul},
			{"mod", mymod},
			{"pchar", mypchar},
			{"pstr", mypstr},
			{"rotl", myrotl},
			{"rotr", myrotr},
			{"queue", myqueue},
			{"stack", mystack},
			{NULL, NULL}
			};
	ops[6].f(st, cnt);
	return (0);
}
void mynop(stack_t **st, unsigned int cnt)
{
	(void)st;
	(void)cnt;
}
