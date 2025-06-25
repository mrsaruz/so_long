# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adruz-to <adruz-to@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/18 16:36:34 by adruz-to          #+#    #+#              #
#    Updated: 2025/06/25 13:08:32 by adruz-to         ###   ########.fr        #
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

# Minilibx
MLX_DIR = ./minilibx-linux

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

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re