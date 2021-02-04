#include "Ennemy.h"
#include "Player.h"
#pragma once
class Room
{
public :
	bool treasure;
	bool ennemy;
	bool isVisited;
	bool shop;
	Ennemy *E;
};

class Shop 
{
public:
	bool sword = true;
	bool armor = true;
	int swordprice = 20;
	int armorprice = 35;
	int potionprice = 10;
	Ennemy* ShopKeeper;
};


class Dungeon
{
public:
	void roomGeneration();
	void checkMap();
	void checkRoom();
	void move();
	void checkAction();
	void checkTreasure(Player*);
	void shop(Player*);
	void fightMonster(Player*);
	void nextStages();
	int getStages();
protected:
	int tailleDungeon = 10;
	Room gameRoom[10][10];
	Shop dungeonShop;
	int coordX;
	int coordY;
	int winX;
	int	winY;
	int stages = 1;
	char player = 'P';
	char map = '#';
	char discovered = 'X';
};


