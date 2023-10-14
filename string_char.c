#include "shell.h"

/**
 * string_conv - converts number into string.
 * @number: no for conversion in the string.
 * @string: buffer to save string.
 * @base: base for converting no.
 *
 * Return: Nothing.
 */
void string_conv(long number, char *string, int base)
{
	int index = 0, inNegative = 0;
	long cociente = number;
	char letters[] = {"0123456789abcdef"};

	if (cociente == 0)
		string[index++] = '0';

	if (string[0] == '-')
		inNegative = 1;

	while (cociente)
	{
		if (cociente < 0)
			string[index++] = letters[-(cociente % base)];
		else
			string[index++] = letters[cociente % base];
		cociente /= base;
	}
	if (inNegative)
		string[index++] = '-';

	string[index] = '\0';
	str_reverse(string);
}



/**
 * chars_count - coincidences of char count in string.
 *
 * @string: pointer
 * @character: string to be counted
 * Return: zero or int string.
 */
int chars_count(char *string, char *character)
{
	int j = 0, counter = 0;

	for (; string[j]; j++)
	{
		if (string[j] == character[0])
			counter++;
	}
	return (counter);
}
