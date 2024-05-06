#include "myshell.h"

void    ft_print_prompt()
{
    printf("%s> ", my_directory);
    fflush(stdout);
}

void ft_loop(void)
{
    char    *line;
    char    **args;
    int     status;

    char    *init_dir = getcwd(NULL, 0);
    my_directory = strdup(init_dir);
    free(init_dir);

    do{
        ft_print_prompt();
        
        line = ft_read_line();
        args = ft_split_line(line);


        if(args[0] != NULL && strcmp(args[0], "cd") == 0)
            lsh_cd(args);
        else
            status = ft_execute(args);

        free(line);
        free(args);
    }while (status);
}