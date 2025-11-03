#include <iostream>

#include "Game.h"

Game* firstGame = new Game(1920, 1080, "Toto");

int main()
{
    firstGame->StartGame();
    delete firstGame;
}

