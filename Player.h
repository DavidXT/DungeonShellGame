#pragma once
class Player {

public:
	Player(int _health, int _strenght, int _money) {
		health = _health;
		strenght = _strenght;
		money = _money;
	};
	Player();
	void checkPlayerStatus();
	void getDamage(int dmg) { health -= dmg; }
	void gainMoney(int gold) { money += gold; }
	int getHealth() { return health; }
	int getStrenght() { return strenght; }
	int getMoney() { return money; }
protected:
	int health;
	int strenght;
	int money;
};

