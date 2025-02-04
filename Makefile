SERVER = server
CLIENT = client

SRCSERVER = utils.c \
			server.c

SRCSCLIENT = utils.c \
			client.c

OBJSERVER:=$(SRCSERVER:.c=.o)
OBJSCLIENT:=$(SRCSCLIENT:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror

all:$(SERVER) $(CLIENT)

$(SERVER):$(OBJSERVER)
	$(CC) $(CFLAGS) $(SRCSERVER) -o $(SERVER)

$(CLIENT):$(OBJSCLIENT)
	$(CC) $(CFLAGS) $(SRCSCLIENT) -o $(CLIENT)
clean :
	rm -f $(OBJSERVER)
	rm -f $(OBJSCLIENT)
fclean : clean
	rm -f $(SERVER)
	rm -f $(CLIENT)
re: fclean all

.PHONY : all clean fclean re bonus
