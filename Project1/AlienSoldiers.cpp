#include "AlienSoldiers.h"
#include"game.h"
AlienSoldiers::AlienSoldiers(int _ID, string type, int _health, int _power, int _attackCapacity, int _jointime, game* g) : Unit(_ID, "AS", _health, _power, _attackCapacity, _jointime, g) 
{
	gameptr = g; }

void AlienSoldiers::attack()
{
	AlienSoldiers* AS = gameptr->getalien()->getAS();

	
	if (AS == nullptr) {
		return;
	}
	std::cout << "AS " << AS->getID() << " shots [ ";
	LinkedQueue<EarthSoldiers*>templist;
	EarthSoldiers* ES;
	for (int i = 0; i < AS->getAttackCapacity(); i++)
	{
		 ES = gameptr->getearth()->getES();
		if (ES == nullptr) {

		}
		else {
			gameptr->getearth()->removeEarthSoldier(ES);
			std::cout << ES->getID() << " , ";
			ES->setOriginalH(ES->getHealth());
			ES->settUML(gameptr->currenttimeStep);
			
			if (ES->getTa() == 0)
			{
				ES->setTa(gameptr->currenttimeStep);
			}
			ES->setDf(ES->getTa() - ES->getJoinTime());
			int damage = (AS->getPower() * AS->getHealth() / 100) / pow(ES->getHealth(), 0.5);
			ES->setHealth(ES->getHealth() - damage);
			if (ES->getHealth() <= 0) {
				ES->setTd(gameptr->currenttimeStep);
				ES->setDd(ES->getTd() - ES->getTa());
				ES->setDb(ES->getDf() + ES->getDd());
				gameptr->addkilled(ES);
			}
			else if (ES->getHealth() > 0 && ES->getHealth() < 0.2 * ES->getOriginalH()) {
				int pri = -ES->getHealth();
				gameptr->addUMLS(ES, pri);
			}
			else {
				templist.enqueue(ES);
				//templist.dequeue(ES);
				//gameptr->getearth()->addEarthSoldier(ES);
			}

		}
	}
	std::cout << " ]"<<std::endl;
	for (int i = 0; i < templist.getSize(); i++) {
		templist.dequeue(ES);
		gameptr->getearth()->addEarthSoldier(ES);
	}
}




