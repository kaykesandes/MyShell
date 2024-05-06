#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

#ifndef MYSHELL

#define RL_BUFSIZE 1024
#define TOK_BUFSIZE 64
#define TOK_DELIM " \t\r\n\a"
#define TRUE 1
#define IS_POSIX 1
#define _BSD_SOURCE
#else
    #define IS_POSIX 0

#endif

void    ft_loop(void);
void    *ft_read_line(void);
char    **ft_split_line(char *line);
int     ft_launch(char **args);
int     lsh_num_builtins(void);
int     ft_execute(char **args);

int lsh_cd(char **args);
int lsh_help(char **args);
int lsh_exit(char **args);
int lsh_clear(char **args);
int lsh_mkdir(char **args);

extern const char *builtin_str[];
extern int (*builtin_func[])(char **);
