#include "shell.h"
/**
 * shell_env - Prints all the environment variables.
 *
 * Return: void.
 */
int shell_env(void)
{
	int x;

	for (x = 0; environ[x]; x++)
	{
		_puts(environ[x]);
		_putchar('\n');
	}

	return (0);
}
