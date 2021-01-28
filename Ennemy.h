#pragma once
class Ennemy {
public:
	Ennemy(int _health, int _strenght, int _money) {
		health = _health;
		strenght = _strenght;
		money = _money;
	}
	void getDamage(int dmg) { health -= dmg; }
	int getHealth() { return health; }
protected:
	int health;
	int strenght;
	int money;
};

