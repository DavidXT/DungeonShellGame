#include "Player.h"
#include <iostream>

Player::Player(int _health, int _strenght, int _money) {
	health = _health;
	strenght = _strenght;
	money = _money;
    maxHealth = health;
    exp = 0;
    level = 1;
};
void Player::checkPlayerStatus() {
    std::cout << "\nPlayer Stats : \nHP : " << health << "/" << maxHealth <<
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
void Player::gainExp(int gain) {
    exp += gain;
    do {
        gainLevel();
        exp -= 100;
    } while (exp >= 100);
}

void Player::gainLevel() {
    level++;
    strenght += 2;
    maxHealth += 10;
    health += 10;
}
void Player::gainStrenght(int str) {
    strenght += str;
}

void Player::gainHealth(int vit) {
    maxHealth += vit;
    health += vit;
}

void Player::runAway() {
    int temp = money / 2;
    money -= temp;
    std::cout << "You ran away! you lost : " << temp << "\n";
}

int Player::getHealth() { return health; }
int Player::getStrenght() { return strenght; }
int Player::getMoney() { return money; }





