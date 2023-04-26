#include "main.h"

#define LSH_TOK_BUFSIZE 64
#define LSH_TOK_DELIM " \t\r\n\a"

/**
 * input_passer - slpit input into tokens
 * @line: line input
 * Return: 1 or 0
*/
char **input_passer(char *line)
{
int bufsize = LSH_TOK_BUFSIZE, position = 0;
char **tokens = malloc(bufsize * sizeof(char *));
char *token, **tokens_backup;

if (!tokens)
{
fprintf(stderr, "lsh: allocation error\n");
exit(EXIT_FAILURE);
}
