#include <ncurses.h>
#include "AGraphic.hpp"
#include	<unistd.h>

#define WIDTH 120
#define HEIGHT 40 

class NCurse : public AGraphic
{
    private:
        WINDOW *win;
        int startx;
        int starty;
        unordered_map<int, char> convertor;
        vector<int> inputs;

    public:
        int tmp;

        NCurse()
        {
            cout << "initNcurse Graphical Library" << endl;
            tmp = 0;
            startx = 10;
            starty = 5;

            convertor[TOP_ROW] = '-';
            convertor[BOT_ROW] = '-';
            convertor[SIDE_ROW] = '|';
            convertor[CORNER] = '+';
            convertor[BONUS] = 'o';
            convertor[EMPTY] = ' ';

            convertor[PLAYER_BODY] = '=';
            convertor[PLAYER_BODY_LEFT] = '=';
            convertor[PLAYER_BODY_RIGHT] = '=';
            convertor[PLAYER_UP] = '^';
            convertor[PLAYER_DOWN] = 'v';
            convertor[PLAYER_LEFT] = '<';
            convertor[PLAYER_RIGHT] = '>';

            convertor[ENNEMY] = 'X';
            this->setWinSize(HEIGHT, WIDTH);
        }
        virtual ~NCurse() 
        {
            this->CloseScreen();
        }

        void InitScreen()
        {
            cout << "InitScreen NCurse " << this->tmp << endl;
            initscr();
            clear();
            noecho();
            cbreak();

            //todo create a new terminal that will take 100% of the screen
            //and pass to the win the size of the terminal
            this->win = newwin(HEIGHT, WIDTH, starty, startx);
            this->setWinSize(HEIGHT, WIDTH);

            nodelay(this->win, true);
            keypad(this->win, TRUE);
            refresh();
         }
 
        void CloseScreen()
        {
            clrtoeol();
            refresh();
            endwin();
            delwin(this->win);
            cout << "Ncurse close screen" << endl;
        }

        int ReadInputs()
        {
            int c;
            c = wgetch(this->win);
            
            switch(c)
            {	
                case 122:
                    c = UP;
                    break;
                case 100:
                    c = RIGHT;
                    break;
                case 115:
                    c = DOWN;
                    break;
                case 113:
                    c = LEFT;
                    break;
                case 10: //enter
                    // c = -42;
                    break;
                default:
                    refresh();
                    break;
            }
            mvprintw(0, 0, "Charcter pressed is = %3d Hopefully it can be printed as '%d'", c, c);
            refresh();

            flushinp();
            return c;
        }

        void Render(vector<vector<int>> _map, int _mapWidth, int _mapHeight)
        {
            (void)_mapWidth;

            // cout << input << endl;
            // temporaire
            // box(this->win, 0, 0);
            int x = 0;
            int y = 0;
            int startX = 0; //offset ? 
            int startY = _mapHeight; //offset ?
            int elem;

            wborder(this->win, 0, 0, 0, 0, 0, 0, 0, 0);
            // mvprintw(2, 0, "Charcter pressed is = %3d Hopefully it can be printed as '%d'", _map[1][_map[1].size()], _map[1][_map[1].size()]);

            while (y < int(_map.size()))
            {
                x = 0;
                while (x < int(_map[y].size()))
                {
                    elem = _map[y][x];

                    // NB: operator[] of maps and hash_map is not accecible in const fcts
                    mvwprintw(this->win, startY - y, startX + x, "%c", this->convertor[elem]);
                    x++;
                }
                y++;
            }
            
            wrefresh(this->win);
            refresh();
        }
};