#include <memory>
#include <iostream>
#include <thread>
#include "BrickBreaker.hpp"
#include "Snake.hpp"
#include "NCurse.hpp"
#include "SFML.hpp"
#include "Error.hpp"

using namespace std;

class Arcade
{
    private:
        vector<shared_ptr<AGame>> games;
        vector<shared_ptr<AGraphic>> graphics;

        string input;
        int game_iterator;
        int graphic_iterator;
    public:

        Arcade()
        {
            this->graphics.push_back(make_shared<NCurse>());
            this->graphics.push_back(make_shared<SFML>());
            this->graphic_iterator = 0;

            this->games.push_back(make_unique<Snake>(60, 60));
            this->games.push_back(make_unique<BrickBreaker>(40, 120));
            this->game_iterator = 0;
        }
        ~Arcade()
        {
            cout << "Arcade's destructor" << endl;
        }

        void Update();
        void RetrieveInputs();
        void Init();
        shared_ptr<AGraphic> getCurrentGraphic();
        shared_ptr<AGame> getCurrentGame();
        void ChangeGraphic(int _input);
        void ChangeGame(int _input);
};