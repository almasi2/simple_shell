#include "shell.h"

/**
 * set_alias - this will add, or override alias
 * @alias_string: to be seied in the form.
 * @data: program's data struct
 * Return: 0 if sucess, or other number if declred in arguments
 */
int set_alias(char *alias_string, program_data *data)
{
	int j, k;
	char buffer[250] = {'0'}, *temp = NULL;

	if (alias_string == NULL ||  data->alias_list == NULL)
		return (1);
	for (j = 0; alias_string[j]; j++)
		if (alias_string[j] != '=')
			buffer[j] = alias_string[j];
		else
		{
			temp = get_alias(data, alias_string + j + 1);
			break;
		}

	for (k = 0; data->alias_list[k]; k++)
		if (str_comp(buffer, data->alias_list[k], j) &&
			data->alias_list[k][j] == '=')
		{
			free(data->alias_list[k]);
			break;
		}

	if (temp)
	{
		add_buffer(buffer, "=");
		add_buffer(buffer, temp);
		data->alias_list[k] = str_dup(buffer);
	}
	else
		data->alias_list[k] = str_dup(alias_string);
	return (0);
}
