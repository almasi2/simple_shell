#include "shell.h"

/**
 * env_setup - shows environment on which shell runs
 * @data: program data struct
 * Return: 0 on sucess, any number if declared in arguments
 */
int env_setup(program_data *data)
{
	int j;
	char cpname[50] = {'\0'};
	char *var_copy = NULL;

	if (data->tokens[1] == NULL)
		print_environ(data);
	else
	{
		for (j = 0; data->tokens[1][j]; j++)
		{
			if (data->tokens[1][j] == '=')
			{
				var_copy = str_dup(env_get_key(cpname, data));
				if (var_copy != NULL)
					set_key(cpname, data->tokens[1] + j + 1, data);

				print_environ(data);
				if (env_get_key(cpname, data) == NULL)
				{
					_print(data->tokens[1]);
					_print("\n");
				}
				else
				{
					set_key(cpname, var_copy, data);
					free(var_copy);
				}
				return (0);
			}
			cpname[j] = data->tokens[1][j];
		}
		errno = 2;
		perror(data->command_name);
		errno = 127;
	}
	return (0);
}
