#include "monty.h"

/**
 * ppop - fun to pop top stack
 * @stack: stack of inputs
 * @len: line of op code
 */
void ppop(stack_t **stack, unsigned int len)
{
	stack_t *stk;

	stk = *stack;
	if (!(*stack))
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", len);
		free(stack);
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%d\n", (*stack)->n);
	*stack = (*stack)->next;
	free(stk);
}
/**
 * aadd - fun to push add
 * @stack: stack of inputs
 * @len: line  of opcode
 */
void aadd(stack_t **stack, unsigned int len)
{
	int result;
	stack_t *stk;

	stk = *stack;
	if (!stk || !stk->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", len);
		exit(EXIT_FAILURE);
	}

	result = (*stack)->n;
	(*stack) = (*stack)->next;
	result += (*stack)->n;
	free(stk);
}

/**
 * nnop - fun to do nothing
 * @stack: stack of inputs
 * @len: line of instructure
 */
void nnop(stack_t **stack, unsigned int len)
{
	(void)stack;
	(void)len;
}
