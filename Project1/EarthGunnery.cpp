#include "EarthGunnery.h"
#include"game.h"

EarthGunnery::EarthGunnery(int _ID, string type, int _health, int _power, int _attackCapacity, int _jointime,game*g) : Unit(_ID, "EG", _health, _power, _attackCapacity, _jointime,g) 
{
	gameptr = g;
}

void EarthGunnery::attack()
{
	EarthGunnery* EG = gameptr->getearth()->getEG();
	int damage_AM;
	//int damage_AD1;
	int damage_AD1;
	int damage_AD2;
	LinkedQueue<AlienMonsters*> templistmonsters;
	LinkedQueue<AlienDrones*>templistdrones;
	AlienDrones* AD1 = nullptr;
	AlienDrones* AD2 = nullptr;
	AlienMonsters* AM;

	/*EarthGunnery* EG = gameptr->getearth()->getEG();*/
	std::cout << "EG " << EG->getID() << " shots [ ";
	if (EG == nullptr)
	{
		return;
	}
	int i = 1;
	while (i <= EG->getAttackCapacity())
	{
		AM = gameptr->getalien()->getAM();
		int counter = i;
		gameptr->getalien()->removeAlienMonster(AM);

		if (AM != nullptr && i <= EG->getAttackCapacity())
		{
			std::cout << AM->getID() << " ";
			if (AM->getTa() == 0)
			{
				AM->setTa(gameptr->getTime());
			}
			AM->setDf(AM->getTa() - AM->getJoinTime());
			damage_AM = (EG->getPower() * EG->getHealth() / 100) / sqrt(AM->getHealth());
			AM->setHealth(AM->getHealth() - damage_AM);
			if (AM->getHealth() <= 0)
			{
				AM->setTd(gameptr->getTime());
				AM->setDd(AM->getTd() - AM->getTa());
				AM->setDb(AM->getDf() + AM->getDd());
				gameptr->addkilled(AM);
			}

			else
			{
				templistmonsters.enqueue(AM);

			}
			i++;
		}
		gameptr->getalien()->getAD(AD1, AD2);
		if (AD1 == AD2&&AD1!=nullptr&& i <= EG->getAttackCapacity()) {
			AD2 = nullptr;
			gameptr->getalien()->removeAlienDronefront(AD1);
			std::cout << AD1->getID() << " ";
			if (AD1->getTa() == 0)
			{
				AD1->setTa(gameptr->getTime());
			}
			AD1->setDf(AD1->getTa() - AD1->getJoinTime());
			damage_AD1 = (EG->getPower() * EG->getHealth() / 100) / sqrt(AD1->getHealth());
			AD1->setHealth(AD1->getHealth() - damage_AD1);

			if (AD1->getHealth() <= 0) {
				AD1->setTd(gameptr->getTime());
				AD1->setDd(AD1->getTd() - AD1->getTa());
				AD1->setDb(AD1->getDf() + AD1->getDd());
				gameptr->addkilled(AD1);
			}
			else {
				templistdrones.enqueue(AD1);
			}
			i++;
			continue;
		}
		else if (AD1 != nullptr&& i <= EG->getAttackCapacity()) {
			gameptr->getalien()->removeAlienDronefront(AD1);
			std::cout << AD1->getID() << " ";
			if (AD1->getTa() == 0)
			{
				AD1->setTa(gameptr->getTime());
			}
			AD1->setDf(AD1->getTa() - AD1->getJoinTime());
			damage_AD1 = (EG->getPower() * EG->getHealth() / 100) / sqrt(AD1->getHealth());
			AD1->setHealth(AD1->getHealth() - damage_AD1);

			if (AD1->getHealth() <= 0) {
				AD1->setTd(gameptr->getTime());
				AD1->setDd(AD1->getTd() - AD1->getTa());
				AD1->setDb(AD1->getDf() + AD1->getDd());
				gameptr->addkilled(AD1);
			}
			else {
				templistdrones.enqueue(AD1);
			}
			i++;
			if (AD2 != nullptr&&i<=EG->getAttackCapacity()) {
				gameptr->getalien()->removeAlienDroneback(AD2);
				std::cout << AD2->getID() << " ";
				if (AD2->getTa() == 0)
				{
					AD2->setTa(gameptr->getTime());
				}
				AD2->setDf(AD2->getTa() - AD2->getJoinTime());
				damage_AD2 = (EG->getPower() * EG->getHealth() / 100) / sqrt(AD2->getHealth());
				AD2->setHealth(AD2->getHealth() - damage_AD2);

				if (AD2->getHealth() <= 0) {
					AD2->setTd(gameptr->getTime());
					AD2->setDd(AD2->getTd() - AD2->getTa());
					AD2->setDb(AD2->getDf() + AD2->getDd());
					gameptr->addkilled(AD2);
				}
				else {

					templistdrones.enqueue(AD2);
				}
				i++;
			}
		}
		
		if (i == counter) { break; }
	}
	std::cout << " ] " << std::endl;
	int x = 0;//as the size of the lists decrease by 1 every dequeue we cant make for loop 
	while (x != templistmonsters.getSize())
	{
			templistmonsters.dequeue(AM);
			gameptr->getalien()->addAlienMonster(AM);
		}
	while(x!=templistdrones.getSize()){
			templistdrones.dequeue(AD1);
			gameptr->getalien()->addAlienDrone(AD1);
		}
}



int EarthGunnery::calculatePriority()
{
	

		return getHealth() * getPower();
	
}


