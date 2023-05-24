#include "shell.h"

int (*builtin_func[])(char **, char *) = {
	&sh_cd,
	&sh_exit,
	&sh_env,
};
/**
 * _process_cmd - checks if input cmd is a
 * built in and executes it else calls
 * the execute_cmd function
 *
 * @cmd: user's cmd passed in from the main
 * loop of the shell
 * @inp_cmd: command to be freed
 * @loop_count: for error message
 * @prog_name: for error message
 *
 * Return: 0 on success and -1 on error and errno
 * is set appropriately
 */
int _process_cmd(char **cmd, char *inp_cmd, char *prog_name, int loop_count)
{
	char *builtin_cmd[] = {"cd", "exit", "env"};
	int func_len, i;

	if (cmd == NULL)
		return (-1);
	func_len = sizeof(builtin_cmd) / sizeof(char *);
	for (i = 0; i < func_len; i++)
	{
		if (strcmp(cmd[0], builtin_cmd[i]) == 0)
			return ((*builtin_func[i])(cmd, inp_cmd));
	}
	return (execute_cmd(cmd, prog_name, loop_count));

}

int check_cmd(char *str)
{
	int k;
	for (k = 0; str[k] != 0; k++)
	{
		if (str[k] == '/')
			return (1);
	}
	return (0);
}
/**
 * execute_cmd - executes commands that
 * are not built-ins
 * @cmd: the command to be executed
 * @prog_name: for error message
 * @loop_count: for error message
 *
 * Return: an int indicating if memory
 * was allocated for the cmd or not
 * On error -1 is returned
 */
int execute_cmd(char **cmd, char *prog_name, int loop_count)
{
	pid_t child_pid;
	char **env = environ;
	int status, check_free = 0;
	struct stat cmd_info;

	if (cmd == NULL)
		return (-1);
	if (check_cmd(cmd[0]) == 0)
	{	cmd[0] = get_full_path(cmd);
		check_free = 1;
		if (cmd[0] == NULL)
			check_free = 0;
	}
	if (stat(cmd[0], &cmd_info) == 0)
	{	child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			return (-1);
		}
		if (child_pid == 0)
		{
			if (execve(cmd[0], cmd, env) == -1)
			{
				/* changed error msg */
				dprintf(1, "%s: %d: Permission denied\n", prog_name, loop_count);
				free(cmd[0]);
				free(cmd);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(&status);
		}
	}
	else
		dprintf(1, "%s: %d: Not found\n", prog_name, loop_count); /* here too */
	return (check_free);
}
