# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcohen <jcohen@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/03 14:30:26 by jcohen            #+#    #+#              #
#    Updated: 2025/02/27 20:59:38 by jcohen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Interface
CXX = c++
OBJ_FOLDER = obj
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp Ice.cpp Cure.cpp MateriaSource.cpp Character.cpp AMateria.cpp
OBJS = $(SRCS:%.cpp=$(OBJ_FOLDER)/%.o)
HEADERS = Ice.hpp Cure.hpp MateriaSource.hpp Character.hpp AMateria.hpp ICharacter.hpp IMateriaSource.hpp

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
