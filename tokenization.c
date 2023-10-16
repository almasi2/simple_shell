#include "shell.h"
/**
 * tokenization - a unction that separates the string using a designed delimiter
 * @data: pointer to the program's data
 * Return: array of the different parts of the string
 */
void tokenization(program_data *data)
{
	char *delimiter = " \t";
	int i, j, counta = 2, length;

	length = str_length(data->input_line);
	if (length)
	{
		if (data->input_line[length - 1] == '\n')
			data->input_line[length - 1] = '\0';
	}

	for (i = 0; data->input_line[i]; i++)
	{
		for (j = 0; delimiter[j]; j++)
		{
			if (data->input_line[i] == delimiter[j])
				counta++;
		}
	}

	data->tokens = malloc(counta * sizeof(char *));
	if (data->tokens == NULL)
	{
		perror(data->program_name);
		exit(errno);
	}
	i = 0;
	data->tokens[i] = str_duplicate(token_str(data->input_line, delimiter));
	data->command_name = str_duplicate(data->tokens[0]);
	while (data->tokens[i++])
	{
		data->tokens[i] = str_duplicate(token_str(NULL, delimiter));
	}
}
