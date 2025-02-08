CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = minitalk
EXC_BONUS_C = .client_b
EXC_BONUS_S = .server_b
EXC_MANDATORY_C = .client_mandtory
EXC_MANDATORY_S = .server_mandtory
SRCSCLIENT = utils.c \
			client.c
SRCSERVER = server.c \
				utils.c

SRCSCLIENTB = utils_bonus.c \
			client_bonus.c
SRCSERVERB = server_bonus.c \
			utils_bonus.c

OBJ_SM = $(SRCSERVER:.c=.o)
OBJ_CM = $(SRCSCLIENT:.c=.o)

OBJ_SB = $(SRCSERVERB:.c=.o)
OBJ_CB = $(SRCSCLIENTB:.c=.o)

all : $(NAME)

$(NAME) : $(EXC_MANDATORY_S) $(EXC_MANDATORY_C)


$(EXC_MANDATORY_S) : $(OBJ_SM)
		@$(CC) $(CFLAGS) $(SRCSERVER) -o $(EXC_MANDATORY_S)
		@ln -sfv  $(EXC_MANDATORY_S) server
$(EXC_MANDATORY_C) : $(OBJ_CM)
		@$(CC) $(CFLAGS) $(SRCSCLIENT) -o $(EXC_MANDATORY_C)
		@ln -sfv  $(EXC_MANDATORY_C) client

bonus : $(EXC_BONUS_C) $(EXC_BONUS_S)

ifneq ("$(realpath .client_b)", "$(realpath client)")
	@ln -sfv .client_b client
	@ln -sfv .server_b server
ifneq ("$(wildcard utils.o)", "")
	@touch utils.o
endif
endif

$(EXC_BONUS_S) : $(OBJ_SB)
		@$(CC) $(CFLAGS) $(SRCSERVERB) -o $(EXC_BONUS_S)
		@ln -sf  $(EXC_BONUS_S) server
$(EXC_BONUS_C) : $(OBJ_CB)
		@$(CC) $(CFLAGS) $(SRCSCLIENTB) -o $(EXC_BONUS_C)
		@ln -sf $(EXC_BONUS_C) client

clean :
	rm -f $(OBJ_SM) $(OBJ_CM)
	rm -f $(OBJ_SB) $(OBJ_CB)

fclean : clean
	rm -f $(EXC_MANDATORY_C) $(EXC_MANDATORY_S)
	rm -f $(EXC_BONUS_C) $(EXC_BONUS_S) server client

re : fclean all

.PHONY : all re fclean clean bonus
