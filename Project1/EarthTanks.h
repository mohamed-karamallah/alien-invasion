#pragma once
#include"Unit.h"
class EarthTanks :public Unit
{
	int originalHealth;
public:
	EarthTanks(int ID, string type, int joinTime, int health, int power, int attackCapacity,game*g);
	void attack();

	void setOriginalH(int h);
	int getOriginalH();
	    
};

