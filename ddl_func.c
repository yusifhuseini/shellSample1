#include "monty.h"

/**
 * add_dnodeint_end - Add a node at the end of the doubly linked list.
 * @head: Pointer to the head of the linked list.
 * @n: Data to store in the new node.
 * Return: A pointer to the newly added node, or NULL on failure.
 */
stack_t *add_dnodeint(stack_t **head, const int n, int at_end)
{
    stack_t *new_node;

    if (head == NULL)
        return NULL;

    new_node = malloc(sizeof(stack_t));

    if (!new_node)
    {
        dprintf(2, "Error: malloc failed\n");
        free_vglo();
        exit(EXIT_FAILURE);
    }

    new_node->n = n;
    new_node->prev = NULL;
    new_node->next = NULL;

    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        if (at_end)
        {
            stack_t *current = *head;
            while (current->next)
                current = current->next;

            current->next = new_node;
            new_node->prev = current;
        }
        else
        {
            new_node->next = *head;
            (*head)->prev = new_node;
            *head = new_node;
        }
    }

    return new_node;
}

/**
 * add_dnodeint_end - Add a node at the end of the doubly linked list.
 * @head: Pointer to the head of the linked list.
 * @n: Data to store in the new node.
 * Return: A pointer to the newly added node, or NULL on failure.
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
    return add_dnodeint(head, n, 1);
}

/**
 * free_dlistint - Frees the doubly linked list.
 * @head: Head of the list.
 */
void free_dlistint(stack_t *head)
{
    stack_t *current;

    while (head)
    {
        current = head;
        head = head->next;
        free(current);
    }
}
