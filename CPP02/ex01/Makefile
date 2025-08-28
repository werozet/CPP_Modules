# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wzielins <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/28 14:11:32 by wzielins          #+#    #+#              #
#    Updated: 2025/08/28 14:11:34 by wzielins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Fixed01
CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp Fixed.cpp

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CPPFLAGS) -o $(NAME) $(SRC)

clean:
	rm -f $(NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re