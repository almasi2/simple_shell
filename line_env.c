#include "shell.h"

/**
* line_fetch - this will read one line from propt.
* @data: this is the struct for  program's data
*
* Return: counting bytes.
*/
int line_fetch(program_data *data)
{
	char buff[BUFFER_SIZE] = {'\0'};
	static char *array_commands[10] = {NULL};
	static char array_operators[10] = {'\0'};
	ssize_t read_bytes, j = 0;

	if (!array_commands[0] || (array_operators[0] == '&' && errno != 0) ||
		(array_operators[0] == '|' && errno == 0))
	{

		for (j = 0; array_commands[j]; j++)
		{
			free(array_commands[j]);
			array_commands[j] = NULL;
		}

		read_bytes = read(data->file_descriptor, &buff, BUFFER_SIZE - 1);
		if (read_bytes == 0)
			return (-1);

		j = 0;
		do {
			array_commands[j] = str_duplicate(token_str(j ? NULL : buff, "\n;"));
			j = logic_checks(array_commands, j, array_operators);
		} while (array_commands[j++]);
	}

	data->input_line = array_commands[0];
	for (j = 0; array_commands[j]; j++)
	{
		array_commands[j] = array_commands[j + 1];
		array_operators[j] = array_operators[j + 1];
	}

	return (str_length(data->input_line));
}

/**
* logic_checks - this function will checks n split for && and || operators
* @array_commands: this is an array of  commands.
* @i: the index in array_commands to be checked
* @array_operators: array of logical operators for each previous command
*
* Return: the index of last command in array_commands.
*/
int logic_checks(char *array_commands[], int i, char array_operators[])
{
	char *temp = NULL;
	int k;

	for (k = 0; array_commands[i] != NULL  && array_commands[i][k]; k++)
	{
		if (array_commands[i][k] == '&' && array_commands[i][k + 1] == '&')
		{
			temp = array_commands[i];
			array_commands[i][k] = '\0';
			array_commands[i] = str_duplicate(array_commands[i]);
			array_commands[i + 1] = str_duplicate(temp + k + 2);
			i++;
			array_operators[i] = '&';
			free(temp);
			k = 0;
		}
		if (array_commands[i][k] == '|' && array_commands[i][k + 1] == '|')
		{
			temp = array_commands[i];
			array_commands[i][k] = '\0';
			array_commands[i] = str_duplicate(array_commands[i]);
			array_commands[i + 1] = str_duplicate(temp + k + 2);
			i++;
			array_operators[i] = '|';
			free(temp);
			k = 0;
		}
	}
	return (i);
}
