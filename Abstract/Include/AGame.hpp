#include <iostream>
#include <vector>
#include <memory>
#include "state.h"
// #include "AEntity.hpp"

#ifndef H_AGame
#define H_AGame

using namespace std;
class AEntity;

class AGame
{
    protected:
        vector<vector<int>> map;
        vector<vector<shared_ptr<AEntity>>> entities;

        // the origin is the bottom LEFT Corner of the map
        // int startX;
        // int startY;

        int width;
        int height;


    public:
        AGame()
        {
        }
        virtual ~AGame()
        {
        }

        // give basic coordinate to Entities
        // draw the base of the map
        virtual void InitGame() = 0;

        // pass the input to the entities (like player)
        // update the position of all entities
        // handle collision ?
        virtual void GameUpdate(const int &_inputs) = 0;

        // move an Entity through the entities vector
        void EntityMoved(const int &_prevY, const int &_prevX, const int &_nextY, const int &_nextX);

        // create the base Arena
        void CreateArena();

        // get coordinate from entities and palce them on the board
        void DrawBoard();

        void KillEntity(const int &_Y, const int &_X);

        vector<vector<int>> &getMap();
        shared_ptr<AEntity> getEntityAt(const int &_coordY, const int &_coordX) const;
        void getHeightWidth(int *_height, int *_width) const;
        const int &getHeigh() const;
        const int &getWidth() const;
};

#endif