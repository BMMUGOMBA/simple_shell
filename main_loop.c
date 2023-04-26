#include "main.h"

/**
 * main_loop - main executing loop
 * @copy_env: environment varible
*/
void main_loop(char *copy_env[])
{
char *line;
char **args;
int status;
char *builtin_str[] = {
"cd",
"exit"
};

do {
printf("$");
line = get_input();
args = input_passer(line);
status = sys_execute(args, copy_env, builtin_str);

free(line);
free(args);
} while (status);
}
