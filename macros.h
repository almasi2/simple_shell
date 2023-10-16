#ifndef HELPERS_H
#define HELPERS_H

/* Prompt that will be printed */
#define PROMPT_MSG "Bilionaires$$ "
#define UNUSED __attribute__((unused))
/* buffer size for each read call in _getline */
#define BUFFER_SIZE 1024

/************* FORMATTED_STR TO HELP BUILT-IN **************/

#define SET_ENV_MSG "setenv=\n"

#define UNSET_ENV_MSG "unsetenv=\n"

#define HELP_MSG "help=\n"

#define ENV_MSG "env=\n"

#define CD_MSG "cd=\n"

#define EXIT_MSG "exit=\n"

#endif
