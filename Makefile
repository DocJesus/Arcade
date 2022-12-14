SRC = Graphical/Common/shader.cpp Common/Arcade.cpp main.cpp

CXXFLAGS += -std=c++17 -Werror -Wextra -Wall -I./Include \
			-I./Abstract -I./Common -I./Graphical/OpenGL \
			-I./Games/BrickBreaker -I./Graphical/Ncurses \
			-I./Graphical

LDFLAGS+=	-lGL -lGLU -lGLEW -lglfw\
			-lncurses \
			-lpthread


LOADLIBES = -lm

OBJ = $(SRC:.cpp=.o)

NAME = arcade

$(NAME):	$(OBJ)
			g++ $(OBJ) -o $(NAME) $(LDFLAGS)

fclean: clean
		rm -f $(NAME)

clean:
		rm -f $(OBJ)

all:	$(NAME) clean

re: fclean all