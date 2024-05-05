#include "myshell.h"

void *ft_read_line(void)
{
  int bufTam = RL_BUFSIZE;
  int posicao = 0;
  char *buffer = malloc(sizeof(char) * bufTam);
  int c;

  if (!buffer)
  {
    printf("Erro de alocação memoria \n");
    exit(EXIT_FAILURE);
  }

  while (TRUE)
  {
    c = getchar();

    if (c == EOF || c == '\n')
    {
      buffer[posicao] = '\0';
      return buffer;
    }
    else
      buffer[posicao] = c;

    posicao++;

    if (posicao >= bufTam)
    {
      bufTam += RL_BUFSIZE;
      buffer = realloc(buffer, bufTam);
      if (!buffer)
      {
        printf("Erro de alocação memoria \n");
        exit(EXIT_FAILURE);
      }
    }
  }
}