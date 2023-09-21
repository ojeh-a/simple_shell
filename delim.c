#include "shell.h"

/**
 * is_delim - checks fir delimiter.
 *  @c: character
 *  @delim: string
 *
 * Return: 0 or 1.
 */

int is_delim(char c, char *delim)
{
	while  (*delim)
	{
		if (*delim++ == c)
			return (1);
	}
	return (0);
}
