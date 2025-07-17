# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adruz-to <adruz-to@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/18 16:36:34 by adruz-to          #+#    #+#              #
#    Updated: 2025/07/17 13:06:42 by adruz-to         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME = so_long

# Includes dir
INCLUDE_DIRS = -I./include \
			-I./ft_printf \
			-I./get_next_line \
			-I./MLX42/include \
			-I./libft

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Werror -Wextra $(INCLUDE_DIRS)

# Libft
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

# Ft_Printf
FT_PRINTF_DIR = ./ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/ft_printf.a

# Minilibx
MLX42_DIR = ./MLX42
MLX42 = $(MLX42_DIR)/build/libmlx42.a

# MLX42 linking flags
MLX42_FLAGS = -ldl -lglfw -pthread -lm

# Source files
SRCS = src/game_events.c \
	src/game_render.c \
	src/game.c \
	src/load_map.c \
	src/map_loader.c \
	src/map_path_validation.c \
	src/map_utils.c \
	src/map_validation_utils.c \
	src/map_validation.c \
	src/player_movement.c \
	src/player_utils.c \
	src/so_long_utils.c \
	src/so_long.c \
	get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c

# Objects files
OBJS = $(SRCS:%.c=%.o)

$(NAME): $(OBJS) $(LIBFT) $(FT_PRINTF) $(MLX42)
		$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(FT_PRINTF) $(MLX42) $(MLX42_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
		$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF):
		$(MAKE) -C $(FT_PRINTF_DIR)

$(MLX42):
		cmake -B $(MLX42_DIR)/build $(MLX42_DIR)
		cmake --build $(MLX42_DIR)/build -j4

# Rules

all: $(NAME)

clean:
		rm -f $(OBJS)
		$(MAKE) -C $(LIBFT_DIR) clean
		$(MAKE) -C $(FT_PRINTF_DIR) clean
		rm -rf $(MLX42_DIR)/build

fclean: clean
		rm -f $(NAME)
		$(MAKE) -C $(LIBFT_DIR) fclean
		$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re