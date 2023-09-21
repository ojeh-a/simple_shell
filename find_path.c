#include "shell.h"

/**
 * find_in_path - Looks for a command in each directory specified in the PATH
 * @command: pointer to `command` string to look for.
 *
 * Return: pointer to string containing the full path (success) if it is found
 */
char *find_in_path(char *command)
{
    struct stat st;
    int stat_ret, i;
    char buf[PATH_MAX_LENGTH];
    char *path = get_path();
    char *ret = NULL;
    char **dir = NULL;

    if (!path)
        return (NULL);

    dir = tokenize(path, PATH_SEPARATOR);
    if (!dir)
    {
        free(path);
        return (NULL);
    }

    for (i = 0; dir[i]; i++)
    {
        _memset(buf, 0, PATH_MAX_LENGTH);
        _strcpy(buf, dir[i]);
        _strcat(buf, "/");
        _strcat(buf, command);
        stat_ret = stat(buf, &st);

        if (stat_ret == 0 && S_ISREG(st.st_mode) && (st.st_mode & S_IXUSR))
        {
            ret = _strdup(buf);
            break;
        }
    }

    free_tokens(dir);
    free(path);

    return (ret);
}

/*char *find_in_path(char *command)
{
	struct stat st;
	int stat_ret, x;
	char buf[PATH_MAX_LENGTH], *path, *ret, **dir;

	path = get_path();
	if (!path)
		return (NULL);
	dir = tokenize(path, PATH_SEPARATOR);
	if (!dir)
		return (NULL);
	for (x = 0; dir[x]; x++)
	{
		_memset(buf, 0, PATH_MAX_LENGTH);
		_strcpy(buf, dir[x]);
		_strcat(buf, "/");
		_strcat(buf, command);
		stat_ret = stat(buf, &st);
		if (stat_ret == 0 && S_ISREG(st.st_mode) && (st.st_mode & S_IXUSR))
		{
			free_tokens(dir);
			ret = malloc(sizeof(char) * (strlen(buf) + 1));
			free(ret);
			if (!ret)
				return (NULL);
			strcpy(ret, buf);
			return (ret);
		}
	}
	if (stat_ret == -1)
		free_tokens(dir);
	return (NULL);
}*/
