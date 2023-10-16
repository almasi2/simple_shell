#include "shell.h"

/**
 * built_list - search, match & execute associated builtin
 * @data: program data structure
 * Return: Returns the function executed
 * otherwise return -1.
 **/
int built_list(program_data *data)
{
	int i;
	builtins options[] = {
		{"exit", ext_builtn},
		{"help", builtn_assist},
		{"cd", builtin_change},
		{"alias", alias_builtn},
		{"env", env_setup},
		{"setenv", set_env},
		{"unsetenv", unset_env},
		{NULL, NULL}
	};

	for (i = 0; options[i].builtin != NULL; i++)
	{
		if (str_compare(options[i].builtin, data->command_name, 0))
		{
			return (options[i].function(data));
		}
	}
	return (-1);
}
