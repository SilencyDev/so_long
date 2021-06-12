# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmacquet <kmacquet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/11 11:47:02 by kmacquet          #+#    #+#              #
#    Updated: 2021/06/12 15:16:42 by kmacquet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Imlx -I./includes
SRCS =	srcs/print.c srcs/parsing.c srcs/init.c srcs/utils.c \
		srcs/mlx.c srcs/get_next_line.c srcs/libft.c \
		srcs/main.c srcs/move.c
OBJS = $(SRCS:.c=.o)
RM = rm -f

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -o $(<:.c=.o) -c $<

$(NAME):$(OBJS)
	$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) -g -fsanitize=address

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
