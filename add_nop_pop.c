#include "monty.h"

/**
 * ppop - fun to pop
 * @stack: stack
 * @len: line
 */
void ppop(stack_t **stack, unsigned int len)
{
        stack_t *st;

        st = *stack;
        if (!(*stack))
        {
                fprintf(stderr, "L%u: can't pop an empty stack\n", len);
                free(stack);
                exit(EXIT_FAILURE);
        }
        fprintf(stdout, "%d\n", (*stack)->n);
        *stack = (*stack)->next;
        free(st);
}
/**
 * aadd - fun to push add
 * @stack: stack
 * @len: line
 */
void aadd(stack_t **stack, unsigned int len)
{
        int result;
        stack_t *st;

        st = *stack;

        if (!st || !st->next)
        {
                fprintf(stderr, "L%u: can't add, stack too short\n", len);
                exit(EXIT_FAILURE);
        }

        result = (*stack)->n;
        (*stack) = (*stack)->next;
        result += (*stack)->n;
        free(st);
}

/**
 * nnop - fun to push add
 * @stack: stack
 * @len: line
 */
void nnop(stack_t **stack, unsigned int len)
{
        (void)stack;
        (void)len;
}
