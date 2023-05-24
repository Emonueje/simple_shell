#include "shell.h"

/**
 * sh_cd - changes the working directory
 * to the specified working directory
 * @cmd: the working dir to change to
 * @inp: non useful function
 * Return: On sucess, 0 is returned.
 * On error, -1 is returned and errno is
 * set appropriately
 */
int sh_cd(char **cmd, char *inp)
{
	(void)inp;
	if (cmd[1] == NULL)
	{
		if (chdir(_getenv("HOME")) != 0)
			perror("chdir");
	}
	else
	{
		if (chdir(cmd[1]) != 0)
		{
			perror("chdir");
		}
	}
	return (0);
}

/**
 * check_exit_val - checks if input exit value
 * contains only numbers
 * @exit_str: input exit value
 * Return: 0 on success and -1 on failure
 */
int check_exit_val(char *exit_str)
{
	int i;

	i = 0;
	while (exit_str[i] != '\0')
	{
		if (isdigit(exit_str[i]))
			i++;
		else
			return (-1);
	}
	return (0);
}

/**
 * sh_exit - builtin exit function
 * @cmd: input array of cmd
 * @inp: to be freed
 * Return: function exits on success
 * or 0 is returned
 */
int sh_exit(char **cmd, char *inp)
{
	int exit_val = 0;

	if (cmd[1] == NULL)
	{
		free(cmd);
		free(inp);
		exit(EXIT_SUCCESS);
	}
	else
	{
		if (check_exit_val(cmd[1]) == 0)
		{
			exit_val = atoi(cmd[1]);
			if (exit_val >= 256)
			{
				free(cmd);
				free(inp);
				exit (exit_val - 256);
			}
			if (exit_val < 0)
				return (1);
			free(cmd);
			free(inp);
			exit(exit_val);
		}
		else
			dprintf(2, "Illegal number: %s\n", cmd[1]);
	}
	return (0);

}
/**
 * sh_env - builtin env function
 * it prints the env to the stdout
 * @cmd: input array of commands
 * @inp: input to be freed
 * Return: returns 0 on success
 */
int sh_env(char **cmd, char *inp)
{
	int i;

	(void)inp, (void)cmd;
	for (i = 0; environ[i] != NULL; i++)
	{
		dprintf(STDOUT_FILENO, "%s\n", environ[i]);
	}
	return (0);
}
