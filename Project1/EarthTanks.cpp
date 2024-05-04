#include "EarthTanks.h"

EarthTanks::EarthTanks(int ID, string type, int joinTime, int health, int power, int attackCapacity,game*g) : Unit(ID, "ET", joinTime, health, power, attackCapacity,g) 
{
	gameptr = g;
}

void EarthTanks::attack(Unit*ET)
{
}

void EarthTanks::setOriginalH(int h)
{
	originalHealth = h;
}

int EarthTanks::getOriginalH()
{
	return originalHealth;
}
