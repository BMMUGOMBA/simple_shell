all :
	gcc -Wall -Werror -Wextra -pedantic -g _* shell.c shell.h -o shell
	valgrind --leak-check=full --show-leak-kinds=all --trace-children=yes ./shell
	#gdb set follow-fork-mode mode ./shell
	#./shell
