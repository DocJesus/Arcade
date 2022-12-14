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
    // int height, width;

    this->graphic->InitScreen();
    // this->graphic->getWinSize(&height, &width);
    // this->game = make_unique<BrickBreaker>(height, width);
    this->game = make_unique<BrickBreaker>(40, 120);
    this->game->InitGame();
    // this->graphic->Render(this->game->getMap(), this->game->getStartPosX(), this->game->getStartPosY());
    this->graphic->Render();
}

void Arcade::Update()
{
    // vector<int> input;
    int input;

    signal(SIGINT, SignalCallbackHandler);

    try
    {
        while (!stop)
        {
            // input = this->graphic->ReadInputs();
            if (input == 10)
                stop = 1;

            this->game->GameUpdate(input);
            // this->graphic->Render(this->game->getMap(), this->game->getStartPosX(), this->game->getStartPosY());
            usleep(100000);
        }
    }
    catch (const exception& _e)
    {
        cerr << _e.what();
    }
    this->graphic->CloseScreen();
    cout << "See you around" << endl;
}