#include "main.h"


/**
* printenv - executes the built in functions
* @copy_env: arguments being passed
* Return: (0)
*/

int printenv(char *copy_env[])
{
	int j = 0;

	while (copy_env[j] != NULL)
	{
		printf("%s\n", copy_env[j]);
		j++;
	}
	return (0);
}

/**
 * sys_chdir - function for inbuilt cd
 * @args: arguments
 * Return: 1 or 0
*/
int sys_chdir(char **args)
{
if (args[1] == NULL)
{
if (chdir("/home") != 0)
perror("chdir() to /home failed");
}
else
{
if (chdir(args[1]) != 0)
{
perror("shell");
}
}
return (1);
}



/**
*sys_exit - Builtin command: exit.
*@args: List of args.  Not examined.
*Return: Always returns 0, to terminate execution.
*/
int sys_exit(char **args)
{
	if (args[1] == NULL)
	{
	return (0);
	}
	else
	return (0);
}
