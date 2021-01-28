#include "Player.h"
#include <iostream>

Player::Player(int _health, int _strenght, int _money) {
	health = _health;
	strenght = _strenght;
	money = _money;
};
void Player::checkPlayerStatus() {
    std::cout << "\nPlayer Stats : \nHP : " << health <<
        "\nSTR :" << strenght << "\nGold :" << money << "\n";
}

void Player::getDamage(int dmg) {
	health -= dmg;
}
void Player::gainMoney(int gold) { 
	money += gold; 
}

int Player::getHealth() { return health; }
int Player::getStrenght() { return strenght; }
int Player::getMoney() { return money; }

void Player::fightMonster(Ennemy E) {
    do {
        std::cout << "Le joueur attaque!\n";
        E.getDamage(1);
        std::cout << E.getHealth() << "HP restant.\n";
        if (E.getHealth() > 0) {
            std::cout << "Le monstre attaque!\n";
            getDamage(1);
            std::cout << health << "HP restant.\n";
        }
        else {
            std::cout << "Le monstre est mort!";
        }
    } while (health > 0 && E.getHealth() > 0);
}




