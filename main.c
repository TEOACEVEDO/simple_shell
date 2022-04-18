#include "main.h"

int main(int argc, char **argv)
{
	if (isatty(STDIN_FILENO) == 1)
		prompt_interactivo();
	else
		prompt_no_interactivo(argc, argv);
	return (0);
}
