#include "Player.h"
#include "Ennemy.h"
#pragma once

class Room
{
public :
	bool treasure;
	bool ennemy;
};


class Dungeon
{
public:
	void roomGeneration();
	void checkMap();
	void checkRoom();
	void generateRandomStart();
	void generateExit();
	void move();
	void checkAction();
	void checkTreasure(Player);
	void fightMonster(Player,Ennemy);
protected:
	int tailleDungeon = 10;
	Room gameRoom[10][10];
	bool gameMap[10][10];
	int coordX, coordY;
	int winX, winY;
	char player = 'P';
	char map = '#';
};


