#include "shell.h"

/**
 * print_alias - show, add, remove aliases
 * @data: program's data struct
 * @alias: alias name to print
 * Return: 0 if sucess, any number if declared in arguments
 */
int print_alias(program_data *data, char *alias)
{
	int m, k, alias_length;
	char buffer[250] = {'\0'};

	if (data->alias_list)
	{
		alias_length = str_length(alias);
		for (m = 0; data->alias_list[m]; m++)
		{
			if (!alias || (str_compare(data->alias_list[m], alias, alias_length)
				&&	data->alias_list[m][alias_length] == '='))
			{
				for (k = 0; data->alias_list[m][k]; k++)
				{
					buffer[k] = data->alias_list[m][k];
					if (data->alias_list[m][k] == '=')
						break;
				}
				buffer[k + 1] = '\0';
				add_buffer(buffer, "'");
				add_buffer(buffer, data->alias_list[m] + k + 1);
				add_buffer(buffer, "'\n");
				_print(buffer);
			}
		}
	}

	return (0);
}

/**
 * get_alias - show, add, remove aliases
 * @data: program data struct
 * @name: requested alias name
 * Return: 0 if sucess, any other number if declared in arguments
 */
char *get_alias(program_data *data, char *name)
{
	int m, alias_length;

	if (name == NULL || data->alias_list == NULL)
		return (NULL);

	alias_length = str_length(name);

	for (m = 0; data->alias_list[m]; m++)
	{
		if (str_compare(name, data->alias_list[m], alias_length) &&
			data->alias_list[m][alias_length] == '=')
		{
			return (data->alias_list[m] + alias_length + 1);
		}
	}
	return (NULL);

}
