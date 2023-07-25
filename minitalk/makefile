SRC_SRV = server.c
SRC_CLT = client.c
BONUS_SRV = server_bonus.c
BONUS_CLT = client_bonus.c


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


$(OBJS_NAME_SRV):
	$(CC) $(FLAGS) -c $(SRC_CLT)
	$(CC) $(FLAGS) -o $@ server.c
$(OBJS_NAME_CLT):
	$(CC) $(FLAGS) -c $(SRC_CLT)
	$(CC) $(FLAGS) -o $@ $(SRC_CLT)
	
$(OBJS_DIR_BONUS):
	$(CC) $(FLAGS) -c $(BONUS_SRV) $(BONUS_CLT)
$(BONUS_OBJS_NAME_SRV):
	$(CC) $(FLAGS) -o $@ $(SRV_BONUS_OBJS)
$(BONUS_OBJS_NAME_CLT):
	$(CC) $(FLAGS) -o $@ $(CLT_BONUS_OBJS)


bonus: $(OBJS_DIR_BONUS) $(BONUS_OBJS_NAME_SRV) $(BONUS_OBJS_NAME_CLT)

clean:
	rm -rf $(OBJS_NAME_SRV) $(OBJS_NAME_CLT) $(BONUS_OBJS_NAME_SRV) $(BONUS_OBJS_NAME_CLT)

fclean:
	rm -f $(OBJS_NAME_SRV) $(OBJS_NAME_CLT) $(BONUS_OBJS_NAME_SRV) $(BONUS_OBJS_NAME_CLT)

re: clean all

bonus_re: fclean bonus

.PHONY: all clean fclean re bonus bonus_re
