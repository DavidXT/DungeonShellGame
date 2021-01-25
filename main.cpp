#include "Dungeon.h"
#include <iostream>

void move();

int HP= 5;

int main()
{
    std::cout << "----- Game Start ! -----\n";
    do
    {
        std::cout << '\n' << "- Press a start to start the game";
    } while (std::cin.get() != '\n');
    while (HP > 0) {
        move();
        HP--;
    }
}

