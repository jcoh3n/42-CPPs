# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcohen <jcohen@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/03 14:30:26 by jcohen            #+#    #+#              #
#    Updated: 2025/02/27 18:55:38 by jcohen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Brain
CXX = c++
OBJ_FOLDER = obj
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp
OBJS = $(SRCS:%.cpp=$(OBJ_FOLDER)/%.o)
HEADERS = Animal.hpp Dog.hpp Cat.hpp WrongAnimal.hpp WrongCat.hpp Brain.hpp

all: $(OBJ_FOLDER) $(NAME)

$(OBJ_FOLDER):
	mkdir -p $(OBJ_FOLDER)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJ_FOLDER)/%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_FOLDER)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
