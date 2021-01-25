#include "Dungeon.h"
#include <iostream>

std::string user;
void roomGeneration() {

}

void move()
{
    std::cout << "\nMouvement : [N][S][E][W] \n";
    std::cin >> user;
    if (user == "n" || user == "N") {
        std::cout << "Nord";
    }
    if (user == "s" || user == "S") {
        std::cout << "Sud";
    }
    if (user == "e" || user == "E") {
        std::cout << "Est";
    }
    if (user == "w" || user == "W") {
        std::cout << "West";
    }
}

