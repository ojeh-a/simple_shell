#include "shell.h"
/**
 * execute - Execute a command with arguments.
 * @argv: An array of strings containing the command and its arguments.
 *
 * Return: The exit status of the executed command.
 */
int execute(char **argv)
{
	pid_t child_pid;
	int status = 0;
	char *cmd_path, *envp[2];

	if (argv == NULL || *argv == NULL)
		return (status);
	if (check_for_builtin(argv))
		return (status);

	child_pid = fork();
	if (child_pid < 0)
	{
		_puterror("fork");
		return (1);
	}

	else if (child_pid == 0)
	{
		cmd_path = (argv[0][0] != '/') ? find_in_path(argv[0]) : argv[0];
		if (!cmd_path || execve(cmd_path, argv, envp) == -1)
		{
			perror(argv[0]);
			free_tokens(argv);
			free_last_input();
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		do {
			waitpid(child_pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (status);
}
