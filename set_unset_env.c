#include "shell.h"

/**
 * set_env - sets the environment to start receiving commads..
 * @data: program's data struct
 * Return: 0 if sucess, any other number if declared in arguments
 */
int set_env(program_data *data)
{

	if (data->tokens[1] == NULL || data->tokens[2] == NULL)
		return (0);
	if (data->tokens[3] != NULL)
	{
		errno = E2BIG;
		perror(data->command_name);
		return (5);
	}

	set_key(data->tokens[1], data->tokens[2], data);

	return (0);
}

/**
 * unset_env - unsets the env..
 * @data: program's data struct
 * Return: ..
 */
int unset_env(program_data *data)
{
	if (data->tokens[1] == NULL)
		return (0);
	if (data->tokens[2] != NULL)
	{
		errno = E2BIG;
		perror(data->command_name);
		return (5);
	}
	key_remove(data->tokens[1], data);

	return (0);
}
