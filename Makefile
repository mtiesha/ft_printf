NAME = libftprintf.a

SRCS_UTILS = ft_src_dics.c ft_src_hexp.c

SRCS = ft_printf.c ${SRCS_UTILS}

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror

LIB = ar rcs

OBJ = ${SRCS:.c=.o}

CC = gcc

all : ${NAME}

${NAME} : ${OBJ}
	${LIB} ${NAME} ${OBJ}

%.o : %.c Makefile ft_printf.h
	${CC} ${CFLAGS} -I. -c $< -o $@

clean :
	${RM} ${OBJ}

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY : clean fclean all re
