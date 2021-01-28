#include "Ennemy.h"

Ennemy::Ennemy(int _health, int _strenght, int _money) {
	health = _health;
	strenght = _strenght;
	money = _money;
}

int Ennemy::getHealth() {
	return health;
}

void Ennemy::getDamage(int dmg) {
	health -= dmg;
}