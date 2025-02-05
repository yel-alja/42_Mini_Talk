SERVER = server
CLIENT = client

SERVER_B = serverb
CLIENT_B = clientb

SRCSERVER = utils.c \
			server.c
SRCSCLIENT = utils.c \
			client.c

SRCSERVER_B = utils_bonus.c \
				server_bonus.c
SRCSCLIENT_B = utils_bonus.c \
				client_bonus.c

OBJSERVER:=$(SRCSERVER:.c=.o)
OBJSCLIENT:=$(SRCSCLIENT:.c=.o)
OBJSERVER_B:=$(SRCSERVER_B:.c=.o)
OBJSCLIENT_B:=$(SRCSCLIENT_B:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g
CC = cc

all:$(SERVER) $(CLIENT)
bonus:$(SERVER_B) $(CLIENT_B)

$(SERVER):$(OBJSERVER)
	$(CC) $(CFLAGS) $(SRCSERVER) -o $(SERVER)
$(CLIENT):$(OBJSCLIENT)
	$(CC) $(CFLAGS) $(SRCSCLIENT) -o $(CLIENT)

$(SERVER_B):$(OBJSERVER_B)
	$(CC) $(CFLAGS) $(SRCSERVER_B) -o $(SERVER_B)

$(CLIENT_B):$(OBJSCLIENT_B)
	$(CC) $(CFLAGS) $(SRCSCLIENT_B) -o $(CLIENT_B)
clean :
	rm -f $(OBJSERVER)
	rm -f $(OBJSCLIENT)
	rm -f $(OBJSERVER_B)
	rm -f $(OBJSCLIENT_B)
fclean : clean
	rm -f $(SERVER)
	rm -f $(CLIENT)
	rm -f $(SERVER_B)
	rm -f $(CLIENT_B)
re: fclean all

.PHONY : all clean fclean re bonus
