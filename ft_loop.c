#include "myshell.h"

void ft_loop(void)
{
    char    *line;
    char    **args;
    int     status;


    do{
        printf("> ");
        line = ft_read_line();
        args = ft_split_line(line);
        status = ft_execute(args);

        free(line);
        free(args);
    }while (status);
}