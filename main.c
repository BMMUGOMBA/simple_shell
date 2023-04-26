#include "main.h"

/**
 * main - main function start
 * @argc: param
 * @argv: agrv param
 * @envp: envp param
 * Return: EXIT_SUCCESS
 */
int main(int argc, char *argv[], char *envp[])
{
int i = 0;

	char *copy_env[100];
	int a;

	a = 0;

	a = a + argc;
	argc = 0;
	argv[1] = 0;
	while (envp[i] != NULL)
	{
    /*printf("%s\n", envp[i]);*/
	copy_env[i] = envp[i];
	argv[2] = copy_env[1];
	i++;
	}

	main_loop(copy_env);


	return (EXIT_SUCCESS);
}
