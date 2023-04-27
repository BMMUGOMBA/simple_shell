#include "main.h"
/**
 * main - Loop for shell
 * if status is 1, the loop goes to the begginning, otherwise, it breaks.
 * Return: void.
**/
int main(void)
{
	char *line = NULL;
	char **argc = NULL;
	int modeStatus = 1;
	int addr = 0;

	signal(SIGINT, SignalHandler);
	if (isatty(STDIN_FILENO) != 1)
		intmodestatus(line, argc);
	else
	{
		do {
			addr = 0;
			write(STDOUT_FILENO, "$ ", 2);
			line = _getline();
			if (line == NULL)
				break;
			argc = _passinput(line);
			if (argc[0] != NULL)
				modeStatus = _launch(argc, &addr, 0);
			if (modeStatus == 0)
				free(line);
			if (addr == 1)
				free(argc[0]);
			else
				if (modeStatus != 0)
					free(line);
			free(argc);
		} while (modeStatus);
	}
	return (0);
}
