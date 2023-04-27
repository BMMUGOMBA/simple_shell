 #include "main.h"

/**
 * _getline - Receives a command typed by the user in the prompt
 * Return: Returns the typed command
**/
char *_getline(void)
{
	/*variable decleration*/
	char *line = NULL;
	size_t len = 0;
	int readline = 0;

	readline = getline(&line, &len, stdin);
	if (readline != -1)
		return (line);
	free(line);
	/*memory freeing*/
	write(1, "\n", 1);
	return (NULL);
}
