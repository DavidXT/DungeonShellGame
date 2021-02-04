#pragma once
class Ennemy {
public:
	Ennemy(int _health, int _strenght, int _money, int _exp);
	void getDamage(int dmg);
	int getHealth();
	int getStrenght();
	int getMoney();
	int getExp();
protected:
	int health;
	int strenght;
	int money;
	int exp;
};

