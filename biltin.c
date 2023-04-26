#include "main.h"


int (*builtin_func[]) (char **) = {
&sys_chdir,
&sys_exit,
};
