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
