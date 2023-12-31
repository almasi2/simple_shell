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

/*------------kelvin_builtins.c -------*/

int ext_builtn(program_data *data);
int builtin_change(program_data *data);

/*----------- frank_builtins.c -------*/

int work_dir_setup(program_data *data, char *new_dir);
int builtn_assist(program_data *data);
int alias_builtn(program_data *data);

/*----------- env_setup.c *------------*/

int env_setup(program_data *data);

/*---------- set_unset_env.c *-----------*/

int set_env(program_data *data);
int unset_env(program_data *data);

/*-----------variable_expansion.c-----------*/

void variable_expansion(program_data *data);

/*------------ alias_expansion.c ----------*/

int add_buffer(char *buffer, char *str_to_add);
void alias_expansion(program_data *data);

/*---------- find_program.c -----------*/

int find_program(program_data *data);


/*----------program_path.c----------*/

char **tokenize_path(program_data *data);
int check_file(char *full_path);


/*-------------free_func.c---------------*/

void free_data_recurrent(program_data *data);
void free_full_data(program_data *data);
void free_array_pointers(char **array);

/*------------- _atoi.c ------------*/

int _atoi(char *s);

/*------------- string.c ------------*/

int chars_count(char *string, char *character);
void string_conv(long number, char *string, int base);


/*-------------print.c-----------*/

int _print(char *string);
int _printe(char *string);
int _print_err(int errorcode, program_data *data);

/*------------ compare_reverse_string.c ---------*/

void str_reverse(char *string);
int str_comp(char *string1, char *string2, int number);

/*----------- concat_duplicate.c -------------*/

int str_len(char *string);
char *str_dup(char *string);
char *str_concat(char *string1, char *string2);

/*------------- setup_env.c --------------*/

void print_environ(program_data *data);
int set_key(char *key, char *value, program_data *data);


/*-------------get_remove_key.c---------------*/

char *env_get_key(char *key, program_data *data);
int key_remove(char *key, program_data *data);


/*----------------alias.c---------------*/

int print_alias(program_data *data, char *alias);
char *get_alias(program_data *data, char *name);

/*--------------mypid.c-----------*/

int set_alias(char *alias_string, program_data *data);

#endif
