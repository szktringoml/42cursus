# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: string <string>                            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/18 16:39:58 by string            #+#    #+#              #
#    Updated: 2023/09/18 16:40:01 by string           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC	=	push_swap.c \
		operations.c \
		sort.c \
		gen_a_stack.c
OBJS = ${SRC:.c=.o}

LIBFT = ../libft/libft.a
NAME = push_swap
CC = cc
CFLAG = -Wall -Wextra -Werror

${NAME}: all ;
	
#dummy-tergetの宣言
.PHONY:	all clean fclean re

#全てのソースコードをコンパイルする
all: ${OBJS}
	${CC} ${CFLAG} -o ${NAME} ${OBJS} ${LIBFT}

#コンパイル時に生成したオブジェクトファイルを削除
clean:
	rm -rf ${OBJS}

#clean+コンパイルした時に生成された実行ファイルと静的ライブラリを削除
fclean: clean
	rm -rf ${NAME}

re: fclean all ;
