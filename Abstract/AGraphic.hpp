#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>

using namespace std;

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
        virtual int ReadInputs() const = 0;
        virtual void Render(vector<vector<int>> _map, int _startPosX, int _startPosY) = 0;

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