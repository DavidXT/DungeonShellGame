#include "Player.h"
#include <iostream>

Player::Player(int _health, int _strenght, int _money) {
	health = _health;
	strenght = _strenght;
	money = _money;
    maxHealth = health;
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

void Player::loseMoney(int gold) {
    money -= gold;
}

void Player::heal(int pv) {
    if (health + pv <= maxHealth) {
        health += pv;
    }
    else {
        health = maxHealth;
    }
}

void Player::gainStrenght(int str) {
    strenght += str;
}

void Player::gainHealth(int vit) {
    maxHealth += vit;
    health += vit;
}

int Player::getHealth() { return health; }
int Player::getStrenght() { return strenght; }
int Player::getMoney() { return money; }





