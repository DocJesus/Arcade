#include <ncurses.h>
#include "AGraphic.hpp"

#define WIDTH 120
#define HEIGHT 40 


class NCurse : public AGraphic
{
    private:
        WINDOW *win;
        int startx;
        int starty;
        vector<string> choices;
        int n_choices;
        unordered_map<int, char> convertor;

    public:
        int tmp;

        NCurse()
        {
            cout << "initNcurse Graphical Library" << endl;
            tmp = 0;
            startx = 10;
            starty = 5;

            convertor[TOP_ROW] = '-';
            convertor[SIDE_ROW] = '|';
            convertor[CORNER] = '+';
            convertor[BONUS] = 'o';
            convertor[EMPTY] = ' ';

            convertor[PLAYER_BODY] = '=';
            convertor[PLAYER_UP] = '^';
            convertor[PLAYER_DOWN] = 'v';
            convertor[PLAYER_LEFT] = '<';
            convertor[PLAYER_RIGHT] = '>';

            convertor[ENNEMY] = 'X';
        }
        virtual ~NCurse() {}

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

        int GetInputs() const
        {
            int c = wgetch(this->win);
            
            switch(c)
            {	
                case KEY_UP:
                    // c = 1;
                    break;
                case KEY_DOWN:
                    // c = -1;
                    break;
                case 10: //enter
                    // c = -42;
                    break;
                default:
                    mvprintw(0, 0, "Charcter pressed is = %3d Hopefully it can be printed as '%c'", c, c);
                    refresh();
                    break;
            }
            
            return c;
        }

        void Render(vector<vector<int>> _map, int _startPosX, int _startPosY)
        {
            // cout << input << endl;
            // temporaire
            // box(this->win, 0, 0);
            int x = 0;
            int y = 0;
            int startX = _startPosX; //offset ? 
            int startY = _startPosY; //offset ?
            int elem;

            wborder(this->win, 0, 0, 0, 0, 0, 0, 0, 0);
            mvprintw(2, 0, "Charcter pressed is = %3d Hopefully it can be printed as '%d'", _map[1][_map[1].size()], _map[1][_map[1].size()]);

            while (y < int(_map.size()))
            {
                x = 0;
                while (x < int(_map[y].size()))
                {
                    elem = _map[y][x];

                    // NB: operator[] of maps and hash_map is not accecible in const fcts
                    mvwprintw(this->win, startY + y, startX + x, "%c", this->convertor[elem]);
                    x++;
                }
                y++;
            }
            
            wrefresh(this->win);
            refresh();
        }
};