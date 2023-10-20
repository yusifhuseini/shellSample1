#include "monty.h"

/**
 * _mod - Computes the remainder of the division of the second element
 * by the top element of the stack.
 * @doubly: Pointer to the head of the linked list.
 * @cline: Line number.
 * Description: The result is stored in the second value node
 * from the top, and the top value is removed.
 */
void _mod(stack_t **doubly, unsigned int cline)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't mod, stack too short\n", cline);
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
	aux->n %= (*doubly)->n;
	_pop(doubly, cline);
}

/**
 * _pstr - Prints the string represented by values in the stack.
 * @doubly: Pointer to the head of the linked list.
 * @cline: Line number.
 * Description: Prints characters as long as they are in the range (1-127).
 * Stops printing when encountering a 0 or a value outside the range.
 */
void _pstr(stack_t **doubly, unsigned int cline)
{
	stack_t *aux;
	(void)cline;

	aux = *doubly;

	while (aux && aux->n > 0 && aux->n < 128)
	{
		printf("%c", aux->n);
		aux = aux->next;
	}

	printf("\n");
}

/**
 * _pchar - Prints the character value of the first element in the stack.
 * @doubly: Pointer to the head of the linked list.
 * @cline: Line number.
 * Description: Checks for an empty stack and validates the value range.
 */
void _pchar(stack_t **doubly, unsigned int cline)
{
	if (doubly == NULL || *doubly == NULL)
	{
		dprintf(2, "L%u: can't pchar, stack empty\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	if ((*doubly)->n < 0 || (*doubly)->n >= 128)
	{
		dprintf(2, "L%u: can't pchar, value out of range\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*doubly)->n);
}
