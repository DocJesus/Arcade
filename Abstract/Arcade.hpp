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
        vector<shared_ptr<AGraphic>> graphics;

        string input;
        int graphic_iterator;
    public:

        Arcade()
        {
            this->graphics.push_back(make_shared<SFML>());
            this->graphics.push_back(make_shared<NCurse>());

            this->graphic_iterator = 0;
        }
        ~Arcade()
        {
            cout << "Arcade's destructor" << endl;
        }

        void Update();
        void RetrieveInputs();
        void Init();
        shared_ptr<AGraphic> getCurrentGraphic();
        void ChangeGraphic(int _input);
};