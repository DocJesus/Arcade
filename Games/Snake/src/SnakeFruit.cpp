#include "SnakeFruit.hpp"

void SnakeFruit::Move(const int &_input)
{
    (void)_input;
}

void SnakeFruit::UpdatePos(const int &_input)
{
    (void)_input;
}

void SnakeFruit::Die()
{
    this->gameMaster->KillEntity(this->coordY, this->coordX);
    this->gameMaster->AddEntityRd(make_shared<SnakeFruit>(this));
}