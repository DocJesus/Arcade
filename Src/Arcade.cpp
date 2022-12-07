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

void Arcade::InitGame()
{
    int height, width;

    this->graphic->getWinSize(&height, &width);
    this->game = make_unique<BrickBreaker>(height, width);
}

void Arcade::Update()
{
    int input;
    signal(SIGINT, SignalCallbackHandler);

    try
    {
        this->graphic->InitScreen();
        this->InitGame();
        while (!stop)
        {
            input = this->graphic->GetInputs();
            if (input == 10)
                stop = 1;
            // this->game.GameUpdate(this->get_inputs());
            this->graphic->Render(this->game->getMap(), this->game->getStartPosX(), this->game->getStartPosY());
        }
    }
    catch (const exception& _e)
    {
        cerr << _e.what();
    }
    this->graphic->CloseScreen();
    cout << "See you around" << endl;
}