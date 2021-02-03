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
    dungeon.roomGeneration();
    do {
        dungeon.checkAction();
        std::cin >> userInput;
        if (userInput == "D" || userInput == "d") {
            dungeon.move();
            std::cout << "\033c";
            dungeon.checkRoom();
        }
        if (userInput == "M" || userInput == "m") {
            std::cout << "\033c";
            dungeon.checkMap();
        }
        if (userInput == "T" || userInput == "t") {
            std::cout << "\033c";
            dungeon.checkTreasure(P);
        }
        if (userInput == "P" || userInput == "p") {
            std::cout << "\033c";
            P->checkPlayerStatus();
        }
        if (userInput == "F" || userInput == "f") {
            std::cout << "\033c";
            dungeon.fightMonster(P);
        }
        if (userInput == "S" || userInput == "s") {
            std::cout << "\033c";
            dungeon.shop(P);
        }
        if (userInput == "G" || userInput == "g") {
            std::cout << "\033c";
            dungeon.nextStages();
        }
    } while (P->getHealth() > 0);
    std::cout << "---- GAME OVER ----";
    P->checkPlayerStatus();
    std::cout << "Stage : " << dungeon.getStages();
}

