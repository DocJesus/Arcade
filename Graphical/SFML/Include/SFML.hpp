#include "AGraphic.hpp"
#include <unistd.h>
#include <SFML/Graphics.hpp>

// min width min height ?
#define SFML_WIDTH 1400
#define SFML_HEIGHT 1000


class SFML : public AGraphic
{
    private:
        sf::RenderWindow window;

        sf::CircleShape bonuShape;
        sf::CircleShape playerShape;
        vector<sf::RectangleShape> bodyShape;
        vector<sf::RectangleShape> wallShape;
        vector<sf::RectangleShape> ennemyShape;
        unordered_map<sf::Keyboard::Key, int> keyMap;

        static int bodyCount;
        static int wallCount;
        static int ennemyCount;

    public:

        SFML()
        {
            this->bonuShape = sf::CircleShape(8.f);
            this->bonuShape.setPointCount(25);

            this->playerShape = sf::CircleShape(8.f, 3);
            this->setWinSize(800, 800); // mettre un DEFINE dans AGraphic + Formule pour Ncurse

            this->keyMap[sf::Keyboard::Escape] = 10;
            this->keyMap[sf::Keyboard::Return] = 10;
            this->keyMap[sf::Keyboard::Z] = UP;
            this->keyMap[sf::Keyboard::Q] = LEFT;
            this->keyMap[sf::Keyboard::S] = DOWN;
            this->keyMap[sf::Keyboard::D] = RIGHT;

            this->keyMap[sf::Keyboard::A] = GRAPHICAL_DOWN;
            this->keyMap[sf::Keyboard::E] = GRAPHICAL_UP;

            this->resetCounters();
        }

        virtual ~SFML() 
        {
            this->CloseScreen();
        }

        void InitScreen();

        void CloseScreen();

        int ReadInputs();

        void Render(vector<vector<int>> _map, int _mapWidth, int _mapHeight);

        float VecCoordToFloat(int _coord);

    private:
        sf::Shape *getShapeForEntity(int _entity);
        void resetCounters();
};