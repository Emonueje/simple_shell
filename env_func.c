#include "shell.h"

/**
 * _getenv - searches the environment list
 * to find the environment variable env_name
 *
 * @env_name: the name of the env to be returned
 *
 * Return: a pointer to the environment
 * or NULL if there is no match
 */
char *_getenv(const char *env_name)
{
	size_t len;
	char **env = environ;
	/* get lenght of the name input */
	len = strlen(env_name);
	/* loop to compare name with all env_vars and get the one requested */
	while (*env != NULL)
	{
		if ((strncmp(*env, env_name, len)) == 0 && (*env)[len] == '=')
		{
			return (&((*env)[len + 1]));
		}
		env++;
	}
	/* if no env_var is the same name return Null */
	return (NULL);
}
