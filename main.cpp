#include "Dungeon.h"
#include <iostream>

void move();
void generateExit();
void roomGeneration();
void generateRandomStart();
void checkRoom();
void checkTreasure(Player playerdata);
void checkMap();
void checkPlayerStatus();
void checkAction();
void fightMonster();

Player player;
int HP = 5;
std::string userInput;

int main()
{
    std::cout << "----- Game Start ! -----\n";
    do
    {
        std::cout << '\n' << "Press start to start the game\n";
    } while (std::cin.get() != '\n');
    generateRandomStart();
    generateExit();
    roomGeneration();
    do {
        checkAction();
        std::cin >> userInput;
        if (userInput == "D" || userInput == "d") {
            move();
            checkRoom();
        }
        if (userInput == "M" || userInput == "m") {
            checkMap();
        }
        if (userInput == "T" || userInput == "t") {
            checkTreasure(player);
        }
        if (userInput == "S" || userInput == "s") {
            checkPlayerStatus();
        }
        if (userInput == "F" || userInput == "f") {
            fightMonster();
        }
    } while (HP > 0);
    std::cout << "---- GAME OVER ----";
}

