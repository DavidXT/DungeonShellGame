#include "Dungeon.h"
#include <iostream>


int coordX, coordY;
int winX, winY;
int tailleDungeon = 10;
bool gameMap[10][10];
Room gameRoom[10][10];
char player = 'P';
char map = '#';
std::string user;
Player PlayerData;


void roomGeneration() {
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

void checkPlayerStatus() {
    std::cout << "\nPlayer Stats : \nHP : " << PlayerData.getHealth() << 
        "\nSTR :" << PlayerData.getStrenght() << "\nGold :" <<PlayerData.getMoney() << "\n";
}

void checkMap() {
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

void checkRoom() {
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

void generateRandomStart() {
    coordX = rand() % 10;
    coordY = rand() % 10;
}

void generateExit() {
    winX = rand() % 10;
    winY = rand() % 10;
}

void move()
{
    std::cout << "\Go to :";
    if (coordY < tailleDungeon) {
        std::cout << "[N]orth ";
    }
    if (coordY >= 0) {
        std::cout << "[S]outh ";
    }
    if (coordX < tailleDungeon) {
        std::cout << "[E]st ";
    }
    if (coordX >= 0) {
        std::cout << "[W]est";
    }
    std::cout << "\n";
    std::cin >> user;
    if ((user == "n" || user == "N") && coordY < tailleDungeon) {
        coordY++;
    }
    if ((user == "s" || user == "S") && coordY >= 0) {
        coordY--;
    }
    if ((user == "e" || user == "E") && coordX < tailleDungeon) {
        coordX++;
    }
    if ((user == "w" || user == "W") && coordX >= 0) {
        coordX--;
    }
}

void checkAction() {
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


void checkTreasure(Player playerData) {
    if (gameRoom[coordX][coordY].treasure == true) {
        std::cout << "Open Treasure? [Y]es [N]o\n";
        do {
            std::cin >> user;
        } while (user != "Y" && user != "N" && user != "y" && user != "n");
        if (user == "Y") {
            std::cout << "Treasure opened\n";
            int tempMoney = rand() % 30 + 20;
            playerData.gainMoney(tempMoney);
            std::cout << "+" << tempMoney << "golds!\n";
            std::cout << "Total : " << playerData.getMoney() << "golds!";
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

void fightMonster() {
    //Fight Monster Here
}


