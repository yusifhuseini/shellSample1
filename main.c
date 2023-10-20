#include "monty.h"

void (*instruction_function)(stack_t **stack, unsigned int line_number);

global_t global_data;
global_t vglo;

/**
 * free_vglo - Frees the global variables.
 */
void free_vglo(void)
{
	free_dlistint(global_data.head);
	free(global_data.buffer);
	fclose(global_data.fd);
}

/**
 * free_global_data - Frees the global variables.
 */
void free_global_data(void)
{
	free_dlistint(global_data.head);
	free(global_data.buffer);
	fclose(global_data.fd);
}

/**
 * initialize_global_data - Initializes the global variables.
 *
 * @fd: File descriptor
 */
void initialize_global_data(FILE *fd)
{
	global_data.lifo = 1;
	global_data.cont = 1;
	global_data.arg = NULL;
	global_data.head = NULL;
	global_data.fd = fd;
	global_data.buffer = NULL;
}

/**
 * check_file - Checks if the file exists and can be opened.
 *
 * @argc: Argument count
 * @argv: Argument vector
 * @return 1 if the file exists, 0 if it doesn't.
 */
FILE *check_file(int argc, char *argv[])
{
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	return (file);
}

/**
 * main - Entry point
 *
 * @argc: Argument count
 * @argv: Argument vector
 * @return read file
 */
int main(int argc, char *argv[])
{
	FILE *file;
	size_t buffer_size = 256;
	ssize_t read_lines = 0;
	char *line_tokens[2] = {NULL, NULL};

	file = check_file(argc, argv);
	initialize_global_data(file);
	read_lines = getline(&global_data.buffer, &buffer_size, file);

	while (read_lines != -1)
	{
		line_tokens[0] = _strtoky(global_data.buffer, " \t\n");

		if (line_tokens[0] && line_tokens[0][0] != '#')
		{
			instruction_function = get_opcodes(line_tokens[0]);

		if (!instruction_function)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n",
				global_data.cont, line_tokens[0]);
			free_global_data();
			exit(EXIT_FAILURE);
		}

		global_data.arg = _strtoky(NULL, " \t\n");
		instruction_function(&global_data.head, global_data.cont);
		}

		read_lines = getline(&global_data.buffer, &buffer_size, file);
		global_data.cont++;
	}

	free_global_data();

	return (EXIT_SUCCESS);
}
