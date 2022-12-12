SRC = Src/Arcade.cpp main.cpp

CXXFLAGS += -std=c++17 -Werror -Wextra -Wall -I./Include -I./Include/BrickBreaker -I./Include/Ncurses
LOADLIBES = -lm

OBJ = $(SRC:.cpp=.o)

NAME = arcade

$(NAME):	$(OBJ)
			g++ -o $(NAME) $(OBJ) -lpthread -lncurses 

fclean: clean
		rm -f $(NAME)

clean:
		rm -f $(OBJ)

all:	$(NAME) clean

re: fclean all