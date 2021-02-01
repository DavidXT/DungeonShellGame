#include "Ennemy.h"
#pragma once

class Player {

public:
	Player(int _health, int _strenght, int _money);
	void checkPlayerStatus();
	void getDamage(int dmg);
	void gainMoney(int gold);
	void loseMoney(int gold);
	void heal(int pv);
	void gainStrenght(int str);
	void gainHealth(int vit);
	void runAway();
	int getHealth();
	int getStrenght();
	int getMoney();
protected:
	int maxHealth;
	int health;
	int strenght;
	int money;
};

