#ifndef SHELL_H
#define SHELL_H

/* definitions of needed size */
#define BUFFER_SIZE (size_t)128
#define MAX_PATH_LENGTH 64

/* define globale variables */
extern char **environ;

/* needed header files */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>
#include <ctype.h>

/* prototype strtok implementation*/
char *str_tok(char *string, const char *delim);

/* definition of utility functions that reads input from command line */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
void *_realloc(void *ptr, size_t old_size, size_t new_size);
int sh_getc(FILE *stream);

/* definition of utility functions that execute input commands if valid */
char **_parse_cmd(char *inp_cmd);
int execute_cmd(char **cmd_arg, char *prog_name);
int _process_cmd(char **cmd, char *inp, char *prog_name);
char *get_full_path(char **cmd);
int _putchar(char c);

/* definition of builtin commands */
int sh_cd(char **cmd, char *inp);
int sh_exit(char **cmd, char *inp);
int sh_env(char **cmd, char *inp);

/* definition of funcition used for accessing the environment */
char *_getenv(const char *env_name);

#endif
