#include <memory>
#include <iostream>
#include <thread>
#include "BrickBreaker.hpp"
#include "NCurse.hpp"
#include "SFML.hpp"
#include "Error.hpp"

using namespace std;

class Arcade
{
    private:
        unique_ptr<AGame> game;
        unique_ptr<AGraphic> graphic;

        string input;
    public:

        Arcade()
        {
            this->graphic = make_unique<SFML>();
        }
        ~Arcade()
        {
            cout << "Arcade's destructor" << endl;
        }

        void Update();
        void RetrieveInputs();
        void InitGame();
};