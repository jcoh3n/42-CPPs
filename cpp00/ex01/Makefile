# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcohen <jcohen@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/03 14:30:26 by jcohen            #+#    #+#              #
#    Updated: 2025/02/03 14:43:05 by jcohen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PhoneBook
CPP = c++
OBJ_FOLDER = obj
FLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp Contact.cpp PhoneBook.cpp
OBJS = $(SRCS:%.cpp=$(OBJ_FOLDER)/%.o)
HEADERS = Contact.hpp PhoneBook.hpp

all: $(OBJ_FOLDER) $(NAME)

$(OBJ_FOLDER):
	mkdir -p $(OBJ_FOLDER)

$(NAME): $(OBJ)
	$(CPP) $(FLAGS) $(OBJS) -o $(NAME)
	
$(OBJ_FOLDER)/%.o: %.cpp $(HEADERS)
	$(CPP) $(FLAGS) -c $< -o $@
	
clean:
	rm -rf $(OBJ_FOLDER)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
