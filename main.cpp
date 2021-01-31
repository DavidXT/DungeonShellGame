#include "Dungeon.h"
#include "Player.h"
#include <iostream>

Player *P = new Player(20, 5, 0);
Ennemy E(20,2,0);
Dungeon Test;
std::string userInput;

int main()
{
    std::cout << "----- Game Start ! -----\n";
    do
    {
        std::cout << '\n' << "Press start to start the game\n";
    } while (std::cin.get() != '\n');
    srand(time(NULL));
    Test.generateExit();
    Test.roomGeneration();
    do {
        Test.checkAction();
        std::cin >> userInput;
        if (userInput == "D" || userInput == "d") {
            Test.move();
            Test.checkRoom();
        }
        if (userInput == "M" || userInput == "m") {
            Test.checkMap();
        }
        if (userInput == "T" || userInput == "t") {
            srand(time(NULL));
            Test.checkTreasure(P);
        }
        if (userInput == "S" || userInput == "s") {
            P->checkPlayerStatus();
        }
        if (userInput == "F" || userInput == "f") {
            P->fightMonster(E);
        }
    } while (P->getHealth() > 0);
    std::cout << "---- GAME OVER ----";
}

