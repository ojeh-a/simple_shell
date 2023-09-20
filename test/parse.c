#include "shell.h"
/**
 * tokenize - tokenise a string using a delimiter.
 * @str: the string to be tokenized.
 * @delim: the delimiter used to split the string.
 *
 * Return: an array of pointers to the tokens,
 *         or NULL if an error occurs.
 */
char **tokenize(char *str, const char *delim)
{
	char *token = NULL;
	char **ret = NULL;
	int x = 0;

	token = strtok(str, delim);
	while (token)
	{
		ret = realloc(ret, sizeof(char *) * (x + 1));
		if (ret == NULL)
			return (NULL);

		ret[x] = malloc(_strlen(token) + 1);
		if (!(ret[x]))
			return (NULL);

		_strcpy(ret[x], token);
		token = strtok(NULL, delim);
		x++;
	}
	/*increase the size of the array*/
	ret = realloc(ret, (x + 1) * sizeof(char *));
	if (!ret)
		return (NULL);

	ret[x] = NULL;
	return (ret);
}

/**
 * tokenize_input - splits a user input string into tokens with tokenize().
 * @input: the user input string to be tokenized
 *
 * Return: an array of pointers to the tokens, or NULL if an error occurs
 */
char **tokenize_input(char *input)
{
	char **tokens = NULL;
	char *tmp = NULL;

	tmp = _strdup(input);
	if (tmp == NULL)
	{
		_puts("Memory allocation error\n");
		exit(EXIT_FAILURE);
	}

	tokens = tokenize(tmp, " \t\r\n\a");
	free(tmp);

	return (tokens);
}
