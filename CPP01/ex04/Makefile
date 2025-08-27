# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wzielins <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/27 14:30:55 by wzielins          #+#    #+#              #
#    Updated: 2025/08/27 14:31:06 by wzielins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = replace
CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp Replace.cpp

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CPPFLAGS) -o $(NAME) $(SRC)

clean:
	rm -f $(NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re