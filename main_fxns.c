#include "main.h"


/**
 * _launch - Execute command and  flags
 * @argc: The issued command
 * @flag: Flags out if the command was fully written or needs pathfinding
 * @mode: Flag to select the mode, interactive or inninterative
 * Return: Returns a status, 1 to continue and 0 to stop
**/
int _launch(char **argc, int *flag, int mode)
{
	pid_t pid;
	int status;
	int builtstatus = 0;
	int k = 0;
	int flagfinder = 0;

	if (argc == NULL)
		return (1);
	builtstatus = sys_inbuilt(argc);
	if (builtstatus < 2)
		return (builtstatus);
	for (k = 0; *(argc[0] + k) != '\0'; k++)
	{
		if (*(argc[0] + k) == '/')
		{
			flagfinder = 1;
			break;
		}
	}
	if (flagfinder == 0)
	{
		argc[0] = _getlocation(argc[0], mode);
		*flag = 1;
	}
	pid = fork();
	if (pid == 0)
	{
		if (execve(argc[0], argc, environ) == -1)
		{
			perror("ERROR: Couldn't execute program");
			free(argc[0]);
			free(argc);
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
		perror("ERROR: Child couldn't be created");
	else
		wait(&status);
return (1);
}


/**
 * _passinput - passes input into * into char **
 * @line_buf: pointer to be splited
 * Return: double pointer with split pointer
 */
char **_passinput(char *line_buf)
{
	char **args = NULL;
	int i = 0;
	char *token = NULL;

	if (line_buf == NULL)
		return (NULL);

	args = (char **)malloc(sizeof(char *) * 1024);
	if (args == NULL)
		return (NULL);

	token = _strtok(line_buf, "\t\r\n ");
	while (token != NULL)
	{
		args[i] = token;
		i++;
		token = _strtok(NULL, "\t\r\n ");
	}

	args[i] = NULL;
	free(token);
	return (args);
}


/**
 *_strcmp_path - program thisgs
 *Result: always return 0
 *@s1: variabl
 *@s2: source
 *Return: value depending on function
 */
int _strcmp_path(char *s1, char *s2)
{
	int i = 0;
	int c = 1;
	int resultado = 0;

	while (s1[i] != '\0' && s2[i] != '\0' && c < 5)
	{
		resultado = s1[i] - s2[i];
		if (resultado == 0)
			i++;
		else
			c++;
	}

return (resultado);
}


/**
 *  _getlocation - Searches sexecution path of command.
 * @command: Command issued by the user
 * @mode:Flag to select the mode, interactive or inninterative
 * Return: Returns the unconcatenated path for execution
**/
