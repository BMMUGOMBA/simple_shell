#include "main.h"

/**
 * sys_launch - starts the main process
 * @args: args
 * Return: 1 or success or failure
*/
int sys_launch(char **args)
{
pid_t pid;
int status;
char *command = NULL, *actual_command = NULL;

pid = fork();
if (pid == 0)
{

if (args)
{
/* get the command */
command = args[0];

/* generate the path to this command before passing it to execve */
actual_command = get_location(command);

/* execute the actual command with execve */
if (execve(actual_command, args, NULL) == -1)
{
perror("Error:");
}
}
exit(EXIT_FAILURE);
}
else if (pid < 0)
{
perror("lsh");
}
else
{
do {
waitpid(pid, &status, WUNTRACED);
} while (!WIFEXITED(status) && !WIFSIGNALED(status));
}

return (1);
}

/**
* sys_execute -Execute shell built-in or launch program.
* Null terminated list of arguments.
* @args: Argument 1
* @copy_env: environment argument
* @builtin_str: ag
* Return: 1 if the shell should continue running, 0 if it should terminate
*/
int sys_execute(char **args, char *copy_env[], char *builtin_str[])
{
int i;

if (args[0] == NULL)
{
return (1);
}

if (strcmp(args[0], "env") == 0)
{

printenv(copy_env);
return (1);
}

for (i = 0; i < sys_num_builtins(); i++)
{
if (strcmp(args[0], builtin_str[i]) == 0)
{
return ((*builtin_func[i])(args));
}
}

return (sys_launch(args));
}
/**
* get_input - read input
* Return: line
*/
char *get_input(void)
{
#ifdef LSH_USE_STD_GETLINE
char *line = NULL;
ssize_t bufsize = 0;
if (getline(&line, &bufsize, stdin) == -1)
if (feof(stdin))
{
exit(EXIT_SUCCESS);
}
else
{
perror("lsh: getline\n");
exit(EXIT_FAILURE);
}
return (line);
}
/**
 * get_input2 - continues input 1
 * line over 40 lines
 * @line: input line
 * Return: 1 or 0
*/
char *get_input2(char *line)
{
#else
#define LSH_RL_BUFSIZE 1024
int bufsize = LSH_RL_BUFSIZE;
int position = 0;
char *buffer = malloc(sizeof(char) * bufsize);
int c;
if (!buffer)
{
fprintf(stderr, "lsh: allocation error\n");
exit(EXIT_FAILURE);
}
while (1)
{
c = getchar();
if (c == EOF)
{
exit(EXIT_SUCCESS);
}
else if (c == '\n')
{
buffer[position] = '\0';
return (buffer);
}
else
{
buffer[position] = c;
}
position++;
if (position >= bufsize)
{
bufsize += LSH_RL_BUFSIZE;
buffer = realloc(buffer, bufsize);
if (!buffer)
{
fprintf(stderr, "lsh: allocation error\n");
exit(EXIT_FAILURE);
}
}
}
}
#endif
