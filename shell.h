#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TOK_BUFSIZE 64
#define DELIMITER " \t\r\n\a"

/*helper functions*/
int _putchar(char c);
void _puts(char *str);
size_t _strlen(char *str);

/*builtin functions*/
int exec_cd(char **args);
int exec_env(char **args);
int exec_exit(char **args);
int exec_help(char **args);

/* for  reading  arguments*/
char *read_args_stream(void);
char *read_args(void);

char **split_to_tokens(char *tok);


#endif
