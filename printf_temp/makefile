include libft/makefile

SRCS		= src/ft_printf.c \
			  src/ft_generates.c \
				  


BONUS		= bonus_src/ft_printf_bonus.c \
			  bonus_src/ft_generates_bonus.c \

OBJS		= ${SRCS:.c=.o}
BONUS_OBJS	= ${BONUS:.c=.o}
ifdef WITH_BONUS
	SRCS += ${BONUS}
	OBJS += ${BONUS_OBJS}
endif
NAME		= libftprintf.a
LFNAME		= libft/libft.a
RM			= rm -f
CC			= cc
CFLAGS		= -Wall -Wextra -Werror

%.c%.o:
			${CC} ${CFLAGS} $< -o ${<:.c=.o}

${NAME}:	${OBJS} ${LFNAME}
			ar rcs ${NAME} ${OBJS}
bonus:	
	make WITH_BONUS=1 ${NAME}

all:		${NAME}
clean:	
			${RM} ${OBJS} ${BONUS_OBJS} && lfclean
fclean:		clean
			${RM} ${NAME} && lffclean

re:			fclean all lfre

.PHONY: all clean fclean re bonus
