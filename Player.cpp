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
    swordLevel = 0;
    armorLevel = 0;
    healPotion = 0;
};
void Player::checkPlayerStatus() {
    std::cout << BOLDGREEN << "\n -------- Player Stats -------- \nLevel : " << level << "\nHP : " << health << "/" << maxHealth <<
        "\nSTR : " << strenght << "\nExperience : "<< exp << "\nGold : " << money << "\n ------------------------------ \n" << RESET;
}


void Player::showInventory() {
    std::cout << "\n---------- PLAYER INVENTORY ----------\n\n";
    std::cout << "Sword : ";
    switch (swordLevel) {
        case 0: 
            std::cout << "No Sword\n"; 
            break;
        case 1:
            std::cout << "Wooden Sword\n";
            break;
        case 2:
            std::cout << "Iron Sword\n";
            break;
        case 3:
            std::cout << "Golden Sword\n";
            break;
        case 4:
            std::cout << "Diamond Sword\n";
            break;
        case 5:
            std::cout << "Excalibur";
            break;
    }
    std::cout << "Armor : ";
    switch (armorLevel) {
        case 0:
            std::cout << "No Armor\n";
            break;
        case 1:
            std::cout << "Wool Shirt\n";
            break;
        case 2:
            std::cout << "Iron Armor\n";
            break;
        case 3:
            std::cout << "Golden Armor\n";
            break;
        case 4:
            std::cout << "Diamond Armor\n";
            break;
        case 5:
            std::cout << "Adamantium Armor\n";
            break;
    }
    std::cout << "Heal Potion : " << getHealPotion() <<"\n";
    if (getHealPotion() > 0) {
        std::cout << "Use a Heal Potion? "<<CYAN<<"[Y]"<<RESET<<"es"<<CYAN<<" [N]"<<RESET<<"o\n";
        std::string userInput;
        std::cin >> userInput;
        if (userInput == "Y" || userInput == "y") {
            heal(10);
            healPotion--;
        }
    }

    std::cout << "\n--------------------------------------\n";
}

void Player::gainSwordLevel() {
    swordLevel++;
    strenght += 2 * swordLevel;
}

void Player::gainArmorLevel() {
    armorLevel++;
    maxHealth += 2 * armorLevel;
    health += 2 * armorLevel;
}

void Player::addHealPotion() {
    healPotion++;
}
void Player::getDamage(int dmg) {
	health -= dmg;
}
void Player::gainMoney(int gold) { 
	money += gold; 
}

int Player::getSwordLevel() {
    return swordLevel;
}
int Player::getArmorLevel() {
    return armorLevel;
}

int Player::getHealPotion() {
    return healPotion;
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
    if (exp >= 100) {
        do {
            gainLevel();
            exp -= 100;
        } while (exp >= 100);
    }
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





