#include "monty.h"

/**
 * get_opcodes - selects the correct opcode to perform
 *
 * @opc: pass opcode
 *
 * Return: pointer function that executes the opcode
 */
void (*get_opcodes(char *opc))(stack_t **stack, unsigned int line_number)
{
	instruction_t instruct[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{"stack", _stack},
		{"queue", _queue},
		{NULL, NULL}

	};

	int i;

	for (i = 0; instruct[i].opcode; i++)
	{
		if (_strcmp(instruct[i].opcode, opc) == 0)
			break;
	}

	return (instruct[i].f);

}

/**
 * _pall - Prints all values on the stack.
 * @doubly: Pointer to the head of the linked list.
 * @cline: Line number.
 */
void _pall(stack_t **doubly, unsigned int cline)
{
	stack_t *aux;
	(void)cline;

	aux = *doubly;

	while (aux)
	{
		printf("%d\n", aux->n);
		aux = aux->next;
	}
}

/**
 * _pint - Prints the value at the top of the stack.
 * @doubly: Pointer to the head of the linked list.
 * @cline: Line number.
 */
void _pint(stack_t **doubly, unsigned int cline)
{
	(void)cline;

	if (*doubly == NULL)
	{
		dprintf(2, "L%u: can't pint, stack empty\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*doubly)->n);
}
