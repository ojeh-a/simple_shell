#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * shell_cd - changes the current working directory of the shell
 * @args: array of arguments
 */
void shell_cd(char **args)
{
    char *dir = args[1];

    if (dir == NULL)
    {
        dir = getenv("HOME");
        if (dir == NULL)
        {
            _puts(stderr, "cd: No HOME directory found\n");
            return;
        }
    }

    if (chdir(dir) == -1)
    {
        perror("cd");
    }
}

