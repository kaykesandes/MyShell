#include "myshell.h"

void    ft_print_prompt()
{
    char wd[1000];
    printf("%s$ ", getcwd(wd, sizeof(wd)));
    fflush(stdout);
}

void ft_loop(void)
{
    char    *line;
    char    **args;
    int     status;

    do{
        ft_print_prompt();
        
        line = ft_read_line();
        args = ft_split_line(line);
        status = ft_execute(args);

        free(line);
        free(args);
    }while (status);
}