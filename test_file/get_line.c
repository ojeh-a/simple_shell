#include "shell.h"

/**
 * get_line - Read input from the standard input.
 *
 * Return: The string entered by the user, or NULL on failure.
 */
char *get_line(void)
{
	char *input_str = NULL;
	size_t input_size = 0;
	ssize_t nread;
	int current_char;

	while (1)
	{
		nread = read(STDIN_FILENO, &current_char, 1);
		if (nread == -1)
		{
			perror("read");
			free(input_str);
			return (NULL);
		}
		if (nread == 0 || current_char == '\n')
		{
			if (input_size > 0)
				input_str[input_size] = '\0';
			return (input_str);
		}
		char *new_input_str = realloc(input_str, input_size + 1);

		if (!new_input_str)
		{
			free(input_str);
			return (NULL);
		}
		input_str = new_input_str;

		input_str[input_size] = (char)current_char;
		input_size++;
	}
}
