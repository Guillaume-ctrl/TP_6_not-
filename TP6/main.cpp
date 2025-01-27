#include <iostream>
#include "Game.hpp"
#include "Dice.hpp"
#include "Case.hpp"

int main()
{
    GGame = new Game();

    while (true)
    {
        try {
            GGame->play();
            GGame->checkPlayer();
            if (GGame->hasEnded()) break;
        } 
        catch (const std::runtime_error& e) {
            std::cerr << "Runtime Error: " << e.what() << std::endl;

        }
        catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;

        }
    }
    
    std::cout << "The Game Has Ended!";

    delete GGame;
    return 0;
}
