#include "shell.h"

/**
 * env_get_key - gets environment variable value
 * @key: environment variable of concern
 * @data: program data struct
 * Return: pointer to variable value or NULL if doesn't exist
 */
char *env_get_key(char *key, program_data *data)
{
	int j, key_length = 0;

	if (key == NULL || data->env == NULL)
		return (NULL);

	key_length = str_length(key);

	for (j = 0; data->env[j]; j++)
	{
		if (str_compare(key, data->env[j], key_length) &&
		 data->env[j][key_length] == '=')
		{
			return (data->env[j] + key_length + 1);
		}
	}
	return (NULL);
}




/**
 * key_remove - key remove from environment
 * @key: the key
 * @data: program data struct
 * Return: 1 if key removed, 0 if key doesn't exist;
 */
int key_remove(char *key, program_data *data)
{
	int j, key_length = 0;

	if (key == NULL || data->env == NULL)
		return (0);

	key_length = str_length(key);

	for (j = 0; data->env[j]; j++)
	{
		if (str_compare(key, data->env[j], key_length) &&
		 data->env[j][key_length] == '=')
		{
			free(data->env[i]);

			j++;
			for (; data->env[j]; j++)
			{
				data->env[j - 1] = data->env[j];
			}
			data->env[j - 1] = NULL;
			return (1);
		}
	}
	return (0);
}
