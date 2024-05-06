#include "EarthTanks.h"

EarthTanks::EarthTanks(int ID, string type, int joinTime, int health, int power, int attackCapacity,game*g) : Unit(ID, "ET", joinTime, health, power, attackCapacity,g) 
{
	gameptr = g;
}

void EarthTanks::attack()
{
	//int damage_AM;
	////int damage_AD1;
	//int damage_AD1;
	//int damage_AD2;
	//LinkedQueue<AlienMonsters*>templistmonsters;
	//LinkedQueue<AlienDrones*>templistdrones;
	//AlienDrones* AD1 = nullptr;
	//AlienDrones* AD2 = nullptr;
	//AlienMonsters* AM;

	///*EarthGunnery* EG = gameptr->getearth()->getEG();*/
	//std::cout << "EG " << EG->getID() << " shots [ ";
	//if (EG == nullptr)
	//{
	//	return;
	//}
	//int i = 1;
	//while (i <= EG->getAttackCapacity())
	//{
	//	//AM = gameptr->getalien()->getAM();
	//	gameptr->getalien()->removeAlienMonster(AM);

	//	if (AM == nullptr)
	//	{

	//	}
	//	else {



	//		std::cout << AM->getID() << " ";
	//		if (AM->getTa() == 0)
	//		{
	//			AM->setTa(gameptr->currenttimeStep);
	//		}
	//		AM->setDf(AM->getTa() - AM->getJoinTime());
	//		damage_AM = (EG->getPower() * EG->getHealth() / 100) / sqrt(AM->getHealth());
	//		AM->setHealth(AM->getHealth() - damage_AM);
	//		if (AM->getHealth() <= 0)
	//		{
	//			AM->setTd(gameptr->currenttimeStep);
	//			AM->setDd(AM->getTd() - AM->getTa());
	//			AM->setDb(AM->getDf() + AM->getDd());
	//			gameptr->addkilled(AM);
	//		}

	//		else
	//		{
	//			templistmonsters.enqueue(AM);

	//		}
	//		i++;
	//	}

	//	if (i == EG->getAttackCapacity()) {
	//		continue;
	//	}
	//	else {
	//		gameptr->getalien()->getAD(AD1, AD2);
	//		if (AD1 == nullptr && AD2 == nullptr)
	//		{
	//			continue;
	//		}
	//		else if (AD1 == AD2 && AD1 != nullptr)
	//		{
	//			AD2 = nullptr;
	//			gameptr->getalien()->removeAlienDrone(AD1, AD2);
	//			std::cout << AD1->getID() << " ";
	//			damage_AD1 = (EG->getPower() * EG->getHealth() / 100) / sqrt(AD1->getHealth());
	//			AD1->setHealth(AD1->getHealth() - damage_AD1);
	//			if (AD1->getHealth() <= 0)
	//			{
	//				gameptr->addkilled(AD1);
	//			}

	//			else
	//			{
	//				templistdrones.enqueue(AD1);
	//			}
	//			i++;
	//		}
	//		else if (AD1 != nullptr) {
	//			gameptr->getalien()->removeAlienDrone(AD1, AD2);
	//			std::cout << AD1->getID() << " ";
	//			damage_AD1 = (EG->getPower() * EG->getHealth() / 100) / sqrt(AD1->getHealth());
	//			AD1->setHealth(AD1->getHealth() - damage_AD1);

	//			if (AD1->getHealth() <= 0) {
	//				gameptr->addkilled(AD1);
	//			}
	//			else {

	//				templistdrones.enqueue(AD1);
	//			}
	//			i++;
	//			if (AD2 == nullptr) {
	//				continue;
	//			}
	//		}

	//		else if (AD2 != nullptr) {

	//			gameptr->getalien()->removeAlienDrone(AD1, AD2);
	//			std::cout << AD2->getID() << " ";
	//			damage_AD2 = (EG->getPower() * EG->getHealth() / 100) / sqrt(AD2->getHealth());
	//			AD2->setHealth(AD2->getHealth() - damage_AD2);

	//			if (AD2->getHealth() <= 0) {
	//				gameptr->addkilled(AD2);
	//			}
	//			else {

	//				templistdrones.enqueue(AD2);
	//			}
	//			/*else
	//			{
	//				gameptr->getalien()->removeAlienDrone(AD1, AD2);
	//				std::cout << AD1->getID() << " " << AD2->getID() << " ";
	//				damage_AD1 = (EG->getPower() * EG->getHealth() / 100) / sqrt(AD1->getHealth());
	//				AD1->setHealth(AD1->getHealth() - damage_AD1);
	//				damage_AD2 = (EG->getPower() * EG->getHealth() / 100) / sqrt(AD2->getHealth());
	//				AD2->setHealth(AD2->getHealth() - damage_AD2);

	//				if (AD1->getHealth() <= 0)
	//				{
	//					gameptr->addkilled(AD1);
	//				}

	//				else
	//				{
	//					templistdrones.enqueue(AD1);
	//				}
	//				if (AD2->getHealth() <= 0)
	//				{
	//					gameptr->addkilled(AD2);

	//				}

	//				else
	//				{
	//					templistdrones.enqueue(AD2);

	//				}
	//			}*/
	//		}
	//	}
	//}*/
}

void EarthTanks::setOriginalH(int h)
{
	originalHealth = h;
}

int EarthTanks::getOriginalH()
{
	return originalHealth;
}
