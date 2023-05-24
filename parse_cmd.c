#include "shell.h"

/**
 * error_av - little program to help me
 * utilize function lines so betty can :)
 * @av: pointer to pointer to chars
 *
 * Return: NULL if error occurs or the pointer
 */
char **error_av(char **av)
{
	if (av == NULL)
	{
		perror("./hsh: allocation error\n");
		return (NULL);
	}
	return (av);
}

/**
 * _parse_cmd - parses commands into strings
 * consisting of executable cmd args and other args
 * that would be used by our built in functions or the
 * execve function to excute the command inputted by the user
 * @inp_cmd: input commands gotten after reading
 * from the input stream
 * Return: returns an pointer to a pointer of chars
 * and on error NULL is returned;
 */
char **_parse_cmd(char *inp_cmd)
{
	char **av, *token; /* av refers to tokens that stores each token */
	char *delim = " \t\r\n\a";
	int i = 0, av_size = 64;

	av = malloc(sizeof(char *) * av_size);
	if (error_av(av) == NULL)
		return (NULL);
	token = strtok(inp_cmd, delim);
	while (token != NULL)
	{
		av[i] = token;
		i++;
		if (i >= av_size)
		{
			av_size += 64;
			av = _realloc(av, (av_size - 64), av_size * sizeof(char *));
			if (error_av(av) == NULL)
			return (NULL);
		}
		token = strtok(NULL, delim);
	}
	av[i] = NULL;
	return (av);
}
