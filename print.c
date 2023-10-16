#include "shell.h"

/**
 * _print - this will writes an array of chars in standard output
 * @string: the pointer to an aray of chars
 * Return: this is the number of bytes written.
 * On error, -1 is returned.
 */
int _print(char *string)
{
	return (write(STDOUT_FILENO, string, str_len(string)));
}
/**
 * _printe - this writes an array of chars instandar error
 * @string: this is the pointer to the array of chars
 * Return: number of bytes written.
 * On error, -1 is returned.
 */
int _printe(char *string)
{
	return (write(STDERR_FILENO, string, str_len(string)));
}

/**
 * _print_err - this writes a array of chars in the standart error.
 * @data: a pointer to program's data.
 * @errorcode: this is the error code to be printed.
 * Return: number of bytes written.
 * On error, -1 is returned.
 */
int _print_err(int errorcode, program_data *data)
{
	char n_as_string[10] = {'\0'};

	string_conv((long) data->exec_counter, n_as_string, 10);

	if (errorcode == 2 || errorcode == 3)
	{
		_printe(data->program_name);
		_printe(": ");
		_printe(n_as_string);
		_printe(": ");
		_printe(data->tokens[0]);
		if (errorcode == 2)
			_printe(": Illegal number: ");
		else
			_printe(": can't cd to ");
		_printe(data->tokens[1]);
		_printe("\n");
	}
	else if (errorcode == 127)
	{
		_printe(data->program_name);
		_printe(": ");
		_printe(n_as_string);
		_printe(": ");
		_printe(data->command_name);
		_printe(": not found\n");
	}
	else if (errorcode == 126)
	{
		_printe(data->program_name);
		_printe(": ");
		_printe(n_as_string);
		_printe(": ");
		_printe(data->command_name);
		_printe(": Permission denied\n");
	}
	return (0);
}
