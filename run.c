#include "monty.h"

/**
 * _getline - f
 * @lineptr: char
 * @n: int
 * @stream: file
 * Return: int
*/
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	char *newline, *line = NULL;
	ssize_t bufsize = 8192, nchars = 0;
	int c;

	if ((lineptr == NULL) || (n == NULL) || (stream == NULL))
		return (-1);
	if ((*lineptr == NULL) || (*n == 0))
	{
		line = (char *)malloc(bufsize);
		if (line == NULL)
			return (-1);
		*n = bufsize; }
	else
	{
		bufsize = *n;
		line = *lineptr; }
	while (1)
	{
		c = fgetc(stream);
		if ((c == EOF) || (c == '\n'))
		{
			line[nchars] = '\0';
			break; }
		if (nchars >= (bufsize - 1))
		{
			bufsize *= 2;
			newline = (char *)_realloc(line, sizeof(line), bufsize);
			if (newline == NULL)
			{
				free(line);
				return (-1); }
			line = newline;
		}
		line[nchars++] = (char)c; }
	*lineptr = line;
	*n = bufsize;
	if ((nchars == 0) && (c == EOF))
		return (-1);
	return (nchars); }

/**
 * *_realloc - f
 * @ptr: pointer
 * @old_size: int
 * @new_size: int
 * Return: pointer
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *ptr1;
	char *old_ptr;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);
	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}
	if (!ptr)
		return (malloc(new_size));
	ptr1 = malloc(new_size);
	if (!ptr1)
		return (NULL);
	old_ptr = ptr;
	if (new_size < old_size)
	{
		for (i = 0; i < new_size; i++)
			ptr1[i] = old_ptr[i];
	}
	if (new_size > old_size)
	{
		for (i = 0; i < old_size; i++)
			ptr1[i] = old_ptr[i];
	}
	free(ptr);
	return (ptr1);
}

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
	char *prc, *args;
	int i = 0;
	instruction_t ops[] = {
			{"nop", mynop},
			{NULL, NULL}
			};

	prc = strtok(line, " \n\t");
	if (prc && prc[0] == '#')
		return (0);
	args = strtok(NULL, " \n\t");
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
		free_st(*st);
		exit(EXIT_FAILURE);
	}
	(void)args;
	return (1);
}

/**
  * free_st - f
  * @head: head
  * Return: void
  */
void free_st(stack_t *head)
{
	if (head == NULL)
		return;
	free_st(head->next);
	free(head);
}
