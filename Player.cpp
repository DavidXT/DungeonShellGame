#include "Player.h"
#include <iostream>
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


Player::Player(int _health, int _strenght, int _money) {
	health = _health;
	strenght = _strenght;
	money = _money;
    maxHealth = health;
    exp = 0;
    level = 1;
};
void Player::checkPlayerStatus() {
    std::cout << BOLDGREEN << "\n -------- Player Stats -------- \nHP : " << health << "/" << maxHealth <<
        "\nSTR :" << strenght << "\nGold :" << money << "\n ------------------------------ \n" << RESET;
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





