#include "myshell.h"

int lsh_cd(char **args);
int lsh_help(char **args);
int lsh_exit(char **args);
int lsh_clear(char **args);
int lsh_pwd(char  **args);

char  *my_directory = NULL;
char wd[1000];

const char *builtin_str[] = {
    "cd",
    "help",
    "exit",
    "clear",
    "mkdir",
    "pwd",
    };

int (*builtin_func[])(char **) = {
    &lsh_cd,
    &lsh_help,
    &lsh_exit,
    &lsh_clear,
    &lsh_mkdir,
    &lsh_pwd
    };

int lsh_pwd(char **args)
{
  (void)args;
  if (args[1] != NULL)
  {
    fprintf(stderr, "minishell: comando mkdir não recebe argumento\n");
    return 1;
  }
  printf("%s\n", getcwd(wd, sizeof(wd)));
  return (1);
}

int lsh_cd(char **args)
{
  if (args[1] == NULL)
  {
    fprintf(stderr, "minishell: argumento faltando para\"cd\"\n");
    return (1);
  }

  char *new_dir = args[1];

  if (chdir(new_dir) != 0)
  {
    perror("cd");
  }
  else
  {
    free(my_directory);
    my_directory = strdup(new_dir);
  }
  return 1;
}

int lsh_num_builtins()
{
  return sizeof(builtin_str) / sizeof(char *);
}

int lsh_mkdir(char **args)
{
  if (args[1] == NULL)
  {
    fprintf(stderr, "minishell: argumento faltando para mkdir\n");
    return 1;
  }
  if (mkdir(args[1], 0777) != 0)
  {
    fprintf(stderr, "minishell: erro ao criar diretório\n");
    return 1;
  }
  return 1;
}

int lsh_clear(char **args)
{
  (void)args;
  printf("\033[2J\033[H");
  /*
  Explicação desse regex:
  \033 e um char de escape ASCII, Usado para iniciar uma sequência de controle
  [2J E a sequência de controle J = (clear entire display) [ = inicio do comando; 2 = limpar toda tela
  [H mover o cursor para canto superior esquerdo tela
  */
  return (1);
}

int lsh_help(char **args)
{
  (void)args;
  int i;
  printf("Myshell Kayke\n");
  printf("Lista de comandos:\n");

  for (i = 0; i < lsh_num_builtins(); i++)
  {
    printf("  %s\n", builtin_str[i]);
  }
  return 1;
}

int lsh_exit(char **args)
{
  (void)args;
  return 0;
}