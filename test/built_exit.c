#include "shell.h"

/**
 * shell_exit - Exit the shell.
 * @args: Arguments.
 *
 * Return: Does not return; exit the shell.
 */
void shell_exit(char **args)
{
	int x = 0;

	if (args[1] != NULL)
	{
		x = _atoi(args[1]);
	}
	free_tokens(args);
	free_last_input();

	exit(x);
}
