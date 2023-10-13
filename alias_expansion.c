#include "shell.h"

/**
 * alias_expansion - this expands the aliases
 * @data: a pointer to a program's data struct
 *
 * Return: 0, but sets errno.
 */
void alias_expansion(program_data *data)
{
	int i, j, was_expanded = 0;
	char line[BUFFER_SIZE] = {0}, expansion[BUFFER_SIZE] = {'\0'}, *temp;

	if (data->input_line == NULL)
		return;

	buffer_add(line, data->input_line);

	for (i = 0; line[i]; i++)
	{
		for (j = 0; line[i + j] && line[i + j] != ' '; j++)
			expansion[j] = line[i + j];
		expansion[j] = '\0';

		temp = get_alias(data, expansion);
		if (temp)
		{
			expansion[0] = '\0';
			buffer_add(expansion, line + i + j);
			line[i] = '\0';
			buffer_add(line, temp);
			line[str_length(line)] = '\0';
			buffer_add(line, expansion);
			was_expanded = 1;
		}
		break;
	}
	if (was_expanded)
	{
		free(data->input_line);
		data->input_line = str_duplicate(line);
	}
}

/**
 * add_buffer - this appends a string at end of the buffer
 * @buffer: this is the  buffer to be filled
 * @str_to_add: the string to be copied into the buffer
 * Return: 0, but sets errno.
 */
int add_buffer(char *buffer, char *str_to_add)
{
	int length, j;

	length = str_length(buffer);
	for (j = 0; str_to_add[j]; j++)
	{
		buffer[length + j] = str_to_add[j];
	}
	buffer[length + j] = '\0';
	return (length + j);
}
