#include "shell.h"
/**
 * shell_cd - changes the current working directory of the shell
 * @args: array of arguments
 */
void shell_cd(char **args)
{
	char *dir = args[1];

	if (dir == NULL)
	{
		dir = _getenv("HOME");
		if (dir == NULL)
		{
			_puts("cd: No HOME directory found\n");
			return;
		}
	}

	if (chdir(dir) == -1)
	{
		perror("cd");
	}
}
