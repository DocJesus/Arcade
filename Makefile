SRC = Common/Arcade.cpp main.cpp

CXXFLAGS += -std=c++17 -Werror -Wextra -Wall -I./Include \
			-I./Abstract -I./Common -I./Graphical/OpenGL \
			-I./Games/BrickBreaker -I./Graphical/Ncurses

LDFLAGS+=	-lGL -lGLU \
			-lncurses \
			-lpthread


LOADLIBES = -lm

OBJ = $(SRC:.cpp=.o)

NAME = arcade

$(NAME):	$(OBJ)
			g++ -o $(NAME) $(OBJ)

fclean: clean
		rm -f $(NAME)

clean:
		rm -f $(OBJ)

all:	$(NAME) clean

re: fclean all