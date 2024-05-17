#include "AlienSoldiers.h"
#include"game.h"
AlienSoldiers::AlienSoldiers(int _ID, string type, int _health, int _power, int _attackCapacity, int _jointime, game* g) : Unit(_ID, "AS", _health, _power, _attackCapacity, _jointime, g)
{
	gameptr = g;
}

void AlienSoldiers::attack()
{
	AlienSoldiers* AS = gameptr->getalien()->getAS();


	if (AS == nullptr) {
		return;
	}
	//std::cout << "AS " << AS->getID() << " shots [ ";
	LinkedQueue<EarthSoldiers*>templist;
	LinkedQueue<Unit*>shotlist;
	EarthSoldiers* ES;
	for (int i = 0; i < AS->getAttackCapacity(); i++)
	{
		ES = gameptr->getearth()->getES();
		if (ES != nullptr) {
			gameptr->getearth()->removeEarthSoldier(ES);
			shotlist.enqueue(ES);
			//std::cout << ES->getID() << " , ";
			ES->setOriginalH(ES->getHealth());

			if (ES->getTa() == 0)
			{
				ES->setTa(gameptr->getTime());
			}
			ES->setDf(ES->getTa() - ES->getJoinTime());
			int damage = (AS->getPower() * AS->getHealth() / 100) / pow(ES->getHealth(), 0.5);
			ES->setHealth(ES->getHealth() - damage);
			if (ES->getHealth() <= 0) {
				ES->setTd(gameptr->getTime());
				ES->setDd(ES->getTd() - ES->getTa());
				ES->setDb(ES->getDf() + ES->getDd());
				gameptr->addkilled(ES);
			}
			else if (ES->getHealth() > 0 && ES->getHealth() < 0.2 * ES->getOriginalH()) {
				ES->settUML(gameptr->getTime());
				int pri = -ES->getHealth();
				gameptr->addUMLS(ES, pri);
			}
			else {
				templist.enqueue(ES);

			}

		}
		else if (ES == nullptr) {
			break;
		}
	}

	//std::cout << " ]"<<std::endl;
	while (!templist.isEmpty()) {
		templist.dequeue(ES);
		gameptr->getearth()->addEarthSoldier(ES);
	}
	if (gameptr->getmode() == 1) {
		std::cout << "AS " << AS->getID() << " shots [ ";
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