SRCS = fdf.c \
		../libft/ft_split.c \
		../libft/ft_atoi.c  \
		../getnextline/get_next_line.c \
		../getnextline/get_next_line_utils.c \

OBJS = ${SRCS:.c=.o}

NAME = fdf
CC	= cc
CFLAG = -Wall -Wextra -Werror

${NAME}: all ;

.PHONY: all clean fclean re

all: ${OBJS} ;
	${CC} ${CFLAG} -o ${NAME} ${OBJS}
clean: 
	rm -rf ${OBJS}

fclean: clean
	#rm -rf *.a
	rm -rf ${NAME}

re: fclean all ;
