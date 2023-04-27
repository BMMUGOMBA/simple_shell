#ifndef _SHELL_H_
#define _SHELL_H_
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

/*inbuilt*/
void sys_chdir(char **argc);
void print_env(void);
int sys_inbuilt(char **argc);
/*utility fxns*/
void SignalHandler(int error);
void intmodestatus(char *line, char **argc);
/*Functions*/
extern char **environ;
char *_getline(void);
char **_passinput(char *line_buf);
int _launch(char **args, int *flag, int mode);
char *_getlocation(char *command, int mode);
char *_catpath(char **uncatpath, char *command);

/*Utilities*/

int _strcmp_path(char *s1, char *s2);

/*Proto-Functions*/
ssize_t getline(char **lineptr, size_t *n, FILE *stream);

char *_strtok(char *s, char *deli);
#endif
