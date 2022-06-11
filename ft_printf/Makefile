# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kishigam <kishigam@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/11 11:49:07 by kishigam          #+#    #+#              #
#    Updated: 2022/06/11 15:06:56 by kishigam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=libftprintf.a

LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a

INCS_DIR	= ./includes

SRC_DIR		= ./srcs
SRCS		= $(SRC_DIR)/ft_printf.c \
			$(SRC_DIR)/ft_setting.c

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
INCS		= -I$(INCS_DIR) -I$(LIBFT_DIR)
LFLAGS		= -L$(LIBFT_DIR) -lft

OBJS		= $(SRCS:.c=.o)

all:		$(NAME)

.c.o:
			$(cc) $(CFLAGS) $(INCS) -c $^ -o $(^:.c=.o)

$(NAME):	$(OBJS) $(LIBFT)
			ar -rcs $(NAME) $(OBJS)

$(LIBFT):
			make -C $(LIBFT_DIR)
			cp $(LIBFT) $(NAME)

clean:
			make clean -C $(LIBFT_DIR)
			rm -f $(OBJS)

fclean:		clean
			make fclean -C $(LIBFT_DIR)
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
