#include "shell.h"

/**
 * tokenize_path - this will tokenize the path in directories
 * @data: this is a pointer to the program's data
 * Return: an array of path directories
 */
char **tokenize_path(program_data *data)
{
	int j = 0;
	int counter_directories = 2;
	char **tokens = NULL;
	char *PATH;

	PATH = env_get_key("PATH", data);
	if ((PATH == NULL) || PATH[0] == '\0')
	{
		return (NULL);
	}

	PATH = str_duplicate(PATH);

	for (j = 0; PATH[j]; j++)
	{
		if (PATH[j] == ':')
			counter_directories++;
	}

	tokens = malloc(sizeof(char *) * counter_directories);

	j = 0;
	tokens[i] = str_duplicate(_strtok(PATH, ":"));
	while (tokens[j++])
	{
		tokens[j] = str_duplicate(_strtok(NULL, ":"));
	}

	free(PATH);
	PATH = NULL;
	return (tokens);

}

/**
 * check_file - this checks if a file exists, if it is not a dairectory n
 * if it has excecution permisions.
 * @full_path: the pointer to the full file name
 * Return: 0 on success, or error code if exists.
 */
int check_file(char *full_path)
{
	struct stat sb;

	if (stat(full_path, &sb) != -1)
	{
		if (S_ISDIR(sb.st_mode) ||  access(full_path, X_OK))
		{
			errno = 126;
			return (126);
		}
		return (0);
	}

	errno = 127;
	return (127);
}
