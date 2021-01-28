#include "Dungeon.h"
#include <iostream>

std::string user;

void Dungeon::roomGeneration() {
    std::cout << "\n";
    for (int i = tailleDungeon; i>= 0; i--) {
        for (int j = 0; j <= tailleDungeon; j++) {
            if (coordX == j && coordY == i) {
                std::cout << player;
                gameMap[i][j] = true;
            }
            else {
                std::cout << map;
                gameMap[i][j] = false;
            }
        }
        std::cout << "\n";
    }
}



void Dungeon::checkMap() {
    std::cout << "\n";
    std::cout << "Player location : " << coordX << ", " << coordY << "\n";
    for (int i = tailleDungeon; i >= 0; i--) {
        for (int j = 0; j <= tailleDungeon; j++) {
            if (coordX == j && coordY == i) {
                std::cout << player;
            }
            else {
                std::cout << map;
            }
        }
        std::cout << "\n";
    }
}

void Dungeon::checkRoom() {
    if (gameMap[coordX][coordY]) {
        std::cout << "Room already explored !\n";
    }
    else {
        int tempTreasure = rand() % 3;
        int tempMonster = rand() % 3;
        if(tempTreasure == 1) {
            gameRoom[coordX][coordY].treasure = true;
            std::cout << "There is a treasure here! \n";
        }
        else {
            std::cout << "No treasure here\n";
        }
        if(tempMonster == 2){ 
            gameRoom[coordX][coordY].ennemy= true;
            std::cout << "There is a monster here!\n";
        }
        else {
            std::cout << "No monster here\n";
        }
        gameMap[coordX][coordY] = true;
    }
}

void Dungeon::generateRandomStart() {
    coordX = rand() % 10;
    coordY = rand() % 10;
}

void Dungeon::generateExit() {
    winX = rand() % 10;
    winY = rand() % 10;
}

void Dungeon::move()
{
    std::cout << "\nGo to :";
    if (coordY < tailleDungeon) {
        std::cout << "[N]orth ";
    }
    if (coordY > 0) {
        std::cout << "[S]outh ";
    }
    if (coordX < tailleDungeon) {
        std::cout << "[E]st ";
    }
    if (coordX > 0) {
        std::cout << "[W]est";
    }
    std::cout << "\n";
    std::cin >> user;
    if ((user == "n" || user == "N") && coordY < tailleDungeon) {
        coordY++;
    }
    if ((user == "s" || user == "S") && coordY > 0) {
        coordY--;
    }
    if ((user == "e" || user == "E") && coordX < tailleDungeon) {
        coordX++;
    }
    if ((user == "w" || user == "W") && coordX > 0) {
        coordX--;
    }
}

void Dungeon::checkAction() {
    if (coordX == winX && coordY == winY) {
        std::cout << "You found the exit!! \nPress [E] to end the game\n";
    }
    else {
        std::cout << "\nPlayer actions :\n\n[D]Move\n[M]ap\n[S]tatus\n";
        if (gameRoom[coordX][coordY].treasure == true) {
            std::cout << "[T]reasure\n";
        }
        if (gameRoom[coordX][coordY].ennemy == true) {
            std::cout << "[F]ight\n";
        }
    }
}


void Dungeon::checkTreasure(Player *p) {
    if (gameRoom[coordX][coordY].treasure == true) {
        std::cout << "Open Treasure? [Y]es [N]o\n";
        do {
            std::cin >> user;
        } while (user != "Y" && user != "N" && user != "y" && user != "n");
        if (user == "Y") {
            std::cout << "Treasure opened\n";
            int tempMoney = rand() % 30 + 20;
            p->gainMoney(tempMoney);
            std::cout << "+" << tempMoney << "golds!\n";
            std::cout << "Total : " << p->getMoney() << "golds!";
            gameRoom[coordX][coordY].treasure = false;
        }
        if (user == "N") {
            std::cout << "Treasure skipped\n";
        }
    }
    else {
        std::cout << "No treasure here\n";
    }
}



