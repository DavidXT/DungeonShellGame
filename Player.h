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
	void gainExp(int gain);
	void gainLevel();
	void showInventory();
	void gainSwordLevel();
	void gainArmorLevel();
	void addHealPotion();
	int getHealth();
	int getStrenght();
	int getMoney();
	int getSwordLevel();
	int getArmorLevel();
	int getHealPotion();
protected:
	int maxHealth;
	int health;
	int strenght;
	int money;
	int exp;
	int level;
	int swordLevel;
	int armorLevel;
	int healPotion;
};


