SRC = Graphical/Common/shader.cpp Common/src/Arcade.cpp \
		Graphical/SFML/src/SFML.cpp \
		Abstract/src/AEntity.cpp Abstract/src/AGame.cpp \
		Games/BrickBreaker/src/BrickBreaker.cpp Games/BrickBreaker/src/BrickEnnemy.cpp \
		Games/BrickBreaker/src/BrickPlayer.cpp Games/BrickBreaker/src/BrickPlayerBody.cpp \
		Games/BrickBreaker/src/BrickProjectile.cpp \
		Games/Snake/src/Snake.cpp Games/Snake/src/SnakePlayer.cpp \
		Games/Snake/src/SnakeBody.cpp Games/Snake/src/SnakeFruit.cpp \
		Graphical/Ncurses/src/NCurse.cpp \
		main.cpp

CXXFLAGS += -std=c++17 -Werror -Wextra -Wall -I./Include \
			-I./Abstract -I./Common -I./Common/Include \
			-I./Games/BrickBreaker/Include -I./Games/Snake/Include \
			-I./Games/Common -I./Abstract/Include \
			-I./Include \
			-I./Graphical/Ncurses/Include -I./Graphical/SFML/Include

LDFLAGS+=	-lGL -lGLU -lGLEW -lglfw \
			-lncurses -lpthread \
			-lsfml-graphics -lsfml-window -lsfml-system


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