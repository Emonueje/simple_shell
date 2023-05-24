#include "shell.h"

/**
 * 1alloc_error - helps reduce program lines
 * @new_cmd: the inp to handle
 * Return: On error -1
 */
int alloc_errors(char *new_cmd)
{
	if (!new_cmd)
	{
		perror("./hsh: allocation error\n");
		return (-1);
	}
	return 0;
}

/**
 * 2alloc_error - helps me reduce function lines
 * @new_cmd: address
 * @buffer: to check
 * Return: On error -1
 */
int alloc_err(char *buffer, char *new_cmd)
{
	if (!buffer)
	{
		free(new_cmd);
		perror("./hsh: allocation error\n");
		return (-1);
	}
	return 0;
}
/**
 * free_them1 - frees up allocated memory
 * saves me function lines
 * @mem1: to be freed
 * @mem2: to be freed
 * Return: VOID
 */
void free_them1(char *mem1, char **mem2)
{
	free(mem1);
	free(mem2);
}
/**
 * free_them2 - reduces function lines
 * @mem1: freed
 * @mem2: freed
 * @mem3: freed
 * Return: VOID
 */
void free_them2(char *mem1, char **mem2, char *mem3)
{
	free(mem1);
	free(mem2);
	free(mem3);
}
/**
 * check_cmd - function to process
 * the input command
 * @cmd: the array of input
 * @prog_name: for error messages
 * @loop_count: for error msg
 * @flag: to check if mem was allocated
 * Return: an array of processed input command
 * or NULL on failure
 */
char **_check_cmd(char **cmd, char *prog_name, int loop_count, int *flag)
{
	char *new_cmd, **path_tokens;
	char *path, *path_copy;
	int k, b;

	for (k = 0; *(cmd[0] + k) != '\0'; k++) /* handle the "/" errors */
	{
		if (*(cmd[0] + k) == '/')
			return (cmd);
	}
	new_cmd = malloc(sizeof(char) * MAX_PATH_LENGTH);
	if (alloc_errors(new_cmd) == -1)
		return (NULL);
	path = _getenv("PATH");
	path_copy = malloc(sizeof(char) * (strlen(path) + 1));
	if (alloc_err(path_copy, new_cmd) == -1)
		return (NULL);
	path_tokens = get_path_tokens(path, path_copy);
	if (path_tokens == NULL)
	{
		free(path_copy);
		return (NULL);
	}
	for (b = 0; path_tokens[b] != NULL; b++)
	{
		strcpy(new_cmd, path_tokens[b]);
		if (*new_cmd != '\0')
			strcat(new_cmd, "/");
		else
			strcat(new_cmd, "./");
		strcat(new_cmd, cmd[0]);
		if (access(new_cmd , X_OK) != -1)
		{
			cmd[0] = new_cmd;
			*flag = 1;
			free_them1(path_copy, path_tokens);
			return (cmd);
		}
	}
	free_them2(new_cmd, path_tokens, path_copy);
	dprintf(2, "%s: %d: not found\n", prog_name, loop_count);
	return (NULL);
}
