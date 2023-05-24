#include "shell.h"

/**
 * get_full_path - gets the array of path dir of
 * the environ variable
 * @path: the original path
 * @path_copy: path copy
 * Return: an array of all path_dir
 */
char **get_path_tokens(char *path, char *path_copy)
{
	char **path_tokens, *token; 
	int token_size = 128, i = 0;

	path_tokens = malloc(sizeof(char *) * token_size);
	if (!path_tokens)
	{
		perror("./hsh: allocation error\n");
		return (NULL);
	}
	strcpy(path_copy, path);
	token = strtok(path_copy, ":\r\n\a");
	while(token != NULL)
	{
		path_tokens[i] = token;
		i++;
		if (i >= token_size)
		{
			token_size += 128;
			path_tokens = _realloc(path_tokens, token_size - 128, token_size *sizeof(char *));
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
