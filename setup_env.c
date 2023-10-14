#include "shell.h"

/**
 * set_key - this overwrites value of the environmnt variable
 * or create it if doesn't exist.
 * @key: name of variable to set
 * @value: the new value
 * @data: program's data struct.
 * Return: 1 if parameters are NULL, 2 if there's an erroror 0 if sucess.
 */

int set_key(char *key, char *value, program_data *data)
{
	int j, key_length = 0, is_new_key = 1;


	if (key == NULL || value == NULL || data->env == NULL)
		return (1);

	key_length = str_length(key);

	for (j = 0; data->env[j]; j++)
	{
		if (str_compare(key, data->env[j], key_length) &&
		 data->env[i][key_length] == '=')
		{
			is_new_key = 0;
			free(data->env[j]);
			break;
		}
	}
	data->env[j] = str_concat(str_duplicate(key), "=");
	data->env[j] = str_concat(data->env[j], value);

	if (is_new_key)
	{
		data->env[j + 1] = NULL;
	}
	return (0);
}

/**
 * print_environ - this prints current environ
 * @data: program's data struct
 * Return: returns nill.
 */
void print_environ(program_data *data)
{
	int i;

	for (i = 0; data->env[i]; i++)
	{
		_print(data->env[i]);
		_print("\n");
	}
}
