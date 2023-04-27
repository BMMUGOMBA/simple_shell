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

void sys_chdir(char **argc)
{
	int j = 0;
	/*counter j*/
	int wrdlen = 0;
	/*argument length*/
	char wrd[1024];

	if (argc[1] == NULL)
		chdir(getenv("HOME"));
	else if (strcmp(argc[1], "-") == 0)
	{
		if (getenv("OLDPWD") == NULL)
			chdir(".");
		else
		{
			chdir(getenv("OLDPWD"));
			getcwd(wrd, sizeof(wrd));
			for (wrdlen = 0; wrd[j] != '\0'; j++)
				wrdlen++;
			wrd[j] = '\n';
			write(1, wrd, wrdlen + 1);
		}
	}
	else
		chdir(argc[1]);
}

/**
 * print_env - Prints environment
 * Return: Void
**/
void print_env(void)
{
	int j = 0, k = 0;

	while (environ[j])
	{
		k = strlen(environ[j]);
		write(STDOUT_FILENO, environ[j], k);
		write(STDOUT_FILENO, "\n", 1);
		j++;
	}
}


