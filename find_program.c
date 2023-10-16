#include "shell.h"

/**
 * find_program - looks for program in path
 * @data: program data pointer
 * Return: 0 if success, else ercode
 */
int find_program(program_data *data)
{
	int j = 0, ret_code = 0;
	char **directories;

	if (!data->command_name)
		return (2);

	if (data->command_name[0] == '/' || data->command_name[0] == '.')
		return (check_file(data->command_name));

	free(data->tokens[0]);
	data->tokens[0] = str_concat(str_dup("/"), data->command_name);
	if (!data->tokens[0])
		return (2);

	directories = tokenize_path(data);/* search in the PATH */

	if (!directories || !directories[0])
	{
		errno = 127;
		return (127);
	}
	for (j = 0; directories[j]; j++)
	{
		directories[j] = str_concat(directories[j], data->tokens[0]);
		ret_code = check_file(directories[j]);
		if (ret_code == 0 || ret_code == 126)
		{
			errno = 0;
			free(data->tokens[0]);
			data->tokens[0] = str_dup(directories[j]);
			free_array_pointers(directories);
			return (ret_code);
		}
	}
	free(data->tokens[0]);
	data->tokens[0] = NULL;
	free_array_pointers(directories);
	return (ret_code);
}
