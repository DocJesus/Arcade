#include "AGame.hpp"
#include "AEntity.hpp"
#include "Wall.hpp"

void AGame::EntityMoved(const int &_prevY, const int &_prevX, const int &_nextY, const int &_nextX)
{
    if (_prevY != _nextY || _prevX != _nextX)
    {
        this->entities[_nextY][_nextX] = this->entities[_prevY][_prevX];
        this->entities[_prevY][_prevX] = nullptr;
    }
}

void AGame::CreateArena()
{
    int y = 0;
    int x = 0;

    while (y < this->height)
    {
        x = 0;
        if (y == 0)
        {
            while (x < this->width)
            {
                this->entities[y][x] = make_shared<Wall>(BOT_ROW, this, y, x);
                x++;
            }
        }
        else if (y == this->height - 1)
        {
            while (x < this->width)
            {
                this->entities[y][x] = make_shared<Wall>(TOP_ROW, this, y, x);
                x++;
            }
        }
        else
        {
            this->entities[y][0] = make_shared<Wall>(SIDE_ROW, this, y, 0);
            this->entities[y][this->width - 1] = make_shared<Wall>(SIDE_ROW, this, y, this->width - 1);
        }
        y++;
    }

    this->entities[0][0] = make_shared<Wall>(CORNER, this, 0, 0);
    this->entities[this->height - 1][this->width - 1] = make_shared<Wall>(CORNER, this, this->height - 1, this->width - 1);
    this->entities[0][this->width - 1] = make_shared<Wall>(CORNER, this, 0, this->width - 1);
    this->entities[this->height - 1][0] = make_shared<Wall>(CORNER, this, this->height - 1, 0);

}

void AGame::DrawBoard()
{
    int x = 0;
    int y = 0;
    int type = 0;

    while (y < this->height)
    {
        x = 0;
        while (x < this->width)
        {
            if (this->entities[y][x] != nullptr)
            {
                type = this->entities[y][x]->getType();
                if (type == PLAYER || type == PLAYER_BODY)
                {
                    this->map[y][x] = this->entities[y][x]->getDirection();                    
                }
                else
                    this->map[y][x] = type;
                
            }
            else
                this->map[y][x] = EMPTY;
            x++;
        }
        y++;
    }
}

void AGame::KillEntity(const int &_Y, const int &_X)
{
    this->entities[_Y][_X] = nullptr;
    this->map[_Y][_X] = EMPTY;
}

void AGame::AddEntity(const int &_Y, const int &_X, shared_ptr<AEntity> _ent)
{
    if (_Y < int(this->entities.size()))
    {
        if (_X < int(this->entities[_Y].size()))
        {
            // cout << "Adding Entity at " << _Y << " " << _X << endl;
            this->entities[_Y][_X] = _ent;
            _ent->setY(_Y);
            _ent->setX(_X);
        }
    }
}

void AGame::AddEntityRd(shared_ptr<AEntity> _ent)
{
    int coordX = rand() % (this->width - 1) + 1;
    int coordY = rand() % (this->height - 1) + 1;
    int lock = 0;

    shared_ptr<AEntity> next_tile = nullptr;
    next_tile = getEntityAt(coordY, coordX);

    while (next_tile != nullptr && lock < 50)
    {
        coordX = rand() % this->width + 1;
        coordY = rand() % this->height + 1;
        next_tile = getEntityAt(coordY, coordX);
        lock += 1;
    }

    if (lock < 50)
    {
        this->entities[coordY][coordX] = _ent;
        _ent->setY(coordY);
        _ent->setX(coordX);
    }

}

vector<vector<int>> &AGame::getMap()
{
    return this->map;
}
shared_ptr<AEntity> AGame::getEntityAt(const int &_coordY, const int &_coordX) const
{
    return this->entities[_coordY][_coordX];
}
void AGame::getHeightWidth(int *_height, int *_width) const
{
    *_height = this->height;
    *_width = this->width;
}
const int &AGame::getHeigh() const
{
    return this->height;
}
const int &AGame::getWidth() const
{
    return this->width;
}
