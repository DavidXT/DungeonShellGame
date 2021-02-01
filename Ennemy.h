#pragma once
class Ennemy {
public:
	Ennemy(int _health, int _strenght, int _money);
	void getDamage(int dmg);
	int getHealth();
	int getStrenght();
	int getMoney();
protected:
	int health;
	int strenght;
	int money;
};

