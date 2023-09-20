#include "shell.h"
/**
 * free_error - frees memory allocated for command-line
 * the program with and error status
 * @argv: pointer to an array string
 * @arg: pointer to a string
 *
 */
void free_error(char **argv, char *arg)
{
	int x;

	for (x = 0; argv[x]; x++)
	{
		free(argv[x]);
	}
	free(argv);
	free(arg);

	exit(EXIT_FAILURE);
}
/**
 * free_tokens - frees memory allocated dynamically by tokenize()
 * @ptr: pointer to allocated memory
 *
 * Return: void.
 */
void free_tokens(char **ptr)
{
	int x;

	for (x = 0; ptr[x]; x++)
		free((ptr[x]));
	free(ptr);
}

/**
 * free_path - Frees the global variable containing the PATH environment
 *              variable value
 *
 * Return: Nothing
 */
void free_path(void)
{
	size_t x;

	if (environ != NULL)
		return;
	for (x = 0; environ[x] != NULL; x++)
	{
		if (_strncmp(environ[x], "PATH=", 5) == 0)
		{
			free(environ[x]);
			environ[x] = NULL;
			break;
		}
		x++;
	}
}
