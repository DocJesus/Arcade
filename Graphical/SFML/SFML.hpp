#include "AGraphic.hpp"
#include <unistd.h>
#include <SFML/Graphics.hpp>

// min width min height ?

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

        SFML();
        virtual ~SFML() 
        {
            this->CloseScreen();
        }

        void InitScreen()
        {
            this->window.create(sf::VideoMode(1600, 800), "SFML works!");
            window.setVerticalSyncEnabled(true);
            window.setFramerateLimit(60);
        }
 
        void CloseScreen()
        {
            this->window.close();
        }

        int ReadInputs()
        {
            int value = 0;
            sf::Event event;
            bool available = true;

            while (this->window.pollEvent(event))
            {
                if (available)
                {
                    switch (event.type)
                    {
                        case sf::Event::KeyPressed:
                        value = this->keyMap[event.key.code];
                        break;
                        case sf::Event::Closed:
                            window.close();
                            value = 10;
                            break;
                        default:
                            break;
                    }
                    available = false;
                }
            }

            return value;
        }

        void Render(vector<vector<int>> _map, int _mapWidth, int _mapHeight)
        {
            int x = 0;
            int y = 0;
            int startX = this->VecCoordToFloat(_mapWidth) + 50; //offset ? 
            int startY = this->VecCoordToFloat(_mapHeight) + 50; //offset ?
            startX = 0;
            // startY = 0;
            int elem;
            sf::Shape *shape;

            this->window.clear(sf::Color::Black);
            // draw box around the whole shit ?
            // wborder(this->win, 0, 0, 0, 0, 0, 0, 0, 0);

            while (y < int(_map.size()))
            {
                x = 0;
                while (x < int(_map[y].size()))
                {
                    elem = _map[y][x];
                    shape = getShapeForEntity(elem);
                    if (shape != nullptr)
                    {
                        shape->setPosition(this->VecCoordToFloat(x) + startX, startY - this->VecCoordToFloat(y));
                        this->window.draw(*shape);
                    }
                    x++;
                }
                y++;
            }

            this->resetCounters();
            this->window.display();
        }

        float VecCoordToFloat(int _coord)
        {
            float floatCoord = _coord * 20.f; // need to find the real conversion

            return floatCoord;
        }

    private:
        sf::Shape *getShapeForEntity(int _entity);
        void resetCounters();
};