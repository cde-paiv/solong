# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cde-paiv <cde-paiv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/24 09:19:33 by cde-paiv          #+#    #+#              #
#    Updated: 2024/08/19 19:37:02 by cde-paiv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SOURCES = 	ft_strlen.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strlcpy.c\
			ft_split.c ft_itoa.c get_next_line.c get_next_line_utils.c \
		
OBJ = $(SOURCES:.c=.o)
RM = rm -f
AR = ar rcs

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

bonus:	$(NAME)
	$(AR) $(NAME)

clean:
	$(RM) $(OBJ)
	@echo "objects deleted"

fclean: clean
	$(RM) $(NAME)
	@echo "libft deleted"

re: fclean all

.PHONY: all clean fclean re
