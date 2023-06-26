#ifndef HEADER_H
#define HEADER_H


#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

/* #include <stderr.h> */


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

/* FUNCTIONS */

void opcod_stack(char *buf_in, size_t lines, stack_t **op_stack);
void *spush(stack_t **head, unsigned int lines, int vlu);
void tprnts(stack_t **h, unsigned int line);
void sswap(stack_t **stack, unsigned int len);
void aprnts(stack_t **h, unsigned int line);


void ppop(stack_t **stack, unsigned int len);
void aadd(stack_t **stack, unsigned int len);
void nnop(stack_t **stack, unsigned int len);


size_t stck_len(const stack_t *h);
stack_t *get_node_at_index(stack_t *head, unsigned int index);
void free_stck(stack_t *head);
stack_t *qpush(stack_t **head, const int n);



/*
 * Compilation & Output
 * Your code will be compiled this way:
 * $ gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
 */

#endif
