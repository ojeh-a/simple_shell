#include "shell.h"

/**
 * _unsetenv - Unsets an environment variable.
 * @name: The name of the environment variable to unset.
 *
 * Return: 0 on success, -1 on failure.
 */
int _unsetenv(const char *name)
{
    int index, len, i;

    if (!name || name[0] == '\0' || name[0] == '=')
        return -1;

    len = _strlen(name);

    for (index = 0; environ[index]; index++)
    {
        if (_strncmp(name, environ[index], len) == 0 && environ[index][len] == '=')
        {
            free(environ[index]);

            for (i = index; environ[i + 1]; i++)
                environ[i] = environ[i + 1];

            environ[i] = NULL;

            return (0);
        }
    }

    return (-1)
}

