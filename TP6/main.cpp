#include <iostream>
#include "Game.hpp"
#include "Start.hpp"
#include "Land.hpp"


int main() 
{
    GGame = new Game;

    GGame->start();
    Case* dernier = new Start();
    dernier = new Land();

    delete GGame;
    return 0;
}
