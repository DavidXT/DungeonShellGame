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
};

class Shop 
{
public:
	bool sword = true;
	bool armor = true;
};


class Dungeon
{
public:
	void roomGeneration();
	void checkMap();
	void checkRoom();
	void generateExit();
	void move();
	void checkAction();
	void checkTreasure(Player*);
	void shop(Player*);
	void fightMonster(Player*, Ennemy);
protected:
	int tailleDungeon = 10;
	Room gameRoom[10][10];
	Shop dungeonShop;
	int coordX;
	int coordY;
	int winX;
	int	winY;
	char player = 'P';
	char map = '#';
	char discovered = 'X';
};


