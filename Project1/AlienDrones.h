#pragma once
#include"Unit.h"

class AlienDrones :
	public Unit
{
public:

	AlienDrones(int _ID, string type, int _health, int _power, int _attackCapacity, int _jointime,game*g);
	void attack();

};
