# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/08 10:41:14 by jcharloi          #+#    #+#              #
#    Updated: 2017/02/11 13:51:28 by jcharloi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = fdf

CFLAGS = -Wall -Wextra -Werror

DEP = fdf.h

SRC = main.c \
	fdf.c \
	initmap.c \
	drawline.c \
	drawline2.c \
	coloroctants.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	$(CC) -o $(NAME) $^ $(CFLAGS) libft/libft.a -L ./minilibx_macos -lmlx -framework OpenGL -framework Appkit

%.o:%.c $(DEP)
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean fclean re norme

clean:
	make clean -C libft/
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft/
	rm -f $(NAME)

re: clean fclean all

norme:
	norminette $(SRC) libft/ fdf.h