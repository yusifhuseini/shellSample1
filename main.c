#include "shell.h"

/**
 * main - main function entry point
 * @ac: arg counter
 * @av: arg vector
 * Code by - Huseini Yusif & Bennet Aboagye-Asare
 * Return: 0 success, 1 error
 */
int main(int ac, char **av)
{
	info_t info[] = { INFO_INIT };
	int fd = 2;

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (fd)
		: "r" (fd));

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				ePuts(av[0]);
				ePuts(": 0: Can't open ");
				ePuts(av[1]);
				ePutChar('\n');
				ePutChar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = fd;
	}
	popuEnvList(info);
	readHistory(info);
	hsh(info, av);
	return (EXIT_SUCCESS);
}
