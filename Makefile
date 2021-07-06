NAME_C	=	client
NAME_S	=	server
CC		=	clang
OBJDIR	=	objects
SRC		=	libft.c
SRC_C	=	client.c $(SRC)
SRC_S	=	server.c $(SRC)
OBJ_C 	=	$(addprefix $(OBJDIR)/, $(SRC_C:.c=.o))
OBJ_S 	=	$(addprefix $(OBJDIR)/, $(SRC_S:.c=.o))
CFLAGS	=	-Wall -Wextra -Werror#-g3 -fsanitize=address

ifneq (,$(findstring xterm,${TERM}))
	GREEN := $(shell tput -Txterm setaf 2)
	RESET := $(shell tput -Txterm sgr0)
else
	GREEN := ""
	RESET := ""
endif

all: $(NAME_C) $(NAME_S)

bonus: all

$(NAME_C): $(OBJ_C)
	@$(CC) $(CFLAGS) $(OBJ_C) -o $(NAME_C)
	@echo "${GREEN}Compilation Client Done${RESET}"

$(NAME_S): $(OBJ_C)
	@$(CC) $(CFLAGS) $(OBJ_S) -o $(NAME_S)
	@echo "${GREEN}Compilation Server Done${RESET}"

$(OBJDIR)/%.o: %.c
	@mkdir -p objects
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ_C) $(OBJ_S)

fclean: clean
	@rm -f $(NAME_C) $(NAME_S)

re: fclean all

.PHONY: clean fclean all re bonus