NAME_C	=	client
NAME_S	=	server
CC		=	clang
OBJDIR	=	objects
SRC		=	libft.c
SRC_C	=	client.c $(SRC)
SRC_C_B	=	client_bonus.c $(SRC)
SRC_S	=	server.c $(SRC)
SRC_S_B	=	server_bonus.c $(SRC)
OBJ_C 	=	$(addprefix $(OBJDIR)/, $(SRC_C:.c=.o))
OBJ_C_B	=	$(addprefix $(OBJDIR)/, $(SRC_C_B:.c=.o))
OBJ_S 	=	$(addprefix $(OBJDIR)/, $(SRC_S:.c=.o))
OBJ_S_B	=	$(addprefix $(OBJDIR)/, $(SRC_S_B:.c=.o))
CFLAGS	=	-Wall -Wextra -Werror

ifneq (,$(findstring xterm,${TERM}))
	GREEN := $(shell tput -Txterm setaf 2)
	RESET := $(shell tput -Txterm sgr0)
else
	GREEN := ""
	RESET := ""
endif

all: $(NAME_C) $(NAME_S)

bonus: client_bonus server_bonus

$(NAME_C): $(OBJ_C)
	@$(CC) $(CFLAGS) $(OBJ_C) -o $(NAME_C)
	@echo "${GREEN}Compilation Client Done${RESET}"

client_bonus: $(OBJ_C_B)
	@$(CC) $(CFLAGS) $(OBJ_C_B) -o $(NAME_C)
	@echo "${GREEN}Compilation Client Done${RESET}"

$(NAME_S): $(OBJ_S)
	@$(CC) $(CFLAGS) $(OBJ_S) -o $(NAME_S)
	@echo "${GREEN}Compilation Server Done${RESET}"

server_bonus: $(OBJ_S_B)
	@$(CC) $(CFLAGS) $(OBJ_S_B) -o $(NAME_S)
	@echo "${GREEN}Compilation Server Done${RESET}"

$(OBJDIR)/%.o: %.c
	@mkdir -p objects
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ_C) $(OBJ_S) $(OBJ_C_B) $(OBJ_S_B)

fclean: clean
	@rm -f $(NAME_C) $(NAME_S)

re: fclean all

.PHONY: clean fclean all re bonus