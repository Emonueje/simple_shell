#include "shell.h"

int check_cmd(char *str)
{
	int k;
	for (k = 0; str[k] != '\0'; k++)
	{
		if (str[k] == '/')
			return (0);
	}
	return (1);
}
/**
 * get_full_path - loops through the path env
 * gets each path_dir, addeds the cmd passed and checks if a full path;
 * @cmd: the cmd passed in to be refined to full path
 *
 * Return: returns a pointer to the refined cmd full path
 */
char *get_full_path(char **cmd)
{
	char *path, *path_copy, *dir, *full_path;
	int dir_len, new_cmd_len;
	struct stat st_buffer;

	path = _getenv("PATH");
	if (path == NULL)
	{
		perror("PATH");
		return (NULL);
	}
	path_copy = strdup(path);
	if (path_copy == NULL)
		return (NULL);
	dir = strtok(path_copy, ":\r\n\a");
	while (dir != NULL)
	{
		dir_len = strlen(dir);
		new_cmd_len = dir_len + strlen(cmd[0]) + 2;
		full_path = malloc(sizeof(char) * new_cmd_len);
		if (full_path == NULL)
		{
			free(path_copy);
			return (NULL);
		}
		snprintf(full_path, new_cmd_len, "%s/%s", dir, cmd[0]);
		if (stat(full_path, &st_buffer) == 0 && check_cmd(cmd[0]) != 0)
		{
			free(path_copy);
			return (full_path);
		}
		free(full_path);
		dir = strtok(NULL, ":\r\n\a");
	}
	free(path_copy);
	return (NULL);
}
