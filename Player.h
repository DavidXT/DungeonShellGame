#include "Ennemy.h"
#pragma once

class Player {

public:
	Player(int _health, int _strenght, int _money);
	void checkPlayerStatus();
	void getDamage(int dmg);
	void gainMoney(int gold);
	void fightMonster(Ennemy);
	int getHealth();
	int getStrenght();
	int getMoney();
	void checkTreasure(Player);
protected:
	int health;
	int strenght;
	int money;
};

