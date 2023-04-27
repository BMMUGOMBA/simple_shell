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
