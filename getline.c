#include "shell.h"

/**
 * alloc_error - checks if mem alloc is successfull
 * @str: input string to check its return value
 *
 * Return: the expected output
 */
char *alloc_error(char *str)
{
	if (str == NULL)
	{
		free(str);
		return (NULL);
	}
	return (str);
}
/**
 * _getline - imitates the getline function
 * reads a line from the file stream passed into it
 * @line_ptr: buffer used to hold to hold line read from
 * the stream
 * @buffer_size: the maximum no. of input that can be read
 * if n is to small more space is reallocated
 * @stream: file stream from which reading takes place from
 * Return: returns a ssize_t value of no. of characters read
 */
ssize_t _getline(char **line_ptr, size_t *buffer_size, FILE *stream)
{
	int c;
	size_t new_buffer_size, i = 0;

	if ((*line_ptr) == NULL) /* checks if str is NULL to allocate memory for it */
	{
		if ((*buffer_size) <= 0) /* checks if the buffer_size is 0 */
			*buffer_size = BUFFER_SIZE;
		(*line_ptr) = malloc(sizeof(char) * (*buffer_size));
		if (alloc_error(*line_ptr) == NULL)
			return (-1);
	}
	while (1)
	{
		fflush(stdout);
		c = sh_getc(stream);
		if (c == '\n' || c == EOF)
		{
			(*line_ptr)[i] = '\0';
			if (c == EOF)
			{
				return (-1);
			}
			else
			{
				return (i + 1);
			}

		}
		(*line_ptr)[i] = c;
		i++;
		if (i >= (*buffer_size)) /* checks if buffer_size is too small */
		{
			new_buffer_size = (*buffer_size) + 3;
			(*line_ptr) = _realloc((*line_ptr), (*buffer_size), new_buffer_size);
			if (alloc_error((*line_ptr)) == NULL)
				return (-1);
			(*buffer_size) = new_buffer_size;
		}
	}
	return (i);
}

/**
 * sh_getc - reads the next character from  the stream
 * and returns it as an unsigned char cast to an int, or EOF
 * end of file or error
 * @stream: the input stream to read characters from
 * Return: the character read casted to an int, or EOF on end of file
 */
int sh_getc(FILE *stream)
{
	char char_buffer[1];
	char *char_read;
	int status;

	/* using the allowed read function  get char from the stdinput stream */
	status = read(fileno(stream), char_buffer, 1);
	if (status > 0) /* checks if character was read */
	{
		char_read = char_buffer;
		return (*char_read);
	}
	if (status == -1)
		return (0);
	return (EOF);
}
