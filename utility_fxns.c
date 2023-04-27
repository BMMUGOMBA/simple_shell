#include "main.h"

/**
 * SignalHandler - gets Behavior of signals
 * @error: Error ID from signal
**/
void SignalHandler(int error)
{
	switch (error)
	{
	case 2:
		write(1, "\n", 1);
		write(STDOUT_FILENO, "$ ", 2);
		break;
	default:
		write(2, "Issued command \n", 15);
		break;
	}
}
/**
 * intmodestatus -  doesn`t open prompt and executes one time
 * @line: Typed command by user sent to splitline
 * @argc: Splitted command sent or not n
 * Return: 1 if completed 0 if failed
**/
void intmodestatus(char *line, char **argc)
{
	int addr;
	int modeStatus = 1;
	size_t len = 0;

	while (getline(&line, &len, stdin) != EOF)
	{
		argc = _passinput(line);
		if (argc[0] != NULL)
			modeStatus = _launch(argc, &addr, 1);
		if (modeStatus == 0)
			if (addr == 1)
				free(argc[0]);
		free(argc);
	}
	free(line);
}

