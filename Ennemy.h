#pragma once
class Ennemy {
public:
	Ennemy(int _health, int _strenght, int _money);
	void getDamage(int dmg);
	int getHealth();
protected:
	int health;
	int strenght;
	int money;
};

