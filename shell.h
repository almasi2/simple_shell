#ifndef SHELL_H
#define SHELL_H

#include <stdio.h> /* printf library*/
#include <unistd.h> /* fork,execve library*/
#include <stdlib.h>
#include <string.h> /* strtok */
#include <stddef.h>
#include <errno.h> /* errno and perror */
#include <sys/types.h> /* type pid */
#include <sys/wait.h> /* wait */
#include <sys/stat.h> /* stat function */
#include <signal.h> /* signal management */
#include <fcntl.h> /* open files*/

/************* MACROS **************/

#include "macros.h" /* for msg help and prompt */

/************* STRUCTURES **************/

/**
 * struct info- struct for the program's data
 * @program_name: the name of the executable
 * @input_line: pointer to the input read for _getline
 * @command_name: pointer to the first command typed by the user
 * @exec_counter: number of excecuted comands
 * @file_descriptor: file descriptor to the input of commands
 * @tokens: pointer to array of tokenized input
 * @env: copy of the environ
 * @alias_list: array of pointers with aliases.
 */
