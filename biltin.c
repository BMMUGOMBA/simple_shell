#include "main.h"


int (*builtin_func[]) (char **) = {
&sys_chdir,
&sys_exit,
};


/**
* sys_num_builtins - system builtin fxns
* Return: return hshs
*/
int sys_num_builtins(void)
{
return (sizeof(builtin_str) / sizeof(char *));
}
