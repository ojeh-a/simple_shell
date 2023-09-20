#include "shell.h"
/**
 * exitt - exits the shell with or without a return status of n
 * @arv: array of words of the entered line
 */
void exitt(char **arv)
{
	int x, n;

	if (arv[1])
	{
		n = _atoi(arv[1]);
		if (n <= -1)
			n = 2;
		exit(n);
	}

	for (x = 0; arv[x]; x++)
		free(arv[x]);

	free(arv);
	exit(0);
}
