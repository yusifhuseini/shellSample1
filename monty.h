#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#define _POSIX_C_SOURCE 200809L

#include <ctype.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack
 * @n: integer
 * @prev: previous point element of the stack
 * @next: next point element of the stack
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct globals - functions global structure
 * @lifo: is stack or queue
 * @cont: current line
 * @arg: 2nd param inside the current line
 * @head: doubly linked list
 * @fd: file descriptor
 * @buffer: input text
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct globals
{
	int lifo;
	unsigned int cont;
	char  *arg;
	stack_t *head;
	FILE *fd;
	char *buffer;
} global_t;

/**
 * struct bus_s - file, line content, var args
 * @arg: value
 * @file: pointer to monty file
 * @content: line content
 * @lifi: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
}  bus_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: func to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern bus_t bus;
extern global_t vglo;


/* opcode_instructuions*/
void _add(stack_t **doubly, unsigned int cline);
void _div(stack_t **doubly, unsigned int cline);
void _mod(stack_t **doubly, unsigned int cline);
void _mul(stack_t **doubly, unsigned int cline);
void _nop(stack_t **doubly, unsigned int cline);
void _pall(stack_t **stack, unsigned int line_number);
void _pchar(stack_t **doubly, unsigned int cline);
void _pint(stack_t **doubly, unsigned int cline);
void _pop(stack_t **doubly, unsigned int cline);
void _pstr(stack_t **doubly, unsigned int cline);
void _push(stack_t **stack, unsigned int line_number);
void _queue(stack_t **doubly, unsigned int cline);
void _rotl(stack_t **doubly, unsigned int cline);
void _rotr(stack_t **doubly, unsigned int cline);
void _stack(stack_t **doubly, unsigned int cline);
void _sub(stack_t **doubly, unsigned int cline);
void _swap(stack_t **doubly, unsigned int cline);

/*get function*/
void (*get_opcodes(char *opc))(stack_t **stack, unsigned int line_number);

/*imported functions*/
char *_strtoky(char *s, char *d);
int _sch(char *s, char c);
int _strcmp(char *s1, char *s2);
void *_calloc(unsigned int nmemb, unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/* main */
void free_vglo(void);
/*stack_t *add_dnodeint(stack_t **head, const int n, int at_end);*/

/* Function to free global data */
void free_vglo(void);

/* Function to get opcodes */
void (*get_opcodes(char *opc))(stack_t **stack, unsigned int line_number);

/*stack_t *add_dnodeint(stack_t **head, const int n);*/
void free_dlistint(stack_t *head);

/* doubly linked list functions */
stack_t *add_dnodeint_end(stack_t **head, const int n);

#endif /* __MONTY_H__ */
