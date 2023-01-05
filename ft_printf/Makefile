NAME = libftprintf.a
CC = gcc -c
FLAGS = -Wall -Wextra -Werror -g
INCLUDE = ft_printf.h
AR = ar rcs
TOOLS = tools/*.c
LIBFT = libft_mod/*.c
MAIN = ft_printf.c
RM = rm -f
OBJ = *.o

# Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

all: $(NAME)

$(NAME):
		@echo "\033[32mCreating library...\033[0m"
		@$(CC) $(FLAGS) -c $(TOOLS) $(LIBFT) $(MAIN) -I $(INCLUDE)
		@$(AR) $(NAME) $(OBJ)
		@ranlib $(NAME)

clean:
			@$(RM) $(OBJ)
			@echo "$(BLUE)ft_printf\n object\n files\n cleaned!$(DEF_COLOR) "

fclean:		clean
			@$(RM) $(NAME)
			@echo "$(RED)ft_printf executable files cleaned!$(DEF_COLOR)"

re: fclean all

.PHONY: all bonus clean fclean re