#include "AlienDrones.h"



AlienDrones::AlienDrones(int _ID, string type, int _health, int _power, int _attackCapacity, int _jointime, game* g) : Unit(_ID, "AD", _health, _power, _attackCapacity, _jointime,g)
{ gameptr = g; }

void AlienDrones::attack()
{
}




