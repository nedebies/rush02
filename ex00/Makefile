# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/25 06:10:28 by nesdebie          #+#    #+#              #
#    Updated: 2023/02/25 06:10:29 by nesdebie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = 	./main.c \
		./utils.c \
		./ft_check.c \
		./ft_lst_manager.c \
		./ft_parsing.c \
		./ft_print.c \
		./ft_read.c 

NAME = rush-02

CC = gcc

CFLAGS = -Wall -Wextra -Werror

HEADER = rush02.h

OBJ = $(SRC:c=o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.c
	${CC} -c -o $@ $< ${CFLAGS}

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(OBJ)
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re