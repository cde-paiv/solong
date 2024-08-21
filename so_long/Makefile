# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cde-paiv <cde-paiv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/19 18:57:40 by cde-paiv          #+#    #+#              #
#    Updated: 2024/08/21 20:15:21 by cde-paiv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_PATH	= ./libraries/libft
LIBFT		= $(LIBFT_PATH)/libft.a

MINILIBX_PATH	= ./libraries/minilibx
MINILIBX	= $(MINILIBX_PATH)/libmlx.a

SOURCES_FILES	= so_long.c \
		  draw.c \
		  init.c \
		  read_map.c \
		  map.c \
		  game_keys.c \
		  game_update.c \
		  exit_game.c

SOURCES_DIR	= ./sources
HEADER		= so_long.h

SOURCES		= $(addprefix $(SOURCES_DIR)/, $(SOURCES_FILES))
OBJECTS		= $(SOURCES:$(SOURCES_DIR)/%.c=$(SOURCES_DIR)/%.o)

NAME		= so_long

CC		= clang
RM		= rm -f

CFLAGS		= -Wall -Wextra -Werror -I$(SOURCES_DIR)
MLXFLAGS	= -L. -lXext -L. -lX11

all: $(NAME)

$(NAME): $(LIBFT) $(MINILIBX) $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) $(MINILIBX) $(MLXFLAGS) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

$(MINILIBX):
	$(MAKE) -C $(MINILIBX_PATH)

$(SOURCES_DIR)/%.o: $(SOURCES_DIR)/%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_PATH) clean
	$(MAKE) -C $(MINILIBX_PATH) clean
	$(RM) $(OBJECTS)

fclean: clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
