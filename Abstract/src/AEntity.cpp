#include "AGame.hpp"
#include "AEntity.hpp"

void AEntity::Die()
{
    this->gameMaster->KillEntity(this->coordY, this->coordX);
}

void AEntity::setYX(const int &_newY, const int &_newX)
{
    this->coordY = _newY;
    this->coordX = _newX;
}
void AEntity::setY(const int &_newY)
{
    this->coordY = _newY;
}
void AEntity::setX(const int &_newX)
{            
    this->coordX = _newX;
}
const int &AEntity::getPosX() const
{
    return this->coordX;
}
const int &AEntity::getPosY() const
{
    return this->coordY;
}
const int &AEntity::getType() const
{
    return this->type;
}
const AGame *AEntity::getMaster() const
{
    return this->gameMaster;
}
const int &AEntity::getDirection() const
{
    return this->direction;
}
