#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <errno.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

/*----------- Macros ---------*/

#include "macros.h" /* msg help and prompt */

/*--------- STRUCTURES --------*/

/**
 * struct info- the structructure for the program's data
 * @program_name: name of executable
 * @input_line: pointer to input read for _getline
 * @command_name: the pointer to first command typed by usa
 * @exec_counter: numba of excecuted comands
 * @file_descriptor: the file descriptor of the input of commands
 * @tokens: the pointer to array of tokenized inputs
 * @env: the copy of the environment
 * @alias_list: the  array of pointers with aliiases.
 */
typedef struct info
{
	char *program_name;
	char *input_line;
	char *command_name;
	int exec_counter;
	int file_descriptor;
	char **tokens;
	char **env;
	char **alias_list;
} program_data;

/**
 * struct builtins - builtins structure
 * @builtin: builtin name
 * @function: function to be called for every single builtin
 */
typedef struct builtins
{
	char *builtin;
	int (*function)(program_data *data);
} builtins;


/* --------------- MAIN FUNCTIONS ----------------- */


/*---------------  shell.c  ------------*/

void get_infin_loop(char *prompt, program_data *data);
void initialize_data(program_data *data, int arc, char *argv[], char **env);
void print_prompt_n(int opr UNUSED);

/*-------------	line_env.c ----------*/

int logic_checks(char *array_commands[], int i, char array_operators[]);
int line_fetch(program_data *data);

/*------------- tokenize_str.c --------*/

char *token_str(char *line, char *delim);

/*------------- tokenization.c ---------*/

void tokenization(program_data *data);

/*----------- exec.c -----------*/

int exec(program_data *data);

/*---------- match_exec_built.c ------*/

int built_list(program_data *data);


#endif
