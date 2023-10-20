#include "monty.h"

/**
 * _stack - Sets the format of data to a stack (LIFO/FILO).
 * @doubly: Pointer to the head of the linked list.
 * @cline: Line number.
 */
void _stack(stack_t **doubly, unsigned int cline)
{
	(void)doubly;
	(void)cline;

	vglo.lifo = 1;
}

/**
 * _queue - Sets the format of data to a queue (FIFO/LILO).
 * @doubly: Pointer to the head of the linked list.
 * @cline: Line number.
 */
void _queue(stack_t **doubly, unsigned int cline)
{
	(void)doubly;
	(void)cline;

	vglo.lifo = 0;
}
