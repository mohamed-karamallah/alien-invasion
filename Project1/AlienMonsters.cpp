#include "AlienMonsters.h"

AlienMonsters::AlienMonsters(int _ID, string type, int _health, int _power, int _attackCapacity, int _jointime, game* g) : Unit(_ID, "AM", _health, _power, _attackCapacity, _jointime,g) 
{ gameptr = g; }


void AlienMonsters::attack(Unit*AM)
{
}




