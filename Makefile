# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgras-ca <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/24 16:08:54 by fgras-ca          #+#    #+#              #
#    Updated: 2023/07/24 16:55:37 by fgras-ca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = client
NAMES = server
BONUS_NAME = client_bonus
BONUS_NAMES = server_bonus
LIBFT = libft.a
PRINTF = libftprintf.a

SRC_CLIENT = client.c
SRC_SERVER = server.c
BONUS_CLIENT = client_bonus.c
BONUS_SERVER = server_bonus.c
SRC_DIR_LIBFT = libft/
SRC_DIR_PRINTF = printf/
SRC_LIBFT = $(addprefix $(SRC_DIR_LIBFT), $(LIBFT))
SRC_PRINTF = $(addprefix $(SRC_DIR_PRINTF), $(PRINTF))

OBJC = $(SRC_CLIENT:.c=.o)
OBJS = $(SRC_SERVER:.c=.o)
OBJCB = $(BONUS_CLIENT:.c=.o)
OBJSB = $(BONUS_SERVER:.c=.o)

CC = gcc

RM = rm -f

CFLAGS = -Wall -Werror -Wextra

all:	$(NAME) $(NAMES)

$(NAME) : $(OBJC)
	@make -C printf
	@make -C libft
	$(CC) $(CLFAGS) $(OBJC) $(SRC_PRINTF) $(SRC_LIBFT) -o $(NAME)

$(NAMES) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(SRC_PRINTF) $(SRC_LIBFT) -o $(NAMES)

bonus :	$(BONUS_NAME) $(BONUS_NAMES)

$(BONUS_NAME) : $(OBJCB)
	@make -C printf
	@make -C libft
	$(CC) $(CFLAGS) $(OBJCB) $(SRC_PRINTF) $(SRC_LIBFT) -o $(BONUS_NAME)

$(BONUS_NAMES) : $(OBJSB)
	$(CC) $(CFLAGS) $(OBJSB) $(SRC_PRINTF) $(SRC_LIBFT) -o $(BONUS_NAMES)

clean :
	@make clean -C printf
	@make clean -C libft
	$(RM) $(OBJC)
	$(RM) $(OBJS)
	$(RM) $(OBJCB)
	$(RM) $(OBJSB)

fclean : clean
	@make fclean -C printf
	@make fclean -C libft
	$(RM) $(NAME)
	$(RM) $(NAMES)
	$(RM) $(BONUS_NAME)
	$(RM) $(BONUS_NAMES)
	$(RM) $(PRINTF)
	$(RM) $(LIBFT)

re : fclean all

.PHONY : all bonus clean fclean re
