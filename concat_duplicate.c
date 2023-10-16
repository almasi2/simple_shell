#include "shell.h"

/**
 * str_len - return string length
 * @string: pointer
 * Return: string length
 */
int str_len(char *string)
{
	int length = 0;

	if (string == NULL)
		return (0);

	while (string[length++] != '\0')
	{
	}
	return (--length);
}



/**
 * str_concat - link two strings.
 * @string1: String to link
 * @string2: String to be linked
 *
 * Return: array pointer
 */
char *str_concat(char *string1, char *string2)
{
	char *result;
	int length1 = 0, length2 = 0;

	if (string1 == NULL)
		string1 = "";
	length1 = str_len(string1);

	if (string2 == NULL)
		string2 = "";
	length2 = str_len(string2);

	result = malloc(sizeof(char) * (length1 + length2 + 1));
	if (result == NULL)
	{
		errno = ENOMEM;
		perror("Error");
		return (NULL);
	}

	for (length1 = 0; string1[length1] != '\0'; length1++)
		result[length1] = string1[length1];
	free(string1);

	for (length2 = 0; string2[length2] != '\0'; length2++)
	{
		result[length1] = string2[length2];
		length1++;
	}

	result[length1] = '\0';
	return (result);
}



/**
 * str_dup - duplicate strng
 * @string: Strng for copying
 * Return: array pointer
 */
char *str_dup(char *string)
{
	char *result;
	int length, j;

	if (string == NULL)
		return (NULL);

	length = str_len(string) + 1;

	result = malloc(sizeof(char) * length);

	if (result == NULL)
	{
		errno = ENOMEM;
		perror("Error");
		return (NULL);
	}
	for (j = 0; j < length ; j++)
	{
		result[j] = string[j];
	}

	return (result);
}
