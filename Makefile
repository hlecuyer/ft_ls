# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hlecuyer <hlecuyer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/18 12:01:59 by hlecuyer          #+#    #+#              #
#    Updated: 2015/05/18 12:01:59 by hlecuyer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=ft_ls
VERSION=1.0.1
CFLAGS=-Wall -Werror -Wextra -g
INCLUDES=-I ./includes -I ./libft/includes
LIBS=-L ./libft -l ft

SRC=loption.c \
	main.c \

OBJ=$(SRC:.c=.o)

all: build $(NAME) finish

build:
	@($(MAKE) -C ./libft)

$(NAME): $(OBJ) ./libft/libft.a
	gcc $(CFLAGS) $(INCLUDES) $(LIBS) -o $(NAME) $(OBJ)

%.o: %.c ./includes ./libft/includes
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

