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


char *_getlocation(char *command, int mode)
{
	int i = 0, j = 0, flagcurr = 0;
	char *completepath = NULL, *envcpy = NULL, *token = NULL;
	char **tokens = NULL;

	tokens = (char **)malloc(sizeof(char *) * 1024);
	if (tokens == NULL)
		return (NULL);

	while (environ[i])
	{
		if (_strcmp_path(environ[i], "PATH=") == 0)
			break;
		i++;
	}
	envcpy = malloc(sizeof(char) * strlen(environ[i]) + 1);
	if (envcpy == NULL)
		return (NULL);

	strcpy(envcpy, environ[i]);
	token = _strtok(envcpy, "=\n\r");
	if (environ[i][5] == ':')
		flagcurr = 1;
	while (token != NULL)
	{
		tokens[j] = token;
		token = _strtok(NULL, ":\n\r");
		j++;
	}
	if (flagcurr == 1)
		tokens[0] = "./";

	completepath = _catpath(tokens, command);
	free(tokens);
	free(token);
	free(envcpy);
	if (mode == 0)
		free(command);

return (completepath);
}

/**
 *  _catpath - Concatenates path of command.
 * @uncatpath: Uncocatenated path
 * @command: Command issued by the user
 * Return: Returns the concatenated path for execution
**/
char *_catpath(char **uncatpath, char *command)
{
	int i = 0;
	char *path = NULL;

	path = malloc(sizeof(char) * 1024);
	if (path == NULL)
		return (NULL);

	for (i = 0; i < 1024; i++)
		path[i] = '\0';

	i = 0;
	while (uncatpath[i] != NULL)
	{
		strcpy(path, uncatpath[i]);
		strcat(path, "/");
		strcat(path, command);
		if (access(path, F_OK & X_OK) != -1)
			break;
		i++;
	}
return (path);
}

