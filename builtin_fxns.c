#include "main.h"

/**
 * sys_inbuilt - Innate commands of the shell
 * @argc: Typed command (built-in)
 * Return: Returns, 0 to break, 1 to continue and 2 for new prompt
**/
int sys_inbuilt(char **argc)
{
	char *builts[] = {"exit", "cd", "env", NULL};
	int j = 0;

	while (builts[j])
	{
		if (strcmp(argc[0], builts[j]) == 0)
			break;
		j++;
	}

	if (j == 0)
	{
		return (0);
	}
	if (j == 1)
	{
		sys_chdir(argc);
		return (1);
	}
	if (j == 2)
	{
		print_env();
		return (1);
	}
	else
		return (2);
}
/**
 * sys_chdir - Change directory
 * @argc: Typed command
 * Return: Void
**/
