# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adruz-to <adruz-to@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/18 16:36:34 by adruz-to          #+#    #+#              #
#    Updated: 2025/06/26 17:16:25 by adruz-to         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME = so_long

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g -Iinclude -I$(MLX42_DIR)/include -I$(LIBFT_DIR) -I$(FT_PRINTF_DIR) -I./get_next_line 

# Libft
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

# Ft_Printf
FT_PRINTF_DIR = ./ft_printf/ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

#Get next line
GET_NEXT_LINE_SRCS = ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c
GET_NEXT_LINE_OBJS = $(GET_NEXT_LINE_SRCS:%.c=%.o)

# Minilibx
MLX42_DIR = ./MLX42
MLX42 = $(MLX42_DIR)/build/libmlx42.a
MLX42_FLAGS = -ldl -lglfw -pthread -lm

# Source files
SRCS = so_long.c
		
# Objects files
OBJS = $(SRCS:%.c=%.o)

$(NAME): $(OBJS) $(LIBFT) $(FT_PRINTF) $(GET_NEXT_LINE_OBJS) $(MLX42)
		$(CC) $(CFLAGS) $(OBJS) $(GET_NEXT_LINE_OBJS) $(LIBFT) $(FT_PRINTF) $(MLX42) $(MLX42_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
		$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF):
		$(MAKE) -C $(FT_PRINTF_DIR)

$(MLX42):
		cd $(MLX42_DIR) && cmake -B build && make -C build

# Rules

all: $(NAME)

clean:
		rm -f $(OBJS) $(GET_NEXT_LINE_OBJS)
		$(MAKE) -C $(LIBFT_DIR) clean
		$(MAKE) -C $(FT_PRINTF_DIR) clean
# si existe el directorio de build de MLX42, limpia los archivos compilados, si no existe, no hagas nada
		if [ -d "$(MLX42_DIR)/build" ]; then $(MAKE) -C $(MLX42_DIR)/build clean; fi

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re