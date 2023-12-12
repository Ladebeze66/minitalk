# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgras-ca <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/18 16:20:00 by fgras-ca          #+#    #+#              #
#    Updated: 2023/03/18 16:32:40 by fgras-ca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SOURCES =	libftprintf/ft_decimal_pf.c \
		libftprintf/ft_hexnum_pf.c \
		libftprintf/ft_print_type.c \
		libftprintf/ft_ptrhex_pf.c \
		libftprintf/ft_putchar_pf.c \
		libftprintf/ft_putstr_pf.c \
		libftprintf/ft_unsigned_pf.c \
		ft_printf.c

OBJECTS = $(SOURCES:.c=.o)

CC = gcc

RM = rm -f

CFLAGS = -Wall -Werror -Wextra

all:	$(NAME)

$(NAME):	$(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

main:
	$(CC) $(CFLAGS) main.c -L. -lftprintf

clean:
	$(RM) $(OBJECTS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
