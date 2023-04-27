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

/**
 * _strtok - tokenizes a string
 * @s: string to be tokenized
 * @deli: delimitator for the tokens
 * Return: pointer to each token
 */
char *_strtok(char *s, char *deli)
{
	int c;
	static char *str;

	if (!s)
		s = str;
	c = *s++;
	while (strchr(deli, c))
	{
		if (c == 0)
			return (0);
		c = *s++;
	}
	--s;
	str = s + strcspn(s, deli);
	if (*str != 0)
	{
		*str = 0;
		str++;
	}
	return (s);
}

