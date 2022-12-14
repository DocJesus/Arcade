#include <memory>
#include <iostream>
#include <thread>
#include "BrickBreaker.hpp"
#include "NCurse.hpp"
#include "OpenGL.hpp"

using namespace std;

class Arcade
{
    private:
        unique_ptr<AGame> game;
        unique_ptr<OpenGL> graphic;
        // unique_ptr<AGraphic> graphic;

        string input;
    public:
        Arcade()
        {
            this->graphic = make_unique<OpenGL>();
        }
        ~Arcade()
        {
            cout << "Arcade's destructor" << endl;
        }

        void Update();
        void RetrieveInputs();
        void InitGame();
};