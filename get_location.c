#include "main.h"

/**
 * get_location - gets the path for env variables
 * @command: input
 * Return: get
*/
char *get_location(char *command)
{
char *env, *env_copy, *env_token, *file_env;
int cmd_len, dir_len;
struct stat buffer;

env = getenv("PATH");
if (env)
{
env_copy = strdup(env);
cmd_len = strlen(command);
env_token = strtok(env_copy, ":");
while (env_token != NULL)
{
dir_len = strlen(env_token);
file_env = malloc(cmd_len + dir_len + 2);
strcpy(file_env, env_token);
strcat(file_env, "/");
strcat(file_env, command);
strcat(file_env, "\0");
if (stat(file_env, &buffer) == 0)
{
free(env_copy);
return (file_env);
}
else
{
free(file_env);
env_token = strtok(NULL, ":");

}
}
free(env_copy);
if (stat(command, &buffer) == 0)
{
return (command);
}
return (NULL);
}
return (NULL);

