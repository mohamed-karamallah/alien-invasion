#pragma once
#include"Unit.h"
class AlienMonsters :public Unit
{
public:
    AlienMonsters(int _ID, string type, int _health, int _power, int _attackCapacity, int _jointime,game *g);
    void attack(Unit*AM);


};



