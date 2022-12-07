#include <vector>
#include <string>
#include <stdio.h>
#include <ncurses.h>
#include <iostream>

#define WIDTH 30
#define HEIGHT 10 

using namespace std;

int startx = 0;
int starty = 0;

vector<string> choices = { 
			"Choice 1",
			"Choice 2",
			"Choice 3",
			"Choice 4",
			"Exit",
		  };

int n_choices = choices.size();
void print_menu(WINDOW *menu_win, int highlight);

int main()
{	
    WINDOW *menu_win;
	int highlight = 1;
	int choice = 0;
	int c;

	clear();
	noecho();
	cbreak();	/* Line buffering disabled. pass on everything */
	startx = (80 - WIDTH) / 2;
	starty = (24 - HEIGHT) / 2;

    	
	menu_win = newwin(HEIGHT, WIDTH, starty, startx);
	keypad(menu_win, TRUE);
	mvprintw(0, 0, "Use arrow keys to go up and down, Press enter to select a choice");
	refresh();
	print_menu(menu_win, highlight);
	while(1)
	{	
        c = wgetch(menu_win);
		switch(c)
		{	
            case KEY_UP:
				if(highlight == 1)
					highlight = n_choices;
				else
					--highlight;
				break;
			case KEY_DOWN:
				if(highlight == n_choices)
					highlight = 1;
				else 
					++highlight;
				break;
			case 10:
				choice = highlight;
				break;
			default:
				mvprintw(24, 0, "Charcter pressed is = %3d Hopefully it can be printed as '%c'", c, c);
				refresh();
				break;
		}
		print_menu(menu_win, highlight);
		if(choice != 0)
			break;
	}

	// mvprintw(23, 0, "You chose choice %d with choice string %s\n", choice, choices[choice - 1]);
	refresh();
	clrtoeol();
    auto toto = delwin(menu_win);
	endwin();
    // auto toto = delwin(screen);
    // cout << toto << endl;
	return 0;
}


void print_menu(WINDOW *menu_win, int highlight)
{
	int x, y, i;	

	x = 2;
	y = 2;
	box(menu_win, 0, 0);
	for(i = 0; i < n_choices; ++i)
	{	if(highlight == i + 1) /* High light the present choice */
		{	wattron(menu_win, A_REVERSE); 
			mvwprintw(menu_win, y, x, "%s", choices[i]);
			wattroff(menu_win, A_REVERSE);
		}
		else
			mvwprintw(menu_win, y, x, "%s", choices[i]);
		++y;
	}
	wrefresh(menu_win);
}