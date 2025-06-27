# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adruz-to <adruz-to@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/18 16:36:34 by adruz-to          #+#    #+#              #
#    Updated: 2025/06/27 12:38:22 by adruz-to         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME = so_long

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g -Iinclude

# Libft
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

# Ft_Printf
FT_PRINTF_DIR = ./ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/ft_printf.a

#Get next line
GET_NEXT_LINE_DIR = ./get_next_line
GET_NEXT_LINE = $(GET_NEXT_LINE_DIR)/get_next_line.a

# Minilibx
MLX42_DIR = ./MLX42
MLX42 = $(MLX42_DIR)/libmlx42.a

# Source files
SRCS = 


# Objects files
OBJS = $(SRCS:%.c=%.o)

$(NAME): $(OBJS) $(LIBFT)
		$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
		$(MAKE) -C $(LIBFT_DIR)

# Rules

all: $(NAME)

clean:
		rm -f $(OBJS)
		$(MAKE) -C $(LIBFT_DIR) clean
		$(MAKE) -C $(FT_PRINTF_DIR) clean
		$(MAKE) -C $(GET_NEXT_LINE_DIR) clean
		$(MAKE) -C $(MLX42_DIR) clean

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re