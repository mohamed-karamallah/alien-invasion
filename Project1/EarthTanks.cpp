#include "EarthTanks.h"
#include"game.h"
EarthTanks::EarthTanks(int ID, string type, int joinTime, int health, int power, int attackCapacity, game* g) : Unit(ID, "ET", joinTime, health, power, attackCapacity, g)
{
	gameptr = g;
}

void EarthTanks::attack()
{
	EarthTanks* ET = gameptr->getearth()->getET();
	int damage;
	LinkedQueue<AlienSoldiers*>templistAS;
	LinkedQueue<AlienMonsters*>templistAM;
	LinkedQueue<Unit*>shotlist;
	AlienMonsters* AM;
	AlienSoldiers* AS;
	//bool check = false;
	if (ET == nullptr)
	{
		return;
	}

	//std::cout << "ET " << ET->getID() << " shots [ ";
	int i = 1;
	while (i <= ET->getAttackCapacity()) {
		int counter = i;
		AM = gameptr->getalien()->getAM();



		if (AM != nullptr && i <= ET->getAttackCapacity())
		{
			gameptr->getalien()->removeAlienMonster(AM);
			shotlist.enqueue(AM);
			//std::cout << AM->getID() << " ";
			if (AM->getTa() == 0)
			{
				AM->setTa(gameptr->getTime());
			}
			AM->setDf(AM->getTa() - AM->getJoinTime());
			damage = (ET->getPower() * ET->getHealth() / 100) / sqrt(AM->getHealth());
			AM->setHealth(AM->getHealth() - damage);
			if (AM->getHealth() <= 0)
			{
				AM->setTd(gameptr->getTime());
				AM->setDd(AM->getTd() - AM->getTa());
				AM->setDb(AM->getDf() + AM->getDd());
				gameptr->addkilled(AM);
			}

			else
			{
				templistAM.enqueue(AM);

			}
			i++;
		}
		if (gameptr->getearth()->getESlistsize() < 0.3 * gameptr->getalien()->getASlistsize() && gameptr->getearth()->getESlistsize() < 0.8 * gameptr->getalien()->getASlistsize())
		{
			AS = gameptr->getalien()->getAS();
			if (AS != nullptr) {
				gameptr->getalien()->removeAlienSoldier(AS);
				//std::cout << AS->getID() << " ,";
				shotlist.enqueue(AS);
				if (AS->getTa() == 0)
				{

					AS->setTa(gameptr->getTime());
				}
				AS->setDf(AS->getTa() - AS->getJoinTime());
				int damage = (ET->getPower() * ET->getHealth() / 100) / pow(AS->getHealth(), 0.5);
				AS->setHealth(AS->getHealth() - damage);

				if (AS->getHealth() <= 0) {
					AS->setTd(gameptr->getTime());
					AS->setDd(AS->getTd() - AS->getTa());
					AS->setDb(AS->getDf() + AS->getDd());
					gameptr->addkilled(AS);
				}
				else {
					templistAS.enqueue(AS);

				}
				i++;
			}

		}

		if (i == counter) { break; }

	}
	if (gameptr->getmode() == 1) {
		std::cout << "ET " << ET->getID() << " shots [ ";
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
	while (!templistAM.isEmpty())
	{
		templistAM.dequeue(AM);
		gameptr->getalien()->addAlienMonster(AM);
	}
	while (!templistAS.isEmpty()) {
		templistAS.dequeue(AS);
		gameptr->getalien()->addAlienSoldier(AS);
	}
}

void EarthTanks::setOriginalH(int h)
{
	originalHealth = h;
}

int EarthTanks::getOriginalH()
{
	return originalHealth;
}
