#include "shell.h"
/**
 * main - program variables initialization
 * @argc: no. of values from command line
 * @argv: values from the command line
 * @env: no. of values from command line
 * Return: returns 0 if success.
 */

int main(int argc, char *argv[], char *env[])
{
	program_data data_struct = {NULL}, *data = &data_struct;
	char *prompt = "";

	initialize_data(data, argc, argv, env);

	signal(SIGINT, handle_ctrl_c);

	if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO) && argc == 1)
	{/*interactive mode,in the terminal */
		errno = 2;
		prompt = PROMPT_MSG;
	}
	errno = 0;
	get_infin_loop(prompt, data);
	return (0);
}


/**
 * initialize_data - struct initialization with program information
 * @data: pointer to data struct
 * @argv: arguments array passed to program execution
 * @env: environ passed to execution of program
 * @argc: no. of values from command line
 */

void initialize_data(data_of_program *data, int argc, char *argv[], char **env)
{
	int j = 0;

	data->program_name = argv[0];
	data->input_line = NULL;
	data->command_name = NULL;
	data->exec_counter = 0;
	/* defining the file descriptor to be read*/
	if (argc == 1)
		data->file_descriptor = STDIN_FILENO;
	else
	{
		data->file_descriptor = open(argv[1], O_RDONLY);
		if (data->file_descriptor == -1)
		{
			_printe(data->program_name);
			_printe(": 0: Can't open ");
			_printe(argv[1]);
			_printe("\n");
			exit(127);
		}
	}
	data->tokens = NULL;
	data->env = malloc(sizeof(char *) * 50);
	if (env)
	{
		for (; env[j]; j++)
		{
			data->env[j] = str_duplicate(env[j]);
		}
	}
	data->env[j] = NULL;
	env = data->env;

	data->alias_list = malloc(sizeof(char *) * 20);
	for (i = 0; i < 20; i++)
	{
		data->alias_list[i] = NULL;
	}
}

/**
 * print_prompt_n - print prompt in new line
 * if signal SIGINT send to program
 * @UNUSED: prototype option
 */

void print_prompt_n(int opr UNUSED)
{
	_print("\n");
	_print(PROMPT_MSG);
}

void get_infin_loop(char *prompt, data_of_program *data)
{
	int err_cod = 0, string_len = 0;

	while (++(data->exec_counter))
	{
		_print(prompt);
		err_cod = string_len = _getline(data);

		if (err_cod == EOF)
		{
			free_all_data(data);
			exit(errno);
		}
		if (string_len >= 1)
		{
			expand_alias(data);
			expand_variables(data);
			tokenize(data);
			if (data->tokens[0])
			{
				err_cod = execute(data);
				if (err_cod != 0)
					_print_error(err_cod, data);
			}
			free_recurrent_data(data);
		}
	}
}

