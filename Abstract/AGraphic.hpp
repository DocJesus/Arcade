#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include <state.h>

using namespace std;

#ifndef H_AGraphic
#define H_AGraphic

class AGraphic
{
    private:
        int width;
        int height;
    public:
        AGraphic()
        {
        }
        virtual ~AGraphic()
        {

        }

        virtual void InitScreen() = 0;
        virtual void CloseScreen() = 0;
        virtual int ReadInputs() = 0;
        virtual void Render(vector<vector<int>> _map, int _mapWidth, int _mapHeight) = 0;
        virtual void Sleep(float _secTime) = 0;

        void getWinSize(int* _height, int* _width) const
        {
            *_height = this->height;
            *_width = this->width;
        }

        void setWinSize(int _height, int _width)
        {
            this->height = _height;
            this->width = _width;
        }
};

#endif