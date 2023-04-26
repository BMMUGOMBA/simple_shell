#ifndef MAIN_H
#define MAIN_H
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>



/*
* Function Declarations for shell commands:
*/
int sys_chdir(char **args);
int sys_help(void);
int sys_exit(char **args);
int printenv(char *copy_env[]);
char *get_location(char *command);
int sys_launch(char **args);
int sys_execute(char **args, char *copy_env[], char *builtin_str[]);
char *get_input(void);
char **input_passer(char *line);
void main_loop(char *copy_env[]);
char *builtin_str[2];
int (*builtin_func[2]) (char **);
int sys_num_builtins(void);


#endif /* MAIN_H */
