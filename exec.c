#include "shell.h"
/**
 * exec - execute command and its path variables.
 * @data: pointer to program data
 * Return: returns 0 if success,and -1 if not.
 */
int exec(program_data *data)
{
	int retrival = 0, status;
	pid_t pidd;

	retrival = built_list(data);
	if (retrival != -1)
		return (retrival);

	retrival = find_program(data);
	if (retrival)
	{
		return (retrival);
	}
	else
	{
		pidd = fork();
		if (pidd == -1)
		{
			perror(data->command_name);
			exit(EXIT_FAILURE);
		}
		if (pidd == 0)
		{
			retrival = execve(data->tokens[0], data->tokens, data->env);
			if (retrival == -1)
				perror(data->command_name), exit(EXIT_FAILURE);
		}
		else
		{
			wait(&status);
			if (WIFEXITED(status))
				errno = WEXITSTATUS(status);
			else if (WIFSIGNALED(status))
				errno = 128 + WTERMSIG(status);
		}
	}
	return (0);
}
