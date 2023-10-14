#include "shell.h"

/**
 * free_data_recurrent - this willl free the fields needed each loop
 * @data: program's data struct
 * Return: returns Nothing.
 */
void free_data_recurrent(program_data *data)
{
	if (data->tokens)
		free_array_pointers(data->tokens);
	if (data->input_line)
		free(data->input_line);
	if (data->command_name)
		free(data->command_name);

	data->input_line = NULL;
	data->command_name = NULL;
	data->tokens = NULL;
}

/**
 * free_full_data - free all data fields.
 * @data: program's data struct
 * Return: returns Nothing.
 */
void free_full_data(program_data *data)
{
	if (data->file_descriptor != 0)
	{
		if (close(data->file_descriptor))
			perror(data->program_name);
	}
	free_data_recurrent(data);
	free_array_pointers(data->env);
	free_array_pointers(data->alias_list);
}

/**
 * free_array_pointers - this frees each pointer of an array of and the
 * array too
 * @array: the array of pointers
 * Return: returns 0
 */
void free_array_pointers(char **array)
{
	int j;

	if (array != NULL)
	{
		for (j = 0; array[j]; j++)
			free(array[j]);

		free(array);
		array = NULL;
	}
}
