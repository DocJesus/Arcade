#include "NCurse.hpp"

void NCurse::InitScreen()
{
    // cout << "InitScreen NCurse " << this->tmp << endl;
    initscr();
    clear();
    noecho();
    cbreak();

    //todo create a new terminal that will take 100% of the screen
    //and pass to the win the size of the terminal
    this->win = newwin(NCURSE_HEIGHT, NCURSE_WIDTH, starty, startx);
    this->setWinSize(NCURSE_HEIGHT, NCURSE_WIDTH);

    nodelay(this->win, true);
    keypad(this->win, TRUE);
    refresh();
}

void NCurse::CloseScreen()
{
    clrtoeol();
    refresh();
    endwin();
    delwin(this->win);
    // cout << "Ncurse close screen" << endl;
}

int NCurse::ReadInputs()
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
        case 97:
            c = GRAPHICAL_DOWN;
            break;
        case 101:
            c = GRAPHICAL_UP;
            break;
        case 102: // F
            c = SPECIAL;
            break;
        case 10: //enter
            // c = -42;
            break;
        default:
            refresh();
            break;
    }
    // mvprintw(0, 0, "Charcter pressed is = %3d Hopefully it can be printed as '%d'", c, c);
    refresh();

    flushinp();
    return c;
}

void NCurse::Render(vector<vector<int>> _map, int _mapWidth, int _mapHeight)
{
    (void)_mapWidth;

    // cout << input << endl;
    // temporaire
    // box(this->win, 0, 0);
    int x = 0;
    int y = 0;
    int startX = 0; //offset ? 
    int startY = _mapHeight - 1; //offset ?
    int elem;

    // mvprintw(2, 0, "mapHeigt = %d map.size = %d", _mapHeight, _map.size());
    // wborder(this->win, 0, 0, 0, 0, 0, 0, 0, 0);
    // mvprintw(2, 0, "Charcter pressed is = %3d Hopefully it can be printed as '%d'", _map[1][_map[1].size()], _map[1][_map[1].size()]);

    while (y < _mapHeight)
    {
        x = 0;
        while (x < _mapWidth)
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
