#include "Arcade.hpp"

int main()
{
    Arcade arc = Arcade();
    
    try
    {
        arc.InitGame();
        // arc.Update();
    }
    catch(Error &e)
    {
        cout << e.what() << endl;
    }
    
    return 0;
}