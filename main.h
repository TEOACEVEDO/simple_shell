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

/* Especial Macros */
extern char **environ;

/* PROTOTYPES */
int prompt_interactivo(void);
int prompt_no_interactivo(int argc, char **argv);

/*Aux functions*/
char **tokener(char *str, char *delim);
int fork_hijo(char *camino, char **arguments, char **environ);
int counter(char *string);
void free_tokens(char **token);
char *search_alias(char **token);
char *_strdup(const char *s);
char *_strncmp(char *path, char *match, size_t n);
char *espace(char *path, char *alias);

/*Builtins*/
int (*get_function(char *str))();
int environment(void);
int Exit_shell(void);

/*structures*/
typedef struct built_in
{
	char *comand;
	int (*f)();
} Built_in;

#endif
