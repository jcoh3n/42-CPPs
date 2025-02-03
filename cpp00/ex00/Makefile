# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcohen <jcohen@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/03 14:03:45 by jcohen            #+#    #+#              #
#    Updated: 2025/02/03 14:22:39 by jcohen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone
CPP = c++
FLAGS = -Wall -Wextra -Werror
OBJ_FOLDER = obj
FILES = megaphone.cpp

OBJ = $(addprefix $(OBJ_FOLDER)/, $(FILES:.cpp=.o))

all: $(OBJ_FOLDER) $(NAME)

$(OBJ_FOLDER):
	mkdir -p $(OBJ_FOLDER)

$(OBJ_FOLDER)/%.o: %.cpp
	$(CPP) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CPP) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ_FOLDER)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
