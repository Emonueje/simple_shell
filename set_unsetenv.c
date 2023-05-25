#include "shell.h"

/**
 * sh_setenv - sets an environmental variable
 * @cmd: the command array
 * @inp: included this cause the builtin array
 * aint gonna like it if i didnt, it void tho
 * Return: 0 if all good, 1 if nah
 */

int sh_setenv(char **cmd, char *inp)
{
	/* Extract name and value from cmd array */
	char *name, *value;

	(void)inp;

	name = cmd[1];
	value = cmd[2];

	/* Check if name and value are provided */
	if (name == NULL || value == NULL)
	{
		fprintf(stderr, "Usage: setenv <name> <value>\n");
	}

	/* Set the environment variable */
	if (setenv(name, value, 1) != 0)
	{
		fprintf(stderr, "Failed to set environment variable\n");
	}

	return (1);
}

/**
 * sh_unsetenv - sets an environmental variable
 * @cmd: the command array
 * @inp: included this cause the builtin array
 * aint gonna like it if i didnt, it void tho
 * Return: 0 if all good, 1 if nah
 */

int sh_unsetenv(char **cmd, char *inp)
{
	 /* Extract name from cmd array */
	char *name;

	(void)inp;

	name = cmd[1];

	/* Check if name is provided */
	if (name == NULL)
	{
		fprintf(stderr, "Usage: unsetenv <name>\n");
	}

	/* Unset the environment variable */
	if (unsetenv(name) != 0)
	{
		fprintf(stderr, "Failed to unset environment variable\n");
	}

	return (1);
}

