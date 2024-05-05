NAME = myshell
SRC = ft_build.c ft_execute.c ft_launch.c ft_loop.c ft_read_line.c ft_split_line.c myshell.c
OBJS = ${SRC:.c=.o}
CC = cc
CFLAGS = -Wall -Wextra -Werror
HEADER = myshell.h

all: ${NAME}

${NAME}: ${OBJS} ${HEADER}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
	rm -f ${OBJS} ${NAME}

re: clean all

.PHONY: clean all re
