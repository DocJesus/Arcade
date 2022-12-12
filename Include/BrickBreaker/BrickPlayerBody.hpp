#include "AEntity.hpp"

#ifndef H_BrickPlayerBody
#define H_BrickPlayerBody


class BrickPlayerBody : public AEntity
{
    public:
        BrickPlayerBody() : AEntity(PLAYER_UP, nullptr, 0, 0)
        {

        }
        BrickPlayerBody(int _type, AGame *_gameMaster, const int &_coordY, const int &_coordX) : AEntity(_type, _gameMaster, _coordY, _coordX)
        {

        }
        ~BrickPlayerBody()
        {
            
        }

        void Move(const int &_input = 0)
        {
            int prevY = this->coordY;
            int prevX = this->coordX;

            switch (_input)
            {
                case RIGHT: // move right
                    this->coordX += 1;
                    this->direction = PLAYER_RIGHT;
                    break;
                case LEFT: // move left
                    this->coordX -= 1;
                    this->direction = PLAYER_LEFT;
                    break;
                default:
                    break;
            }

            // cout << "BrickPlayerBodyMove " << prevY << " " << prevX << " " << this->coordY << " " << this->coordX << endl;
            gameMaster->EntityMoved(prevY, prevX, this->coordY, this->coordX);
        }

        void UpdatePos()
        {

        }
};

#endif