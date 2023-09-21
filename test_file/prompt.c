#include "shell.h"

/**
 * prompt - Print shell prompt to stdin stream.
 *
 * Return: void.
 */
void prompt(void)
{
	_puts(PROMPT);
	fflush(stdout);

/**	if ((isatty(STDIN_FILENO) == 1) && (isatty(STDOUT_FILENO) == 1))
		flag.interactive = 1;
	if (flag.interactive)
		write(STDERR_FILENO, "$ ", 2);
		*/
}
