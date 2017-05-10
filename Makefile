# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebucur <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/26 16:01:02 by ebucur            #+#    #+#              #
#    Updated: 2017/04/26 16:01:05 by ebucur           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ft_ls

SRC	=	src/main.c src/util.c src/size.c src/display.c src/elem.c \
		src/error.c src/ft_ls.c src/print.c src/recurs.c \
		src/sort.c src/sort_ft.c src/time.c

OBJ		= $(SRC:.c=.o)

CFLAGS	= -Wall -Wextra -Werror -I include -I libft/include

$(NAME): $(OBJ)
	make -C libft/
	gcc $(OBJ) -o $(NAME) -L libft/ -lft

all: $(NAME)

clean:
	make -C libft/ clean
	rm -rf $(OBJ)

fclean: clean
	make -C libft/ fclean
	rm -rf $(NAME) $(OBJ)

re: fclean $(NAME)
