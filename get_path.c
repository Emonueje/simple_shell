#include "shell.h"

/**
 * get_path_tokens - gets the array of path dir of
 * the environ variable
 * @path: the original path
 * @path_copy: path copy
 * Return: an array of all path_dir
 */
char **get_path_tokens(char *path, char *path_copy)
{
	char **path_tokens, *token;
	int len = 128, i = 0;

	path_tokens = malloc(sizeof(char *) * len);
	if (!path_tokens)
	{
		perror("./hsh: allocation error\n");
		return (NULL);
	}
	strcpy(path_copy, path);
	token = strtok(path_copy, ":\r\n\a");
	while (token != NULL)
	{
		path_tokens[i] = token;
		i++;
		if (i >= len)
		{
			len += 128;
			path_tokens = _realloc(path_tokens, len - 128, len * sizeof(char *));
			if (!path_tokens)
			{
				perror("./hsh: allocation error\n");
				return (NULL);
			}
		}
		token = strtok(NULL, ":\r\n\a");
	}
	path_tokens[i] = NULL;
	return (path_tokens);
}
