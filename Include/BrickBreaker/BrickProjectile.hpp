#include "AEntity.hpp"

class BrickProjectile : public AEntity
{
    public:
        BrickProjectile() : AEntity(BONUS, nullptr, 0, 0)
        {
            this->direction = UP;
        }
        BrickProjectile(AGame *_gameMaster, const int &_coordY, const int &_coordX) : AEntity(BONUS, _gameMaster, _coordY, _coordX)
        {
            this->direction = UP;
        }
        virtual ~BrickProjectile()
        {

        }

        // validate the input passed and move
        void Move(const int &_input = 0)
        {
            (void)_input;
            int prevY = this->coordY;
            int prevX = this->coordX;

            this->UpdatePos();

            cout << "Prev Coord " << prevY << " " << prevX << endl;
            cout << "what is at " << this->coordY << " " << this->coordX << endl;
            shared_ptr<AEntity> next_tile = gameMaster->getEntityAt(this->coordY, this->coordX);
            cout << "Bonjour" << endl;
            int i = 0;
            if (next_tile != nullptr && next_tile->getType() != BONUS)
            {
                while (next_tile != nullptr && next_tile->getType() != BONUS && i < 50)
                {
                    if (next_tile->getType() == ENNEMY)
                    {
                        cout << "hit an ennemy" << endl;
                        next_tile->Die();
                    }

                    this->Ricochet();
                    if (next_tile->getType() == PLAYER_BODY_LEFT)
                        this->direction = UP_LEFT;
                    if (next_tile->getType() == PLAYER_BODY_RIGHT)
                        this->direction = UP_RIGHT;

                    this->UpdatePos();

                    cout << "what is at " << this->coordY << " " << this->coordX << endl;
                    // check if we go out of the map
                    next_tile = gameMaster->getEntityAt(this->coordY, this->coordX);
                    i++;
                }
                gameMaster->EntityMoved(prevY, prevX, this->coordY, this->coordX);
            }
            else
            {
                cout << prevY << " " << prevX << " " << this->coordY << " " << this->coordX;
                gameMaster->EntityMoved(prevY, prevX, this->coordY, this->coordX);
            }
        }

        void Ricochet()
        {
            cout << "Ricochet" << endl;
            if (this->direction % 2 == 0)
                this->direction += 1;
            else
                this->direction -= 1;

            // this->UpdatePos();
            // gameMaster->EntityMoved(prevY, prevX, this->coordY, this->coordX);
        }

        void UpdatePos()
        {
            cout << "direction of projectile " << this->direction << endl;
            switch (this->direction)
            {
                case RIGHT: // move right
                    this->coordX += 1;
                    break;
                case LEFT: // move left
                    this->coordX -= 1;
                    break;
                case UP: // move up
                    this->coordY += 1;
                    break;
                case DOWN: // move down
                    this->coordY -= 1;
                    break;
                case UP_LEFT: // move up left
                    this->coordX -= 1;
                    this->coordY += 1;
                    break;
                case UP_RIGHT: // move up right
                    this->coordX += 1;
                    this->coordY += 1;
                    break;
                case DOWN_RIGHT: // move down right
                    this->coordX += 1;
                    this->coordY -= 1;
                    break;
                case DOWN_LEFT: // move down left
                    this->coordX -= 1;
                    this->coordY -= 1;
                    break;
                default:
                    break;
            }

            [](BrickProjectile *brick) { if (brick->getPosY() < 0) {brick->setY(1);}} (this);
            [](BrickProjectile *brick) { if (brick->getPosX() < 0) {brick->setX(1);}} (this);
            [](BrickProjectile *brick) { if (brick->getPosY() >= brick->getMaster()->getHeigh()) {brick->setY(brick->getMaster()->getHeigh() - 1);}}(this);
            [](BrickProjectile *brick) { if (brick->getPosX() >= brick->getMaster()->getWidth()) {brick->setX(brick->getMaster()->getWidth() - 1);}}(this);
        }
};