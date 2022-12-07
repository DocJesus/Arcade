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

    public:
        int tmp;

        NCurse()
        {
            cout << "initNcurse Graphical Library" << endl;
            tmp = 0;
            startx = (140 - WIDTH) / 2;
            starty = (50 - HEIGHT) / 2;
            choices = { 
                    "Choice 1",
                    "Choice 2",
                    "Choice 3",
                    "Choice 4",
                    "Exit",
                };
            n_choices = choices.size();
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
         }
 
        void CloseScreen()
        {
            clrtoeol();
            refresh();
            endwin();
            delwin(this->win);
            cout << "Ncurse close screen" << endl;
        }

        int GetInputs()
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

        void Render(vector<vector<int>> _map, int _startPosX, int _startPosY) const
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
                    mvwprintw(this->win, startY + y, startX + x, "%d", elem);
                    x++;
                }
                y++;
            }
            
            // mvprintw(24, 0, "Charcter pressed is = %3d Hopefully it can be printed as '%c'", input, input);
            // mvprintw(0, 0, "Use arrow keys to go up and down, Press enter to select a choice");
            /*
            int i;
            int highlight = 0;

            x = 2;
            y = 2;
            for(i = 0; i < this->n_choices; ++i)
            {	
                if(highlight == i + 1)
                {	
                    wattron(this->win, A_REVERSE); 
                    mvwprintw(this->win, y, x, "%s", this->choices[i]);
                    wattroff(this->win, A_REVERSE);
                }
                else
                    mvwprintw(this->win, y, x, "%s", this->choices[i]);
                ++y;
            }
            */
            wrefresh(this->win);
            refresh();
        }
};