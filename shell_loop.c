#include "shell.h"

/**
 * get_error - litle function to handle
 * line management and get the error status
 * of _getline function
 * @nchars: the number of characters expected
 * @inp_cmd: command to be freed
 * to be returned by the _getline function
 * Return: 0 in a case of no errors and -1
 */
int get_error(ssize_t nchars, char *inp_cmd)
{
	if (nchars == -1)
	{
		free(inp_cmd);
		return (-1);
	}
	return (0);
}
/**
 * handle_sigint - used to handle to the SIGINT signal
 * It returns the control of program to the loop.
 * so that when the user enters ctrl_c a new line with a
 * promt is printed
 * @sig: used by the signal function
 * to compare the SIGNINT value received
 * Return: Void functions have no return value
 */
void handle_sigint(int sig)
{
	(void)sig;
	_putchar('\n');
	printf("cisfun~$ ");
	fflush(stdout);

}
/**
 * main - entry point of the shell
 *
 * prints a prompt
 * get users input
 * parse the input and array it
 * execute the input and print
 * and print the prompt again
 * Return: 0 On success and -1 on Error
 */
int main(int ac, char **av)
{
	char **cmd_arg;
	char *inp_cmd = NULL;
	size_t len = 0;
	ssize_t nchars;
	int testing;

	(void)ac;
	signal(SIGINT, handle_sigint);
	while (1)
	{
		fflush(stdout);
		if (isatty(STDIN_FILENO) != 0)
			printf("cisfun~$ ");
		nchars = _getline(&inp_cmd, &len, stdin);
		if (get_error(nchars, inp_cmd) == -1)
			return (-1);
		cmd_arg = _parse_cmd(inp_cmd);
		if (cmd_arg == NULL)
		{
			free(cmd_arg);
			return (-1);
		}
		if (cmd_arg[0] != NULL)
		{
			testing = _process_cmd(cmd_arg, inp_cmd, av[0]);
			if (testing == 1)
			{
				free(cmd_arg[0]);
				cmd_arg[0] = NULL;
			}
		}
		free(cmd_arg);
	}
	free(inp_cmd);
	return (0);
}
