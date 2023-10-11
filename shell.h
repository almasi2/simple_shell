#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>
#include <fcntl.h> 

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
