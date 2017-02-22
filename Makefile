# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/08 10:41:14 by jcharloi          #+#    #+#              #
#    Updated: 2017/02/21 16:00:14 by jcharloi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = fdf

CFLAGS = -Wall -Wextra -Werror

DEP = fdf.h

SRC = main.c \
	events.c \
	fdf.c \
	initmap.c \
	drawline.c \
	drawline2.c \
	coloroctants.c

OBJ = $(SRC:.c=.o)

MLX = ./mlxE3

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	make -C $(MLX)
	$(CC) -o $(NAME) $^ $(CFLAGS) libft/libft.a -L $(MLX) -lmlx -framework OpenGL -framework Appkit

%.o:%.c $(DEP)
	$(CC) -o $@ -c -I$(MLX) $< $(CFLAGS)

.PHONY: clean fclean re norme

clean:
	make clean -C libft/
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft/
	make clean -C $(MLX)
	rm -f $(NAME)

re: clean fclean all

norme:
	norminette $(SRC) libft/ fdf.h
