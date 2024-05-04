#pragma once
#include"Unit.h"
#include <iostream>
using namespace std;
class AlienSoldiers :
	public Unit
{private:
    
public:
    AlienSoldiers(int _ID, string type, int _health, int _power, int _attackCapacity, int _jointime,game*g);
    void attack(Unit*AS);

};


