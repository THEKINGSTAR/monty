#include "monty.h"



/**
 * print_dlistint - print return function
 *
 * @h: pointer to the list
 * Write a function that prints all the elements of a dlistint_t list.
 * Prototype: size_t print_dlistint(const dlistint_t *h);
 * Return: the number of nodes
 *
 */
size_t print_dlistint(const stack_t *h)
{
        const stack_t *current;
        size_t lenght = 0;

        current = h;
        while (current != NULL)
        {
                lenght++;
                printf("%d\n", current->n);
                current = current->next;
        }
        return (lenght);
}


/**
 * dlistint_len - return lenght function
 *
 * @h: pointer to the list
 * Write a function that returns
 * the number of elements in a linked dlistint_t list.
 * Return: the number of nodes
 *
 */

size_t dlistint_len(const stack_t *h)
{
        const dlistint_t *current;
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
 *  add_dnodeint - add node function
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
stack_t *add_dnodeint(stack_t **head, const int n)
{
        stack_t *new_node;

        new_node = malloc(sizeof(dlistint_t));
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



/**
 *  add_dnodeint_end - add node function at end
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
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
        stack_t *new_node, *current = *head;

        new_node = malloc(sizeof(dlistint_t));
        if (new_node == NULL)
                return (NULL);

        new_node->n = n;
        new_node->next = NULL;

        if (*head == NULL)
        {
                new_node->prev = NULL;
                *head = new_node;
                return (new_node);
        }

        while (current->next != NULL)
        {
                current = current->next;
        }
        current->next = new_node;
        new_node->prev = current;

        return (new_node);
}


/**
 * free_dlistint - free node functions
 *
 * @head: pointer to the list
 * Write a function that frees a dlistint_t list.
 * Prototype: void free_dlistint(dlistint_t *head);
 * Return: function has no return value
 *
 */
void free_dlistint(stack_t *head)
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
 * get_dnodeint_at_index - get node at index function
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
stack_t *get_dnodeint_at_index(stack_t *head, unsigned int index)
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
