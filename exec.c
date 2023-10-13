#include "shell.h"
/**
 * exec - execute command and its path variables.
 * @data: pointer to program data
 * Return: returns 0 if success,and -1 if not.
 */
int exec(program_data *data)
{
	int retval = 0, status;
	pid_t pidd;

	retval = builtins_list(data);
	if (retval != -1)
		return (retval);

	retval = find_program(data);
	if (retval)
	{/* program not found */
		return (retval);
	}
	else
	{/* program found */
		pidd = fork(); /* child process creation */
		if (pidd == -1)
		{ /* fork call fail */
			perror(data->command_name);
			exit(EXIT_FAILURE);
		}
		if (pidd == 0)
		{/* child process, executes program*/
			retval = execve(data->tokens[0], data->tokens, data->env);
			if (retval == -1) /* error when executed*/
				perror(data->command_name), exit(EXIT_FAILURE);
		}
		else
		{/* father, waits to check child exit status */
			wait(&status);
			if (WIFEXITED(status))
				errno = WEXITSTATUS(status);
			else if (WIFSIGNALED(status))
				errno = 128 + WTERMSIG(status);
		}
	}
	return (0);
}
