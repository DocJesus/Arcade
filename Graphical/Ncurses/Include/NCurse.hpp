#include <ncurses.h>
#include "AGraphic.hpp"
#include	<unistd.h>

#define NCURSE_WIDTH 60
#define NCURSE_HEIGHT 60

class NCurse : public AGraphic
{
    private:
        WINDOW *win;
        int startx;
        int starty;
        unordered_map<int, char> convertor;
        vector<int> inputs;

    public:

        NCurse()
        {
            cout << "initNcurse Graphical Library" << endl;
            startx = 10;
            starty = 5;

            convertor[TOP_ROW] = '-';
            convertor[BOT_ROW] = '-';
            convertor[SIDE_ROW] = '|';
            convertor[CORNER] = '+';
            convertor[BONUS] = 'o';
            convertor[EMPTY] = ' ';

            convertor[PLAYER_BODY] = '|';
            convertor[PLAYER_BODY_UP] = '|';
            convertor[PLAYER_BODY_DOWN] = '|';
            convertor[PLAYER_BODY_LEFT] = '=';
            convertor[PLAYER_BODY_RIGHT] = '=';

            convertor[PLAYER] = '^';
            convertor[PLAYER_UP] = '^';
            convertor[PLAYER_DOWN] = 'v';
            convertor[PLAYER_LEFT] = '<';
            convertor[PLAYER_RIGHT] = '>';

            convertor[ENNEMY] = 'X';


            this->setWinSize(NCURSE_HEIGHT, NCURSE_WIDTH);
        }
        virtual ~NCurse() 
        {
            this->CloseScreen();
        }

        void InitScreen();

        void CloseScreen();

        int ReadInputs();

        void Render(vector<vector<int>> _map, int _mapWidth, int _mapHeight);

};