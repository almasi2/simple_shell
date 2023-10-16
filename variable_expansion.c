#include "shell.h"

/**
 * variable_expansion - expand variables
 * @data: pointer to program data struct
 * Return: nothing, sets errno.
 */

void variable_expansion(program_data *data)
{
	int j, k;
	char line[BUFFER_SIZE] = {0}, expansion[BUFFER_SIZE] = {'\0'}, *temp;

	if (data->input_line == NULL)
		return;
	add_buffer(line, data->input_line);
	for (j = 0; line[j]; j++)
		if (line[j] == '#')
			line[j--] = '\0';
		else if (line[j] == '$' && line[j + 1] == '?')
		{
			line[j] = '\0';
			string_conv(errno, expansion, 10);
			add_buffer(line, expansion);
			add_buffer(line, data->input_line + j + 2);
		}
		else if (line[j] == '$' && line[j + 1] == '$')
		{
			line[j] = '\0';
			string_conv(getpid(), expansion, 10);
			add_buffer(line, expansion);
			add_buffer(line, data->input_line + j + 2);
		}
		else if (line[j] == '$' && (line[j + 1] == ' ' || line[j + 1] == '\0'))
			continue;
		else if (line[j] == '$')
		{
			for (k = 1; line[j + k] && line[j + k] != ' '; k++)
				expansion[k - 1] = line[j + k];
			temp = env_get_key(expansion, data);
			line[j] = '\0', expansion[0] = '\0';
			add_buffer(expansion, line + j + k);
			temp ? add_buffer(line, temp) : 1;
			add_buffer(line, expansion);
		}
	if (!str_compare(data->input_line, line, 0))
	{
		free(data->input_line);
		data->input_line = str_duplicate(line);
	}
}
