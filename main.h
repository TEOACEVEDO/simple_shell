#ifndef MAIN_H
#define MAIN_H

/* lIBRERIAS */
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <stddef.h>
#include <errno.h>
/* PROTOTYPES */

/*Aux functions*/
int tokener(char *str);
int fork_hijo(char *camino, char **tokenizador);

#endif
