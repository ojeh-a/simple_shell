#include "shell.h"

/**
 * free_error - frees memory allocated for command-line argument and string and exit 
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
	/* Free the argv array itself */
	free(argv);
	/* Free arg string */
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
	int i;

	for (i = 0; ptr[i]; i++)
		free((ptr[i]));
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
	size_t i;

	if (environ != NULL)
		return;
	for (i = 0; environ[i] != NULL; i++)
	{
		if (_strncmp(environ[i], "PATH=", 5) == 0)
		{
			free(environ[i]);
			environ[i] = NULL;
			break;
		}
	}
}
