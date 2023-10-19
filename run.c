#include "monty.h"

/**
 * run - f
 * Return: return
*/
int run(void)
{
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
	(void)ops;
	return (0);
}
