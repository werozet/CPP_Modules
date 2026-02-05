# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wzielins <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/28 12:32:02 by wzielins          #+#    #+#              #
#    Updated: 2026/02/05 17:41:55 by wzielins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex03
SRC = main.cpp \
	Bureaucrat.cpp \
	AForm.cpp \
	ShrubberyCreationForm.cpp \
	RobotomyRequestForm.cpp \
	PresidentialPardonForm.cpp \
	Intern.cpp


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