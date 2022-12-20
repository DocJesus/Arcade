#include "SFML.hpp"

int SFML::bodyCount;
int SFML::wallCount;
int SFML::ennemyCount;

void SFML::InitScreen()
{
    this->window.create(sf::VideoMode(SFML_WIDTH, SFML_HEIGHT), "SFML works!");
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);
}

void SFML::CloseScreen()
{
    this->window.close();
}

int SFML::ReadInputs()
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

void SFML::Render(vector<vector<int>> _map, int _mapWidth, int _mapHeight)
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

float SFML::VecCoordToFloat(int _coord)
{
    float floatCoord = _coord * 20.f; // need to find the real conversion

    return floatCoord;
}


sf::Shape *SFML::getShapeForEntity(int _entity)
{
    sf::Shape *shape;

    switch (_entity)
    {
        case (PLAYER_UP):
            shape = &this->playerShapeUp;
            break;
        case (PLAYER_DOWN):
            shape = &this->playerShapeDown;
            break;
        case (PLAYER_LEFT):
            shape = &this->playerShapeLeft;
            break;
        case (PLAYER_RIGHT):
            shape = &this->playerShapeRight;
            break;
        case (BONUS):
            shape = &this->bonuShape;
            break;
        case (PLAYER_BODY):
        case (PLAYER_BODY_UP):
        case (PLAYER_BODY_DOWN):
            /*
            if (this->bodyCount >= int(this->bodyShape.size()))
            {
                sf::RectangleShape newBodyShape = sf::RectangleShape(sf::Vector2f(16.f, 8.f));
                newBodyShape.setFillColor(sf::Color::White);
                newBodyShape.setRotation(90.f);
                this->bodyShape.push_back(newBodyShape);
            }
            shape = &this->bodyShape[this->bodyCount];
            this->bodyCount += 1;
            break; */
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
