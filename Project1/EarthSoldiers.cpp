#include "EarthSoldiers.h"
#include"game.h"

EarthSoldiers::EarthSoldiers(int _ID, string _type, int _health, int _power, int _attackCapacity, int _jointime, game* g) : Unit(_ID, "ES", _health, _power, _attackCapacity, _jointime, g)
{
	gameptr = g;
}

void EarthSoldiers::attack()
{
	EarthSoldiers* ES = gameptr->getearth()->getES();
	if (ES == nullptr) {
		return;
	}

	//std::cout << "ES " << ES->getID() << " shots [ ";
	LinkedQueue<AlienSoldiers*> templist;
	LinkedQueue<Unit*>shotlist;
	AlienSoldiers* AS;

	for (int i = 0; i < ES->getAttackCapacity(); i++) {
		AS = gameptr->getalien()->getAS();
		if (AS != nullptr) {
			gameptr->getalien()->removeAlienSoldier(AS);
			shotlist.enqueue(AS);
			//std::cout << AS->getID() << " ,";

			if (AS->getTa() == 0)
			{

				AS->setTa(gameptr->getTime());
			}
			AS->setDf(AS->getTa() - AS->getJoinTime());
			int damage = (ES->getPower() * ES->getHealth() / 100) / pow(AS->getHealth(), 0.5);
			AS->setHealth(AS->getHealth() - damage);

			if (AS->getHealth() <= 0) {
				AS->setTd(gameptr->getTime());
				AS->setDd(AS->getTd() - AS->getTa());
				AS->setDb(AS->getDf() + AS->getDd());
				gameptr->addkilled(AS);
			}
			else {
				templist.enqueue(AS);
				//templist.dequeue(AS);
				//gameptr->getalien()->addAlienSoldier(AS);
			}

		}
	}
	//std::cout << " ] "<<std::endl;

	while (!templist.isEmpty()) {
		templist.dequeue(AS);
		gameptr->getalien()->addAlienSoldier(AS);
	}
	if (gameptr->getmode() == 1) {
		std::cout << "ES " << ES->getID() << " shots [ ";
		while (!shotlist.isEmpty()) {
			Unit* unit;
			shotlist.dequeue(unit);
			std::cout << unit->getID();

			// Check if there are more elements in the list
			if (!shotlist.isEmpty()) {
				std::cout << " , ";
			}
		}
		std::cout << " ]" << std::endl;
	}
}

void EarthSoldiers::setOriginalH(int h)
{
	originalHealth = h;
}

int EarthSoldiers::getOriginalH()
{
	return originalHealth;
}
