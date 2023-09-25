# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: string <string>                            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/25 14:11:34 by string            #+#    #+#              #
#    Updated: 2023/09/25 14:34:19 by string           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_SRV = server.c 
SRC_CLT = client.c utils.c
BONUS_SRV = server_bonus.c
BONUS_CLT = client_bonus.c utils_bonus.c


SRV_OBJS = ${SRC_SRV:.c=.o}
CLT_OBJS = ${SRC_CLT:.c=.o}
SRV_BONUS_OBJS = ${BONUS_SRV:.c=.o}
CLT_BONUS_OBJS = ${BONUS_CLT:.c=.o}

OBJS_NAME_SRV = server
OBJS_NAME_CLT = client
BONUS_OBJS_NAME_SRV = server_bonus
BONUS_OBJS_NAME_CLT = client_bonus

CC = cc
FLAGS = -Wall -Wextra -Werror

all: $(OBJS_NAME_SRV) $(OBJS_NAME_CLT)

${OBJS_NAME_SRV}: ${SRV_OBJS}
${OBJS_NAME_CLT}: ${CLT_OBJS}

${BONUS_OBJS_NAME_SRV}: ${SRV_BONUS_OBJS}
${BONUS_OBJS_NAME_CLT}: ${CLT_BONUS_OBJS}

%.c%.o:
	$(CC) $(FLAGS) $< -o $(<:.c=.o)

$(OBJS_NAME_SRV):
	$(CC) $(FLAGS) -c $(SRC_SRV)
	$(CC) $(FLAGS) -o $@ $(SRC_SRV)
$(OBJS_NAME_CLT):
	$(CC) $(FLAGS) -c $(SRC_CLT)
	$(CC) $(FLAGS) -o $@ $(SRC_CLT)
	
$(BONUS_OBJS_NAME_SRV):
	$(CC) $(FLAGS) -c $(BONUS_SRV)
	$(CC) $(FLAGS) -o $@ $(SRV_BONUS_OBJS)
$(BONUS_OBJS_NAME_CLT):
	$(CC) $(FLAGS) -c $(BONUS_CLT)
	$(CC) $(FLAGS) -o $@ $(CLT_BONUS_OBJS)


bonus: $(BONUS_OBJS_NAME_SRV) $(BONUS_OBJS_NAME_CLT)

clean:
	rm -rf $(SRV_OBJS) $(CLT_OBJS) $(SRV_BONUS_OBJS) $(CLT_BONUS_OBJS)

fclean: clean
	rm -f $(OBJS_NAME_SRV) $(OBJS_NAME_CLT) $(BONUS_OBJS_NAME_SRV) $(BONUS_OBJS_NAME_CLT)

re: clean all

bonus_re: fclean bonus

.PHONY: all clean fclean re bonus bonus_re
