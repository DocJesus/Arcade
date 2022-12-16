#include "SFML.hpp"

int SFML::bodyCount;
int SFML::wallCount;
int SFML::ennemyCount;

SFML::SFML()
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

sf::Shape *SFML::getShapeForEntity(int _entity)
{
    sf::Shape *shape;

    switch (_entity)
    {
        case (PLAYER_UP):
            shape = &this->playerShape;
            break;
        case (BONUS):
            shape = &this->bonuShape;
            break;
        case (PLAYER_BODY):
        case (PLAYER_BODY_RIGHT):
        case (PLAYER_BODY_LEFT):
            if (this->bodyCount >= int(this->bodyShape.size()))
            {
                sf::RectangleShape newBodyShape = sf::RectangleShape(sf::Vector2f(16.f, 8.f));
                newBodyShape.setFillColor(sf::Color::White);
                this->bodyShape.push_back(newBodyShape);
            }
            shape = &this->bodyShape[this->bodyCount];
            this->bodyCount += 1;
            break;


        case (ENNEMY):
            if (this->ennemyCount >= int(this->ennemyShape.size()))
            {
                sf::RectangleShape newEnnemyShape = sf::RectangleShape(sf::Vector2f(16.f, 16.f));
                newEnnemyShape.setFillColor(sf::Color(150, 50, 250));
                this->ennemyShape.push_back(newEnnemyShape);
            }
            shape = &this->ennemyShape[this->ennemyCount];
            this->ennemyCount += 1;
            break;
        case (TOP_ROW):
        case (BOT_ROW):
        case (CORNER):
        case (SIDE_ROW):
            if (this->wallCount >= int(this->wallShape.size()))
            {
                sf::RectangleShape newWallShape = sf::RectangleShape(sf::Vector2f(16.f, 16.f));
                newWallShape.setFillColor(sf::Color(250, 150, 100));
                this->wallShape.push_back(newWallShape);
            }
            shape = &this->wallShape[this->wallCount];
            this->wallCount += 1;
            break;
        default:
            shape = nullptr;
            break;
    }
    return shape;
}

void SFML::resetCounters()
{
    this->bodyCount = 0;
    this->wallCount = 0;
    this->ennemyCount = 0;
}
