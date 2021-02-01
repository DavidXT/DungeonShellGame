#include "Dungeon.h"
#include <iostream>

Player *P = new Player(20, 5, 0);
Dungeon dungeon;
std::string userInput;

int main()
{
    std::cout << "----- Game Start ! -----\n";
    do
    {
        std::cout << '\n' << "Press start to start the game\n";
    } while (std::cin.get() != '\n');
    srand(time(NULL));
    dungeon.generateExit();
    dungeon.roomGeneration();
    do {
        dungeon.checkAction();
        std::cin >> userInput;
        if (userInput == "D" || userInput == "d") {
            dungeon.move();
            dungeon.checkRoom();
        }
        if (userInput == "M" || userInput == "m") {
            dungeon.checkMap();
        }
        if (userInput == "T" || userInput == "t") {
            dungeon.checkTreasure(P);
        }
        if (userInput == "P" || userInput == "p") {
            P->checkPlayerStatus();
        }
        if (userInput == "F" || userInput == "f") {
            dungeon.fightMonster(P);
        }
        if (userInput == "S" || userInput == "s") {
            dungeon.shop(P);
        }
        if (userInput == "G" || userInput == "g") {
            dungeon.nextStages();
        }
    } while (P->getHealth() > 0);
    std::cout << "---- GAME OVER ----";
    P->checkPlayerStatus();
    std::cout << "Stage : " << dungeon.getStages();
}

