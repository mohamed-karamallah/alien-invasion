#pragma once
#include"AlienSoldiers.h"
#include"AlienDrones.h"
#include"LinkedQueue.h"
#include"doubleEQ.h"
#include "Dnode.h"
#include"ArrayofPointers.h"
#include "AlienMonsters.h"

class AlienArmy
{
private:
	LinkedQueue<AlienSoldiers*> alienSoldierslist;
	doubleEQ<AlienDrones*> aliendroneslist;
	ArrayofPointers alienmonstersList;


public:
	
	void addAlienSoldier(AlienSoldiers* soldier);
	void removeAlienSoldier(AlienSoldiers* soldier);
	void addAlienDrone(AlienDrones* drone1);
	void removeAlienDrone(AlienDrones* drone1, AlienDrones* drone2);
	void removeAlienDronefront(AlienDrones* drone);
	void removeAlienDroneback(AlienDrones* drone);
	void addAlienMonster(AlienMonsters* monster1);
	void removeAlienMonster(AlienMonsters* monster1);

	void printaliensoldierlist();
	void printaliendronelist();
	void printAllLists();
	AlienSoldiers* getAS();
	void getAD(AlienDrones*& pickedFront, AlienDrones*& pickedBack);
	AlienMonsters* getAM();
 void printMonstersList();
 void attack();
 int getASlistsize();
 int getADlistsize();
 int getAMlistsize();
 int getAarmysize();

};


