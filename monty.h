#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
		int n;
		struct stack_s *prev;
		struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
		char *opcode;
		void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

int run(void);
void mypush(stack_t **stack, unsigned int line_number);
void mypall(stack_t **stack, unsigned int line_number);
void mypint(stack_t **stack, unsigned int line_number);
void mypop(stack_t **stack, unsigned int line_number);
void myswap(stack_t **stack, unsigned int line_number);
void myadd(stack_t **stack, unsigned int line_number);
void mynop(stack_t **stack, unsigned int line_number);
void mysub(stack_t **stack, unsigned int line_number);
void mydiv(stack_t **stack, unsigned int line_number);
void mymul(stack_t **stack, unsigned int line_number);
void mymod(stack_t **stack, unsigned int line_number);
void mypchar(stack_t **stack, unsigned int line_number);
void mypstr(stack_t **stack, unsigned int line_number);
void myrotl(stack_t **stack, unsigned int line_number);
void myrotr(stack_t **stack, unsigned int line_number);
void myqueue(stack_t **stack, unsigned int line_number);
void mystack(stack_t **stack, unsigned int line_number);

#endif
