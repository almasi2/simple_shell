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

	signal(SIGINT, print_prompt_n);

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

void initialize_data(program_data *data, int argc, char *argv[], char **env)
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
			data->env[j] = str_dup(env[j]);
		}
	}
	data->env[j] = NULL;
	env = data->env;

	data->alias_list = malloc(sizeof(char *) * 20);
	for (j = 0; j < 20; j++)
	{
		data->alias_list[j] = NULL;
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


/**
 * get_infin_loop - infinite loop showing prompt
 * @prompt: prompt for printing
 * @data: infinite loop showing prompt
 */

void get_infin_loop(char *prompt, program_data *data)
{
	int err_cod = 0, string_len = 0;

	while (++(data->exec_counter))
	{
		_print(prompt);
		err_cod = string_len = line_fetch(data);

		if (err_cod == EOF)
		{
			free_full_data(data);
			exit(errno);
		}
		if (string_len >= 1)
		{
			alias_expansion(data);
			variable_expansion(data);
			tokenization(data);
			if (data->tokens[0])
			{
				err_cod = exec(data);
				if (err_cod != 0)
					_print_err(err_cod, data);
			}
			free_data_recurrent(data);
		}
	}
}

