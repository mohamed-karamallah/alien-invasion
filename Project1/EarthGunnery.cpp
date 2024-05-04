#include "EarthGunnery.h"
#include"game.h"

EarthGunnery::EarthGunnery(int _ID, string type, int _health, int _power, int _attackCapacity, int _jointime,game*g) : Unit(_ID, "EG", _health, _power, _attackCapacity, _jointime,g) 
{
	gameptr = g;
}

void EarthGunnery::attack(Unit*EG)
{
	int damage_AM;
	int damage_AD1;
	int damage_AD2;
	LinkedQueue<AlienMonsters*>templistmonsters;
	LinkedQueue<AlienDrones*>templistdrones;
	/*EarthGunnery* EG = gameptr->getearth()->getEG();*/
	std::cout << "EG " << EG->getAttackCapacity() << " shots [ ";
	if (EG == nullptr)
	{
		return;
	}
	for (int i = 0; i < EG->getAttackCapacity(); i++)
	{
		AlienMonsters* AM = gameptr->getalien()->getAM();

		if (AM == nullptr)
		{

		}
		else {
			//int healthAM = AM->getHealth();
			gameptr->getalien()->removeAlienMonster(AM);
			
			std::cout << AM->getID() << " ";
			damage_AM = (EG->getPower() * EG->getHealth() / 100) / sqrt(AM->getHealth());
			AM->setHealth(AM->getHealth() - damage_AM);
			if (AM->getHealth() <= 0)
			{
				gameptr->addkilled(AM);
			}

			else
			{
				templistmonsters.enqueue(AM);
				templistmonsters.dequeue(AM);
				gameptr->getalien()->addAlienMonster(AM);
			}
		}
	
		AlienDrones* AD1 = nullptr;
		AlienDrones* AD2=nullptr;

		gameptr->getalien()->getAD(AD1, AD2);
		if (AD1 == nullptr && AD2 == nullptr)
		{
			
		}
		/*else if (AD1 == AD2)
		{
			AD2 = nullptr;
			gameptr->getalien()->removeAlienDrone(AD1, AD2);
			std::cout << AD1->getID() << " ";
			damage_AD2 = (EG->getPower() * EG->getHealth() / 100) / sqrt(AD2->getHealth());
			AD2->setHealth(AD2->getHealth() - damage_AD2);

		}*/

		else if (AD1 == AD2&&AD1!=nullptr)
		{
			AD2 = nullptr;
			gameptr->getalien()->removeAlienDrone(AD1, AD2);
			std::cout << AD1->getID() << " ";
			damage_AD1 = (EG->getPower() * EG->getHealth() / 100) / sqrt(AD1->getHealth());
			AD1->setHealth(AD1->getHealth() - damage_AD1);
			if (AD1->getHealth() <= 0)
			{
				gameptr->addkilled(AD1);
			}

			else
			{
				templistdrones.enqueue(AD1);
				templistdrones.dequeue(AD1);
				gameptr->getalien()->addAlienDrone(AD1);

			}
		}
		else
		{
			gameptr->getalien()->removeAlienDrone(AD1, AD2);
			std::cout << AD1->getID() << " " << AD2->getID() << " ";
			damage_AD1 = (EG->getPower() * EG->getHealth() / 100) / sqrt(AD1->getHealth());
			AD1->setHealth(AD1->getHealth() - damage_AD1);
			damage_AD2 = (EG->getPower() * EG->getHealth() / 100) / sqrt(AD2->getHealth());
			AD2->setHealth(AD2->getHealth() - damage_AD2);

			if (AD1->getHealth() <= 0)
			{
				gameptr->addkilled(AD1);
			}

			else
			{
				templistdrones.enqueue(AD1);
				templistdrones.dequeue(AD1);
				gameptr->getalien()->addAlienDrone(AD1);

			}

			if (AD2->getHealth() <= 0)
			{
				gameptr->addkilled(AD2);

			}

			else
			{
				templistdrones.enqueue(AD2);
				templistdrones.dequeue(AD2);
				gameptr->getalien()->addAlienDrone(AD2);
			}
		}
	}
	std::cout << " ] " << std::endl;
}

int EarthGunnery::calculatePriority()
{
	
		// Calculate priority based on health and power combination
		return getHealth() * getPower();
	
}


