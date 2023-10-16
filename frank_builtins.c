#include "shell.h"

/**
 * work_dir_setup - sets working dir
 * @data: program data struct
 * @new_dir: path to set as working dir
 * Return: 0 on sucess, any number if declared in arguments
 */
int work_dir_setup(program_data *data, char *new_dir)
{
	char old_dir[128] = {0};
	int err_code = 0;

	getcwd(old_dir, 128);

	if (!str_compare(old_dir, new_dir, 0))
	{
		err_code = chdir(new_dir);
		if (err_code == -1)
		{
			errno = 2;
			return (3);
		}
		set_key("PWD", new_dir, data);
	}
	set_key("OLDPWD", old_dir, data);
	return (0);
}

/**
 * builtn_assist - show environment on which shell runs
 * @data: program data stuct
 * Return: 0 on sucess, any number if declared in arguments
 */
int builtn_assist(program_data *data)
{
	int j, lenth = 0;
	char *feedback[6] = {NULL};

	feedback[0] = HELP_MSG;

	if (data->tokens[1] == NULL)
	{
		_print(feedback[0] + 6);
		return (1);
	}
	if (data->tokens[2] != NULL)
	{
		errno = E2BIG;
		perror(data->command_name);
		return (5);
	}
	feedback[1] = HELP_EXIT_MSG;
	feedback[2] = HELP_ENV_MSG;
	feedback[3] = HELP_SETENV_MSG;
	feedback[4] = HELP_UNSETENV_MSG;
	feedback[5] = HELP_CD_MSG;

	for (j = 0; feedback[j]; j++)
	{
		lenth = str_length(data->tokens[1]);
		if (str_compare(data->tokens[1], feedback[j], lenth))
		{
			_print(feedback[j] + lenth + 1);
			return (1);
		}
	}
	errno = EINVAL;
	perror(data->command_name);
	return (0);
}

/**
 * alias_builtn - show, add, remove synonyms
 * @data: program data struct
 * Return: 0 on sucess, any number if declared in arguments
 */
int alias_builtn(program_data *data)
{
	int j = 0;

	if (data->tokens[1] == NULL)
		return (print_alias(data, NULL));

	while (data->tokens[++j])
	{
		if (chars_count(data->tokens[j], "="))
			set_alias(data->tokens[j], data);
		else
			print_alias(data, data->tokens[j]);
	}

	return (0);
}
