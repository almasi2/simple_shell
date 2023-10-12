#include "shell.h"
/**
 * token_str - this will separates strings with delimiters
 * @line: a pointer to an array we receive in getline.
 * @delim: the characters we mark off in string parts.
 * Return: pointer to the created token
*/
char *token_str(char *line, char *delim)
{
	int i;
	static char *str;
	char *copystr;

	if (line != NULL)
		str = line;
	for (; *str != '\0'; str++)
	{
		for (i = 0; delim[i] != '\0'; i++)
		{
			if (*str == delim[i])
			break;
		}
		if (delim[i] == '\0')
			break;
	}
	copystr = str;
	if (*copystr == '\0')
		return (NULL);
	for (; *str != '\0'; str++)
	{
		for (i = 0; delim[i] != '\0'; i++)
		{
			if (*str == delim[i])
			{
				*str = '\0';
				str++;
				return (copystr);
			}
		}
	}
	return (copystr);
}
