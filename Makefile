NAME		= so_long
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g #-fsanitize=address
RM			= /bin/rm -f

LIBFT_DIR	= libft
PRINTF_DIR	= ft_printf

INCLUDE_DIR	= includes

SRCS_PLATFORM = game.c
MLX_DIR		= mlx
MLX_FLAGS	= -L$(MLX_DIR) -lmlx \
			-framework OpenGL \
			-framework AppKit
INCLUDES 	= -I$(INCLUDE_DIR) \
			-I$(LIBFT_DIR) \
			-I$(PRINTF_DIR) \
			-I$(MLX_DIR)
LIBS		= -L$(LIBFT_DIR) -lft \
			-L$(PRINTF_DIR) -lftprintf

BUILD_DIR	= build
SRC_DIR		= ./srcs
SRCS		=	$(SRCS_PLATFORM) \
				main.c \
				panel.c \
				map.c \
				player.c \
				player_mov.c \
				player_mov2.c \
				enemy.c \
				handling.c \
				init.c \
				validate.c \
				utils/game_util.c \
				utils/vector_util.c \
				utils/img_util.c \
				utils/file_util.c \
				utils/tile_util.c \
				utils/path_finder.c 

OBJS = $(SRCS:%.c=$(BUILD_DIR)/%.o)

all: $(NAME)

restart: cbuild $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) $(LIBS) $(MLX_FLAGS) -o $(NAME)

$(NAME): $(OBJS) libs
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(MLX_FLAGS) -o $(NAME)

$(OBJS): $(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) -g $(CFLAGS) $(INCLUDES) -c $< -o $@

libs:
	@make -C $(LIBFT_DIR)
	@make -C $(PRINTF_DIR)
	@make -C $(MLX_DIR)	

bonus: all

re: fclean all

cbuild:
	-$(RM) -r $(BUILD_DIR)

clean:
	make clean -C $(LIBFT_DIR)
	make clean -C $(PRINTF_DIR)
	make clean -C $(MLX_DIR)
	$(RM) -r $(BUILD_DIR)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(PRINTF_DIR)
	make fclean -C $(MLX_DIR)	
	$(RM) $(NAME)

.PHONY: all clean fclean re
