#include "EarthSoldiers.h"
#include"game.h"

EarthSoldiers::EarthSoldiers(int _ID, string _type, int _health, int _power, int _attackCapacity, int _jointime,game*g) : Unit(_ID, "ES", _health, _power, _attackCapacity, _jointime,g)
{
	gameptr = g;
}

void EarthSoldiers::attack(Unit*ES)
{
	/*EarthSoldiers* ES = gameptr->getearth()->getES();*/
	if (ES == nullptr) {
		return;
	}
	
	std::cout << "ES " << ES->getAttackCapacity() << " shots [ ";
	LinkedQueue<AlienSoldiers*> templist;
	for (int i = 0; i < ES->getAttackCapacity(); i++) {
		AlienSoldiers* AS = gameptr->getalien()->getAS();
		if (AS == nullptr) {

			return;
		}
		else {
			gameptr->getalien()->removeAlienSoldier(AS);
			std::cout << AS->getID() << " ,";
			int damage = (ES->getPower() * ES->getHealth() / 100) / pow(AS->getHealth(), 0.5);
			AS->setHealth(AS->getHealth() - damage);
			
			if (AS->getHealth() <= 0) {
				gameptr->addkilled(AS);
			}
			else {
				templist.enqueue(AS);
				templist.dequeue(AS);
				gameptr->getalien()->addAlienSoldier(AS);
			}

		}
	}
	std::cout << " ] "<<std::endl;
}

void EarthSoldiers::setOriginalH(int h)
{
	originalHealth = h;
}

int EarthSoldiers::getOriginalH()
{
	return originalHealth;
}



