#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <errno.h>
#include <sys/wait.h>
#include <errno.h>:
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
