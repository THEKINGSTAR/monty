#include "monty.h"

/**
 * stck_len - return lenght function
 *
 * @h: pointer to the list
 * Write a function that returns
 * the number of elements in a linked dlistint_t list.
 * Return: the number of nodes
 *
 */

size_t stck_len(const stack_t *h)
{
	const stack_t *current;
	size_t lenght = 0;

	current = h;
	while (current != NULL)
	{
		lenght++;
		current = current->next;
	}
	return (lenght);
}

/**
 * get_node_at_index - get node at index function
 *
 * @head: head of the list
 * @index: index to get the node at
 *
 * where index is the index of the node, starting from 0
 *
 * Return:nth node.
 * if the node does not exist, return NULL
 *
 */
stack_t *get_node_at_index(stack_t *head, unsigned int index)
{
	stack_t *current;
	unsigned int lenght = 0;

	current = head;
	if (index == 0)
		return (current);
	while (current != NULL)
	{
		current = current->next;
		lenght++;
	}
	if ((index > lenght) || (!index))
		return (NULL);
	current = head;
	while (index)
	{
		current = current->next;
		index--;
	}
	return (current);
}

/**
 * free_stck - free node functions
 *
 * @head: pointer to the list
 * Write a function that frees a dlistint_t list.
 * Prototype: void free_dlistint(dlistint_t *head);
 * Return: function has no return value
 *
 */
void free_stck(stack_t *head)
{
	stack_t *current, *prev_n;

	prev_n = NULL;
	current = head;

	while (current != NULL)
	{
		prev_n = current;
		current = current->next;
		prev_n->next = current;
		prev_n->prev = NULL;
		free(prev_n);
	}
	free(current);
}

/**
 *  qpush - add node function
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
stack_t *qpush(stack_t **head, const int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
		return (NULL);
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *head;

	if (*head != NULL)
	{
		(*head)->prev = new_node;
	}
	*head = new_node;
	return (new_node);
}
