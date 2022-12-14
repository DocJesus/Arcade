#include <memory>
#include <iostream>
#include <thread>
#include "BrickBreaker.hpp"
#include "NCurse.hpp"
#include "OpenGL.hpp"
#include "Error.hpp"

using namespace std;

class Arcade
{
    private:
        unique_ptr<AGame> game;
        // unique_ptr<AGraphic> graphic;

        string input;
    public:
        unique_ptr<OpenGL> graphic;

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