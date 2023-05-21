#include "shell.h"

/**
 * _putchar - write the input char
 * to the required stream
 * @c: input character to be written to the
 * Return: 0 on success  and on failure errno
 * is set appropriately
 */
int _putchar(char c)
{
	write(STDOUT_FILENO, &c, 1);
	return (0);
}
