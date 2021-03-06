#include "Dungeon.h"
#include <iostream>
#include <stdio.h>
std::string user;

//COLOR
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

void Dungeon::roomGeneration() {
    std::cout << "\n";
    coordX = rand() % 10;
    coordY = rand() % 10;
    do {
        winX = rand() % 9;
        winY = rand() % 9;
    } while (coordX == winX && coordY == winY);
    for (int i = tailleDungeon; i>= 0; i--) {
        std::cout << "      ";
        for (int j = 0; j < tailleDungeon; j++) {
            if (coordX == j && coordY == i) {
                gameRoom[j][i].isVisited = true;
                gameRoom[j][i].shop = true;
                gameRoom[j][i].E = new Ennemy(100*stages,50*stages,100000*stages, 1000*stages);
            }
            else if (winX == j && winY == i) {
                gameRoom[j][i].ennemy = true;
                gameRoom[j][i].E = new Ennemy(100 * stages, 7 * stages, 50 * stages, 100 * stages);
            }
            else {
                int tempTreasure = rand() % 3;
                int tempMonster = rand() % 4;
                if (tempTreasure == 1) {
                    gameRoom[j][i].treasure = true;
                }
                if (tempMonster == 2) {
                    gameRoom[j][i].ennemy = true;
                    gameRoom[j][i].E = new Ennemy((rand() % 31 + 10)*stages, (rand()%11 + 1)*stages,(rand()%26 + 10)*stages, (rand()%36 + 10)*stages);
                }
                gameRoom[j][i].isVisited = false;
            }
        }
    }
}

int Dungeon::getStages() {
    return stages;
}

void Dungeon::checkMap() {
    std::cout << GREEN << "\n -------- MAP -------- \n\n" << RESET;
    for (int i = tailleDungeon; i >= 0; i--) {
        std::cout << "      ";
        for (int j = 0; j < tailleDungeon; j++) {
            if (coordX == j && coordY == i) {
                std::cout << player;
            }        
            //else    if (winX == j && winY == i) {
            //    std::cout << "E";
            //}
            else {
                if (gameRoom[j][i].shop) {
                    std::cout << GREEN <<'S'<< RESET;
                }
                else{
                    if (gameRoom[j][i].isVisited) {
                        std::cout << RED << map << RESET;
                    }
                    else {
                        std::cout << map;
                    }
                }
            }
        }

        std::cout << "\n";
    }
    std::cout << GREEN <<" ---------------------" <<RESET;
}

void Dungeon::checkRoom() {
    std::cout << "\n";
    if (!gameRoom[coordX][coordY].isVisited) {
        gameRoom[coordX][coordY].isVisited = true;
    }
    if (gameRoom[coordX][coordY].treasure) {
        std::cout << BOLDGREEN << "There is a treasure here! \n" << RESET;
    }
    if (gameRoom[coordX][coordY].ennemy && (winX != coordX && winY != coordY)) {
        std::cout << BOLDRED << "There is a monster here!\n" << RESET;
    }
    if (gameRoom[coordX][coordY].shop) {
        std::cout << BOLDGREEN <<"There is a Shop here!\n" << RESET;
    }
}
void Dungeon::nextStages(Player *p) {
    if (coordX == winX && coordY == winY) {
        if (gameRoom[coordX][coordY].ennemy) {
            std::cout << "\nA monster block the staires\n";
            fightMonster(p);
            stages++;
            Dungeon::roomGeneration();
            std::cout << BOLDRED << "\nWelcome to stages : " << stages << RESET <<"\n";
        }
        else {
            stages++;
            Dungeon::roomGeneration();
            std::cout << BOLDRED << "\nWelcome to stages : " << stages << RESET <<"\n";
        }
    }
}

void Dungeon::move()
{
    std::cout << "\nGo to :";
    if (coordY < tailleDungeon) {
        std::cout << CYAN<<"[N]"<<RESET<<"orth ";
    }
    if (coordY > 0) {
        std::cout << CYAN<<"[S]"<<RESET<<"outh ";
    }
    if (coordX < tailleDungeon) {
        std::cout << CYAN<<"[E]"<<RESET<<"st ";
    }
    if (coordX > 0) {
        std::cout << CYAN<<"[W]"<<RESET<<"est";
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
    std::cout << "\nPlayer actions :\n\n" << CYAN "[D]" << RESET << "Move\n"<<CYAN <<"[M]"<< RESET "ap\n"<<CYAN"[P]"<<RESET<<"layer status\n"<<CYAN<<"[I]"<<RESET<<"nventory\n";
    if (gameRoom[coordX][coordY].shop == true) {
        std::cout << CYAN << "[S]" << RESET << "hop\n";
    }
    if (gameRoom[coordX][coordY].treasure == true) {
        std::cout << CYAN <<"[T]"<< RESET <<"reasure\n";
    }
    if (gameRoom[coordX][coordY].ennemy == true && (winY != coordY && winX != coordX)) {
        std::cout << CYAN << "[F]" << RESET << "ight\n";
    }
    if (coordX == winX && coordY == winY) {
        std::cout << CYAN <<"[G]" << RESET <<"o up\n";
    }
}


void Dungeon::checkTreasure(Player *p) {
    if (gameRoom[coordX][coordY].treasure == true) {
        std::cout << "Open Treasure? " << CYAN << "[Y]" << RESET "es "<<CYAN<<"[N]"<<RESET"o\n";
        do {
            std::cin >> user;
        } while (user != "Y" && user != "N" && user != "y" && user != "n");
        if (user == "Y" || user == "y") {
            std::cout << "Treasure opened\n";
            int tempMoney = rand() % 30 + 20;
            p->gainMoney(tempMoney);
            std::cout << GREEN << "+" << tempMoney << "golds!\n" ;
            std::cout << "Total : " << p->getMoney() << "golds!" << RESET;
            gameRoom[coordX][coordY].treasure = false;
        }
        if (user == "N" || user == "n") {
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
            std::cout << "You don't have enough money to buy anything!\n";
        }
        char shopInput;
        do {
            if (dungeonShop.sword == true && p->getMoney() >= dungeonShop.swordprice) {
                std::cout << "Buy "<<CYAN<<"[S]"<<RESET<<"word for " << dungeonShop.swordprice << " golds?\n";
            }
            else if (dungeonShop.sword == false && p->getMoney() >= dungeonShop.swordprice && p->getSwordLevel() < 5) {
                std::cout << "Upgrade " << CYAN << "[S]" << RESET "word for "<< dungeonShop.swordprice <<" golds?\n";
            }
            if (dungeonShop.armor == true && p->getMoney() >= dungeonShop.armorprice) {
                std::cout << "Buy " << CYAN << "[A]" << RESET << "rmor for " << dungeonShop.armorprice << " golds?\n";
            }
            else if (dungeonShop.armor == false && p->getMoney() >= dungeonShop.armorprice && p->getArmorLevel() < 5) {
                std::cout << "Upgrade " << CYAN << "[A]" << RESET "rmor for " << dungeonShop.armorprice << " golds?\n";
            }
            if (p->getMoney() >= 10) {
                std::cout << "Buy " << CYAN << "[P]" << RESET << "otion for 10 golds?\n";
            }
            std::cout << "" << CYAN << "[F]" << RESET << "ight the shop keeper!\n";
            std::cout << "" << CYAN << "[E]" << RESET << "xit shop.\n";
            std::cin >> shopInput;
            if (shopInput == 'S' || shopInput == 's') {
                if (p->getSwordLevel() < 5) {
                    if (dungeonShop.sword == true) {
                        dungeonShop.sword = false;
                    }
                    p->gainSwordLevel();
                    p->loseMoney(dungeonShop.swordprice);
                    std::cout << "Thanks you for your purchase\n";
                    dungeonShop.swordprice += 10;
                }
            }
            if (shopInput == 'A' || shopInput == 'a') {
                if (p->getArmorLevel() < 5) {
                    if (dungeonShop.armor == true) {
                        dungeonShop.armor = false;
                    }
                    p->gainArmorLevel();
                    p->loseMoney(dungeonShop.armorprice);
                    std::cout << "Thanks you for your purchase\n";
                    dungeonShop.armorprice += 15;
                }
            }
            if (shopInput == 'P' || shopInput == 'p') {
                p->addHealPotion();
                p->loseMoney(dungeonShop.potionprice);
                std::cout << "Thanks you for your purchase\n";
            }
            if (shopInput == 'F' || shopInput == 'f') {
                gameRoom[coordX][coordY].ennemy = true;
                fightMonster(p);
            }
        } while (shopInput != 'E' && shopInput !='e');
    }
    else {
        std::cout << "No shop here!\n";
    }
}

void Dungeon::fightMonster(Player *p) {
    if (gameRoom[coordX][coordY].ennemy) {
        std::cout << RED << "\------- Monster Stats ------- \n\nHP : " << gameRoom[coordX][coordY].E->getHealth() <<
            "\nSTR :" << gameRoom[coordX][coordY].E->getStrenght() << "\nGold :" << gameRoom[coordX][coordY].E->getMoney() <<"\n-----------------------------" << RESET << "\n"
            << "Wanna fight?\n" << CYAN << "[Y]" << RESET << "es " << CYAN << "[N]" << RESET << "o\n";
        do {
            std::cin >> user;
            if (user == "Y" || user == "y") {
                do {
                    std::cout << GREEN << "Player attack!\n" << RESET;
                    gameRoom[coordX][coordY].E->getDamage(p->getStrenght());
                    std::cout << gameRoom[coordX][coordY].E->getHealth() << "HP left (monster).\n";
                    if (gameRoom[coordX][coordY].E->getHealth() > 0) {
                        std::cout << RED << "Monster attack!\n" << RESET;
                        p->getDamage(gameRoom[coordX][coordY].E->getStrenght());
                        std::cout << p->getHealth() << "HP left (player).\n";
                    }
                    else {
                        std::cout << "Monster is Dead!\n";
                        std::cout << "You gain " << gameRoom[coordX][coordY].E->getMoney() << "\n";
                        p->gainMoney(gameRoom[coordX][coordY].E->getMoney());
                        p->gainExp(gameRoom[coordX][coordY].E->getExp());
                        gameRoom[coordX][coordY].ennemy = false;
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



