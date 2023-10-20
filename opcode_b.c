#include "monty.h"

/**
 * _add - Adds the top two values of a stack_t linked list.
 * @doubly: Pointer to the head of the linked list.
 * @cline: Line number
 * Description: The result is stored in the second value node
 * from the top, and the top value is removed.
 */
void _add(stack_t **doubly, unsigned int cline)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't add, stack too short\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	aux = (*doubly)->next;
	aux->n += (*doubly)->n;
	_pop(doubly, cline);
}

/**
 * _nop - Does nothing.
 * @doubly: Pointer to the linked list head.
 * @cline: Line number
 */
void _nop(stack_t **doubly, unsigned int cline)
{
	(void)doubly;
	(void)cline;
}

/**
 * _sub - Subtracts the second value from the top of the stack_t linked list
 * by the top value.
 * @head: The head node
 * @cline: The line number
 * Description: The result is stored in the second value node
 * from the top, and the top value is removed.
 */
void _sub(stack_t **head, unsigned int cline)
{
	int m = 0;
	stack_t *current;

	current = *head;

	for (; current != NULL; current = current->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't sub, stack too short\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	current = (*head)->next;
	current->n -= (*head)->n;
	_pop(head, cline);
}

/**
 * _div - Divides the second value from the top of the stack_t linked list
 * by the top value.
 * @doubly: Pointer to the head of the linked list.
 * @cline: Line number
 * Description: The result is stored in the second value node
 * from the top, and the top value is removed.
 */
void _div(stack_t **doubly, unsigned int cline)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't div, stack too short\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	if ((*doubly)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	aux = (*doubly)->next;
	aux->n /= (*doubly)->n;
	_pop(doubly, cline);
}

/**
 * _mul - Multiplies the second value from the top of the stack_t linked list
 * by the top value.
 * @head: The head node
 * @cline: The line number
 * Description: The result is stored in the second value node
 * from the top, and the top value is removed.
 */
void _mul(stack_t **head, unsigned int cline)
{
	int m = 0;
	stack_t *current;

	current = *head;

	for (; current != NULL; current = current->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't mul, stack too short\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	current = (*head)->next;
	current->n *= (*head)->n;
	_pop(head, cline);
}
