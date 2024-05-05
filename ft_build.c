#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h> // Adicionado para a função mkdir

#include "myshell.h"

int lsh_cd(char **args);
int lsh_help(char **args);
int lsh_exit(char **args);
int lsh_mkdir(char **args); // Modificado para retornar int
int lsh_clear(char **args); // Modificado para retornar int

const char *builtin_str[] = {
    "cd",
    "help",
    "exit",
    "mkdir",
    "clear"
};

int (*builtin_func[])(char **) = {
    &lsh_cd,
    &lsh_help,
    &lsh_exit,
    &lsh_mkdir,
    &lsh_clear
};

int lsh_num_builtins() {
  return sizeof(builtin_str) / sizeof(char *);
}

int lsh_mkdir(char **args) { // Modificado para retornar int
    if (args[1] == NULL) {
        fprintf(stderr, "lsh: missing argument to mkdir\n");
        return 1; // Retorne um valor para indicar que houve um erro
    } else {
        if (mkdir(args[1], 0777) != 0) {
            perror("lsh");
            return 1; // Retorne um valor para indicar que houve um erro
        }
    }
    return 0; // Retorne 0 para indicar sucesso
}

int lsh_clear(char **args) { // Modificado para retornar int
    printf("\033[H\033[J");
    return 1; // Retorne um valor para indicar que a operação foi bem-sucedida
}

int lsh_cd(char **args)
{
  if (args[1] == NULL) {
    fprintf(stderr, "lsh: expected argument to \"cd\"\n");
  } else {
    if (chdir(args[1]) != 0) {
      perror("lsh");
    }
  }
  return 1;
}

int lsh_help(char **args)
{
  (void)args;
  int i;
  printf("Myshell Kayke\n");
  printf("Type program names and arguments, and hit enter.\n");
  printf("The following are built in:\n");

  for (i = 0; i < lsh_num_builtins(); i++) {
    printf("  %s\n", builtin_str[i]);
  }

  printf("Use the man command for information on other programs.\n");
  return 1;
}

int lsh_exit(char **args)
{
  (void)args;
  return 0;
}
