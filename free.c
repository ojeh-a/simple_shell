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
	int i;

	for (i = 0; argv[i]; i++)
	{
		free(argv[i]);
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
	if (environ != NULL)
	{
		size_t x = 0;

		while (environ[x] != NULL)
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
}
