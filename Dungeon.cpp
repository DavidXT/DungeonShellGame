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
                gameRoom[j][i].shop = true;
                gameRoom[j][i].E = new Ennemy(100*stages,50*stages,100000*stages, 1000*stages);
            }
            else {
                std::cout << map;
                int tempTreasure = rand() % 3;
                int tempMonster = rand() % 4;
                if (tempTreasure == 1) {
                    gameRoom[j][i].treasure = true;
                }
                if (tempMonster == 2) {
                    gameRoom[j][i].ennemy = true;
                    gameRoom[j][i].E = new Ennemy((rand() % 20 + 1)*stages, (rand()%5 + 1)*stages,(rand()%20 + 1)*stages, (rand()%30 + 1)*stages);
                }
                gameRoom[j][i].isVisited = false;
            }
        }
        std::cout << "\n";
    }
}

int Dungeon::getStages() {
    return stages;
}

void Dungeon::checkMap() {
    std::cout << "\n";
    for (int i = tailleDungeon; i >= 0; i--) {
        for (int j = 0; j < tailleDungeon; j++) {
            if (coordX == j && coordY == i) {
                std::cout << player;
            }
            //else if (winX == j && winY == i) {
            //    std::cout << "E";
            //}
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
    if (gameRoom[coordX][coordY].ennemy) {
        std::cout << "There is a monster here!\n";
    }
    if (gameRoom[coordX][coordY].shop) {
        std::cout << "There is a Shop here!\n";
    }
}
void Dungeon::nextStages() {
    if (coordX == winX && coordY == winY) {
        stages++;
        Dungeon::roomGeneration();
        std::cout << "Welcome to stages : " << stages;
    }
}

void Dungeon::generateExit() {
    winX = rand() % 9;
    winY = rand() % 9;
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
        std::cout << "You found some stairs wanna go up?\n";
    }
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
    if (coordX == winX && coordY == winY) {
        std::cout << "[G]o up\n";
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
        std::cout << "[F]ight the shop keeper!\n";
        std::cout << "[E]xit shop.\n";
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
            case 'F':
            case 'f':
                gameRoom[coordX][coordY].ennemy = true;
                fightMonster(p);
        }
    }
    else {
        std::cout << "No shop here!\n";
    }
}

void Dungeon::fightMonster(Player *p) {
    if (gameRoom[coordX][coordY].ennemy) {
        std::cout << "\Monster Stats : \n\nHP : " << gameRoom[coordX][coordY].E->getHealth() <<
            "\nSTR :" << gameRoom[coordX][coordY].E->getStrenght() << "\nGold :" << gameRoom[coordX][coordY].E->getMoney() << "\n"
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



