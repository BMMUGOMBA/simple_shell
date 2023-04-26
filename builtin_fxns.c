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
