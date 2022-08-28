# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kishigam <kishigam@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/29 00:28:10 by kishigam          #+#    #+#              #
#    Updated: 2022/08/29 00:28:11 by kishigam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = server.c client.c
OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: server client

bonus: server client

server: server.o Libft
	$(CC) -o $@ $< -LLibft -lft

client: client.o Libft
	$(CC) -o $@ $< -LLibft -lft

%.o: %.c
	$(CC) -c $(CFLAGS) $?

Libft:
	make -C Libft

clean:
	rm -f $(OBJECTS)
	make -C Libft clean
	
fclean: clean
	rm -f server client Libft/Libft.a

re: fclean all

.PHONY: all bonus Libft clean fclean re
