#pragma once
class Dungeon
{
};

class Room
{
public :
	bool treasure;
	bool ennemy;
};

class Player {
public :
	void getDamage(int dmg) { health -= dmg; }
	void gainMoney(int gold) { money += gold; }
	int getHealth() { return health; }
	int getStrenght() { return strenght; }
	int getMoney() { return money; }
protected :
	int health;
	int strenght;
	int money;
};

