#include "Player.h"
#include <iostream>

void Player::checkPlayerStatus() {
    std::cout << "\nPlayer Stats : \nHP : " << health <<
        "\nSTR :" << strenght << "\nGold :" << money << "\n";
}