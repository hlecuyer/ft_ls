# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hlecuyer <hlecuyer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/15 10:51:40 by hlecuyer          #+#    #+#              #
#    Updated: 2015/05/15 10:51:40 by hlecuyer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=ft_ls
VERSION=1.0.0
CFLAGS=-Wall -Werror -Wextra -g
INCLUDES=-I ./libft/includes
LIBS=-L ./libft -l ft

SRC=main.c \

OBJ=$(SRC:.c=.o)

all: build $(NAME) finish

build:
	@($(MAKE) -C ./libft)

$(NAME): $(OBJ) ./libft/libft.a
	gcc $(CFLAGS) $(INCLUDES) $(LIBS) -o $(NAME) $(OBJ)

%.o: %.c ./libft/includes
	gcc $(CFLAGS) $(INCLUDES) -o $@ -c $<

clean:
	@(rm -rf $(OBJ))

fclean: clean
	@(rm -rf $(NAME))

re: fclean all

v:
	@(echo "version: $(VERSION)")

finish:
	@(echo "[\033[32m$(NAME)\033[00m]")

.PHONY: all build clean fclean re v

