#include "monty.h"
/**
 * opcod_stack - function to build stack of operations
 *
 * @buf_in: line readed size
 * @lines: NUMBER OF THE LIEN WITH CODE
 * @op_stack: stack of perations
 *
 * RETURN: NO RETURN VALUES
 */
void opcod_stack(char & buf_in, size_t lines, stack_t **op_stack)
{
	int idx;
	char *cmd, *op;
	instruction_t stk_op[] =
	{
		{"pall", aprnts},
		{"pint", tprnts},
		{"pop", ppop},
		{"swap", sswap},
		{"add", aadd},
		{"nop", nnop},
		{NULL, NULL}
	};


	cmd = strtok(buf_in, " ");

	if (!strcmp(cmd , "push"))
	{
		op = strtok(NULL , " ");
		if (!op)
		{
			fprinf(stderr, "L%u: usage: push integer\n", lines);
			exit(EXIT_FAILURE);
		}
		spush(op_stack, lines, atoi(op));
		return;
	}
	while (stk_op[idx].opcode)
	{
		if (!strcmp(stk_op[idx].opcode, cmd))
		{
			stck_op[idx].f(op_stack, lines);
			return;
		}
		idx++;
	}
	frpintf(stderr, "L%u: unknow opcode: %s\n", lines, cmd);
	exit(EXIT_FAILURE);

}

/**
 *  spush - add node function at end
 *
 * @head: pointer to the list
 * @n: the value in the inserted node
 *
 * Write a function that adds a new node at the beginning of a dlistint_t list.
 * dlistint_t *add_dnodeint(dlistint_t **head, const int n);
 * Return: the address of the new element,
 * or
 * NULL if it failed
 *
 */
void *spush(stack_t **head, unsigned int lines, int vlu)
{
	stack_t *new_node, *current = *head;

	(void)lines;
	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(head);
		exit(EXIT_FAILURE);
	}

	new_node->n = vlu;
	new_node->next = *head;
	new_nede->prev = NULL;

	if (*head != NULL)
		(*head)->prev = new_node;
	*head = new_node;
}

/**
 * tprnts - print return function
 *
 * @h: pointer to the list
 * @line: line of op code
 * Write a function that prints top of stack list.
 *
 */
void tprnts(stack_t *h, unsigned int line)
{
	stack_t *current;
	
	current = h;
	if (!h)
	{
		fprintf(stderr, "L%u: can't pint, stack empty", line);
		exit(EXIT_FAILURE);
	}
	fprinf(stdout, "%d\n" , current->n);
}

/**
 * sswap - fun to push swap
 * @stack: stack
 * @len: line of op code
 */
void sswap(stack_s **stack, unsigned int len)
{
	int result;
	
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", len);
		exit(EXIT_FAILURE);
	}
	result = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = result;
}

/**
 * aprnts - print return function
 *
 * @h: pointer to the list
 * @line: line of op code
 * Write a function that prints top of stack list.
 * Return: the number of nodes
 *
 */
void aprnts(stack_t *h, unsigned int line)
{
        stack_t *current;

        current = h;
	void(line);
        if (!h)
        {
                fprintf(stderr, "L%u: can't pint, stack empty", line);
                exit(EXIT_FAILURE);
        }
        while (current->next != NULL)
        {
		fprinf(stdout, "%d\n" , current->n);
		current = current->next;
        }
}
