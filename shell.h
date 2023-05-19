#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

#define TOK_BUFSIZE 64
#define DELIMITER " \t\r\n\a"
/*for output*/
int _putchar(char c);
void _puts(char *str);


/* for  reading  arguments*/
char *read_args_stream(void);
char *read_args(void);

char **split_to_tokens(char *tok);


#endif
