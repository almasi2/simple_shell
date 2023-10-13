#include "shell.h"

/**
 * ext_builtn - this exts program with the status
 * @data: program data struct
 * Return: 0 on sucess, any other number if declared in arguments
 */
int ext_builtn(program_data *data)
{
	int j;

	if (data->tokens[1] != NULL)
	{
		for (j = 0; data->tokens[1][j]; j++)
			if ((data->tokens[1][j] < '0' || data->tokens[1][j] > '9')
				&& data->tokens[1][j] != '+')
			{
				errno = 2;
				return (2);
			}
		errno = _atoi(data->tokens[1]);
	}
	free_all_data(data);
	exit(errno);
}

/**
 * builtin_change - this changes the current directory
 * @data: struct for program's data
 * Return: 0 on sucess, any other number if declared in arguments
 */
int builtin_change(program_data *data)
{
	char *dir_home = env_get_key("HOME", data), *dir_old = NULL;
	char old_dir[128] = {0};
	int error_code = 0;

	if (data->tokens[1])
	{
		if (str_compare(data->tokens[1], "-", 0))
		{
			dir_old = env_get_key("OLDPWD", data);
			if (dir_old)
				error_code = work_dir_setup(data, dir_old);
			_print(env_get_key("PWD", data));
			_print("\n");

			return (error_code);
		}
		else
		{
			return (work_dir_setup(data, data->tokens[1]));
		}
	}
	else
	{
		if (!dir_home)
			dir_home = getcwd(old_dir, 128);

		return (work_dir_setup(data, dir_home));
	}
	return (0);
}
