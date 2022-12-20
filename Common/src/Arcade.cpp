#include <iostream>
#include <csignal>
#include <unistd.h>
#include "Arcade.hpp"

volatile sig_atomic_t stop;

void SignalCallbackHandler(int _signum)
{
    cout << "Caugth Signal " << _signum << endl;
    cout << "Exiting" << endl;
    stop = 1;
}

void Arcade::RetrieveInputs()
{

}

void Arcade::Init()
{
    int height, width;

    this->getCurrentGraphic()->InitScreen();
    this->getCurrentGraphic()->getWinSize(&height, &width);

    // this->game = make_unique<BrickBreaker>(height, width);
    this->game = make_unique<BrickBreaker>(40, 120);
    // this->game = make_unique<Snake>(60, 60);

    this->game->InitGame();
    this->getCurrentGraphic()->Render(this->game->getMap(), this->game->getWidth(), this->game->getHeigh());
}

void Arcade::Update()
{
    // vector<int> input;
    int input = 0;

    signal(SIGINT, SignalCallbackHandler);

    try
    {
        while (!stop)
        {
            input = this->getCurrentGraphic()->ReadInputs();
            if (input == 10)
                stop = 1;

            if (input == GRAPHICAL_DOWN || input == GRAPHICAL_UP)
                this->ChangeGraphic(input);
            this->game->GameUpdate(input);
            this->getCurrentGraphic()->Render(this->game->getMap(), this->game->getWidth(), this->game->getHeigh());

            usleep(100000);
        }
    }
    catch (const exception& _e)
    {
        cerr << _e.what();
    }
    this->getCurrentGraphic()->CloseScreen();
    cout << "See you around" << endl;
}

shared_ptr<AGraphic> Arcade::getCurrentGraphic()
{
    return this->graphics[this->graphic_iterator];
}

void Arcade::ChangeGraphic(int _input)
{
    this->getCurrentGraphic()->CloseScreen();
    if (_input == GRAPHICAL_DOWN)
    {
        if (this->graphic_iterator == 0)
            this->graphic_iterator = this->graphics.size() - 1;
        else
            this->graphic_iterator--;
    }
    else if (_input == GRAPHICAL_UP)
    {
        if (this->graphic_iterator == int(this->graphics.size()) - 1)
            this->graphic_iterator = 0;
        else
            this->graphic_iterator++;
    }
    this->getCurrentGraphic()->InitScreen();
}