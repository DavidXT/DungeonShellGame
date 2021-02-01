#include "Dungeon.h"
#include <iostream>
#include <stdio.h>
std::string user;

void Dungeon::roomGeneration() {
    std::cout << "\n";
    coordX = rand() % 10;
    coordY = rand() % 10;
    for (int i = tailleDungeon; i>= 0; i--) {
        for (int j = 0; j < tailleDungeon; j++) {
            if (coordX == j && coordY == i) {
                std::cout << player;
                gameRoom[j][i].isVisited = true;
            }
            else {
                std::cout << map;
                int tempShop = rand() % 50;
                int tempTreasure = rand() % 3;
                int tempMonster = rand() % 4;
                if (tempTreasure == 1) {
                    gameRoom[j][i].treasure = true;
                }
                if (tempMonster == 2) {
                    gameRoom[j][i].ennemy = true;
                    gameRoom[j][i].E = new Ennemy(rand() % 20 + 1, rand()%5 + 1,rand()%20 + 1);
                }
                if (i * j == tempShop) {
                    gameRoom[j][i].shop = true;
                }
                gameRoom[j][i].isVisited = false;
            }
        }
        std::cout << "\n";
    }
}



void Dungeon::checkMap() {
    std::cout << "\n";
    std::cout << "Player location : " << coordX << ", " << coordY << "\n";
    for (int i = tailleDungeon; i > 0; i--) {
        for (int j = 0; j < tailleDungeon; j++) {
            if (coordX == j && coordY == i) {
                std::cout << player;
            }
            else {
                if (gameRoom[j][i].shop) {
                    std::cout << 'S';
                }
                else{
                    if (gameRoom[j][i].isVisited) {
                        std::cout << discovered;
                    }
                    else {
                        std::cout << map;
                    }
                }
            }
        }
        std::cout << "\n";
    }
}

void Dungeon::checkRoom() {
    if (!gameRoom[coordX][coordY].isVisited) {
        gameRoom[coordX][coordY].isVisited = true;
    }
    if (gameRoom[coordX][coordY].treasure) {
        std::cout << "There is a treasure here! \n";
    }
    else {
        std::cout << "No treasure here\n";
    }
    if (gameRoom[coordX][coordY].ennemy) {
        std::cout << "There is a monster here!\n";
    }
    else {
        std::cout << "No monster here\n";
    }
    if (gameRoom[coordX][coordY].shop) {
        std::cout << "There is a Shop here!\n";
    }
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
    if (coordY > 1) {
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
    if ((user == "s" || user == "S") && coordY > 1) {
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
        std::cout << "\nPlayer actions :\n\n[D]Move\n[M]ap\n[P]layer status\n";
        if (gameRoom[coordX][coordY].shop == true) {
            std::cout << "[S]hop\n";
        }
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

void Dungeon::shop(Player* p) {
    if (gameRoom[coordX][coordY].shop == true) {
        if (p->getMoney() >= 10) {
            std::cout << "Welcome customer!\n\n";
        }
        else {
            std::cout << "GET OUT!\n";
        }

        if (dungeonShop.sword == true && p->getMoney() >= 20) {
            std::cout << "Buy [S]word for 20 golds?\n";
        }
        if (dungeonShop.armor == true && p->getMoney() >= 35) {
            std::cout << "Buy [A]rmor for 35 golds?\n";
        }
        if (p->getMoney() >= 10) {
            std::cout << "Buy [P]otion for 10 golds?\n";
        }
        std::cout << "[E]xit shop.";
        char shopInput;
        std::cin >> shopInput;
        switch (shopInput) {
            case 'S':
            case 's': 
                dungeonShop.sword = false;
                p->gainStrenght(3);
                p->loseMoney(20);
                break;
            case'A':
            case'a':
                dungeonShop.armor = false;
                p->gainHealth(10);
                p->loseMoney(35);
                break;
            case 'P':
            case 'p':
                p->heal(5);
                p->loseMoney(10);
                break;
            case 'E':
            case 'e':
                checkAction();
                break;
        }
    }
    else {
        std::cout << "No shop here!\n";
    }
}

void Dungeon::fightMonster(Player *p) {
    if (gameRoom[coordX][coordY].ennemy) {
        std::cout << "\Monster Stats : \nHP : " << gameRoom[coordX][coordY].E->getHealth() <<
            "\nSTR :" << gameRoom[coordX][coordY].E->getHealth() << "\nGold :" << gameRoom[coordX][coordY].E->getMoney() << "\n"
            << "Wanna fight?\n[Y]es [N]o\n";
        std::cin >> user;
        do {
            if (user == "Y" || user == "y") {
                do {
                    std::cout << "Player attack!\n";
                    gameRoom[coordX][coordY].E->getDamage(p->getStrenght());
                    std::cout << gameRoom[coordX][coordY].E->getHealth() << "HP left (monster).\n";
                    if (gameRoom[coordX][coordY].E->getHealth() > 0) {
                        std::cout << "Monster attack!\n";
                        p->getDamage(gameRoom[coordX][coordY].E->getStrenght());
                        std::cout << p->getHealth() << "HP left (player).\n";
                    }
                    else {
                        std::cout << "Monster is Dead!\n";
                        std::cout << "You gain " << gameRoom[coordX][coordY].E->getMoney() << "\n";
                        p->gainMoney(gameRoom[coordX][coordY].E->getMoney());
                    }
                } while (p->getHealth() > 0 && gameRoom[coordX][coordY].E->getHealth() > 0);
                if (p->getHealth() <= 0) {
                    std::cout << "GAME OVER\n";
                }
            }
            if (user == "N" || user == "n") {
                p->runAway();
            }
        } while (user != "Y" && user != "y" && user != "N" && user != "n");
    }
    else {
        std::cout << "No monster here!\n";
    }
}



