#include "AGraphic.hpp"
#include	<unistd.h>

#define WIDTH 120
#define HEIGHT 40 


class SFML
{
    private:

    public:
        int tmp;

        SFML()
        {
        }
        virtual ~SFML() 
        {
            this->CloseScreen();
        }

        void InitScreen()
        {
        }
 
        void CloseScreen()
        {
        }

        int ReadInputs() const
        {
        }

        void Render(vector<vector<int>> _map, int _startPosX, int _startPosY)
        {
        }
};