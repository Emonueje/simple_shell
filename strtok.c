#include "shell.h"
/**
 * str_tok - tokenizes an input string
 * @string: the input sting
 * @delim: a delimiter char or char ie where to break up the string
 * Return: a pointer to the char token
 */
char *str_tok(char *string, const char *delim)
{
	static char *buffer;
	char *token_start;
	int token_len;

	if (string != NULL)
		buffer = string;

	if (buffer == NULL || *buffer == '\0')
		return (NULL);

	token_start = buffer;

	token_len = strcspn(buffer, delim);
	buffer += token_len;

	if (*buffer != '\0')
	{
		*buffer = '\0';
		buffer++;
	}

	if (*token_start == '\0')
	{
		return (str_tok(NULL, delim));
	}

	return (token_start);
}
