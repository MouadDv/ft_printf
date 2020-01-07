# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: milmi <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/05 20:52:43 by milmi             #+#    #+#              #
#    Updated: 2020/01/05 20:52:47 by milmi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a
SRCS= ft_atoi.c ft_cnv_d_to_hex.c ft_get_width.c ft_getaftermod.c ft_getaftermodutils.c ft_handle_int.c ft_handle_p.c ft_len_num.c ft_printf.c ft_putchar.c ft_putnbr.c ft_putstr.c ft_putunsigned.c ft_strlen.c ft_width_trick.c handle_percent.c handle_string.c handle_x.c
OBJECTS = $(SRCS:.c=.o)
FLAGS= -Wall -Wextra -Werror
CC=gcc
all: $(NAME)

$(NAME):
	@$(CC) $(FLAGS) -c $(SRCS)
	ar -rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

bonus:
	@$(CC) $(FLAGS) -c $(BSRCS)
	@ar -rc $(NAME) $(OBJECTS)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)
re: fclean all

