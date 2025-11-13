# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wzielins <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/13 12:27:49 by wzielins          #+#    #+#              #
#    Updated: 2025/11/13 13:14:32 by wzielins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = ex01
SRC = main.cpp \
	Bureaucrat.cpp \
	Form.cpp \

# Object files
OBJDIR = obj
OBJ = $(addprefix $(OBJDIR)/, $(SRC:.cpp=.o))
  
# Compiler and flags
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

# Default rule
all: $(OBJDIR) $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)

# Link object files into executable
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	
# Compile source files into object files
$(OBJDIR)/%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	rm -rf $(OBJDIR)

# Clean everything
fclean: clean
	rm -f $(NAME)

# Rebuild
re: fclean all

# Phony targets
.PHONY: all clean fclean re