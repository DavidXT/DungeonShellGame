#include "Ennemy.h"

Ennemy::Ennemy(int _health, int _strenght, int _money, int _exp) {
	health = _health;
	strenght = _strenght;
	money = _money;
	exp = _exp;
}

int Ennemy::getHealth() {
	return health;
}

void Ennemy::getDamage(int dmg) {
	health -= dmg;
}

int Ennemy::getStrenght() {
	return strenght;
}

int Ennemy::getMoney() {
	return money;
}

int Ennemy::getExp() {
	return exp;
}