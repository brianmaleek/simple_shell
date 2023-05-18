#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

/*for output*/
int _putchar(char c);
int _puts(char *str);


/* for  reading  arguments*/
char *read_args_stream(void);
char *read_args(void);



#endif