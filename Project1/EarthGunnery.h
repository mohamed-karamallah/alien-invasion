#pragma once
#include"Unit.h"
#include<iostream>
#include "priQueue.h"
class EarthGunnery :public Unit
{
private:

public:
	EarthGunnery(int _ID, string type, int _health, int _power, int _attackCapacity, int _jointime,game*g);
	EarthGunnery();
	void attack(Unit*EG);
	int calculatePriority();
	

};
