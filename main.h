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
int display(int first, char *line);
int searchb(char **token, char *line);
char *ver_access(char **token);

/*Aux functions*/
char **tokener(char *str, char *delim);
int fork_hijo(char *camino, char **arguments, char **environ);
int counter(char *string);
void free_tokens(char **token);
char *search_alias(char **token);
char *_strdup(char *s);
char *_strncmp(char *path, char *match, size_t n);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *espace(char *path, char *alias);
void handler(int signal);

/*Builtins*/
int (*get_function(char *str))();
int environment(void);
int Exit_shell(void);

/*structures*/

/**
*struct built_in - builtin structures.
*@comand: a char with a name of a file.
*@f: a int that call.
*/
typedef struct built_in
{
	char *comand;
	int (*f)();
} Built_in;

#endif
