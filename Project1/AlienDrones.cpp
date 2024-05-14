#include "AlienDrones.h"
#include"game.h"


AlienDrones::AlienDrones(int _ID, string type, int _health, int _power, int _attackCapacity, int _jointime, game* g) : Unit(_ID, "AD", _health, _power, _attackCapacity, _jointime,g)
{ gameptr = g; }

void AlienDrones::attack()
{
	AlienDrones* AD1 = nullptr;
	AlienDrones* AD2 = nullptr;
	EarthGunnery* EG;
	EarthTanks* ET;
	LinkedQueue<EarthGunnery*>templist;
	LinkedQueue<EarthTanks*>tempET;
	LinkedQueue<Unit*>shot;



	gameptr->getalien()->getAD(AD1, AD2);
	//std::cout << "AD " << AD1->getID() << " shots [ ";
	//attack tanks
	for (int i = 0; i < AD1->getAttackCapacity(); i++)
	{
		EG = gameptr->getearth()->getEG();
		if (EG != NULL)
		{
			gameptr->getearth()->removeEarthGunnery(EG);
			shot.enqueue(EG);

			if (EG->getTa() == 0)
			{
				EG->setTa(gameptr->getTime());
			}
			EG->setDf(EG->getTa() - EG->getJoinTime());
			int damage = (AD1->getPower() * AD1->getHealth() / 100) / sqrt(EG->getHealth());
			EG->setHealth(EG->getHealth() - damage);
			if (EG->getHealth() < 0)
			{
				EG->setTd(gameptr->getTime());
				EG->setDd(EG->getTd() - EG->getTa());
				EG->setDb(EG->getDf() + EG->getDd());
				gameptr->addkilled(EG);
			}
			else
			{
				templist.enqueue(EG);
			}

		}
		else{
			ET = gameptr->getearth()->getET();
			if (ET != NULL)
			{
				gameptr->getearth()->removeEarthtanks(ET);
				shot.enqueue(ET);
				ET->setOriginalH(ET->getHealth());
				if (ET->getTa() == 0)
				{
					ET->setTa(gameptr->getTime());
				}
				ET->setDf(ET->getTa() - ET->getJoinTime());
				int damage = (AD1->getPower() * AD1->getHealth() / 100) / sqrt(ET->getHealth());
				ET->setHealth(ET->getHealth() - damage);
				if (ET->getHealth() < 0)
				{
					ET->setTd(gameptr->getTime());
					ET->setDd(ET->getTd() - ET->getTa());
					ET->setDb(ET->getDf() + ET->getDd());
					gameptr->addkilled(ET);
				}
				else if (ET->getHealth() > 0 && ET->getHealth() < 0.2 * ET->getOriginalH()) {
					ET->settUML(gameptr->getTime());

					gameptr->addUMLT(ET);
				}
				else
				{
					tempET.enqueue(ET);
				}
			}
		}

	}
	
	if (gameptr->getmode() == 1) {
	std::cout << "AD " << AD1->getID() << " shots [ ";
	
		while (!shot.isEmpty()) {
			Unit* unit;
			shot.dequeue(unit);
			std::cout << unit->getID();

			// Check if there are more elements in the list
			if (!shot.isEmpty()) {
				std::cout << " , ";
			}
		}
		std::cout << "]" << endl;
	}

	

	//attack tanks
	//std::cout << "AD " << AD2->getID() << " shots [ ";
	for (int i = 0; i < AD2->getAttackCapacity(); i++)
	{
		ET = gameptr->getearth()->getET();
		if (ET != NULL)
		{
			gameptr->getearth()->removeEarthtanks(ET);
			shot.enqueue(ET);
			ET->setOriginalH(ET->getHealth());
			if (ET->getTa() == 0)
			{
				ET->setTa(gameptr->getTime());
			}
			ET->setDf(ET->getTa() - ET->getJoinTime());
			int damage = (AD2->getPower() * AD2->getHealth() / 100) / sqrt(ET->getHealth());
			ET->setHealth(ET->getHealth() - damage);
			if (ET->getHealth() < 0)
			{
				ET->setTd(gameptr->getTime());
				ET->setDd(ET->getTd() - ET->getTa());
				ET->setDb(ET->getDf() + ET->getDd());
				gameptr->addkilled(ET);
			}
			else if (ET->getHealth() > 0 && ET->getHealth() < 0.2 * ET->getOriginalH()) {
				ET->settUML(gameptr->getTime());

				gameptr->addUMLT(ET);
			}
			else
			{
				tempET.enqueue(ET);
			}
		}
		else{
			EG = gameptr->getearth()->getEG();
			if (EG != NULL)
			{
				gameptr->getearth()->removeEarthGunnery(EG);
				shot.enqueue(EG);

				if (EG->getTa() == 0)
				{
					EG->setTa(gameptr->getTime());
				}
				EG->setDf(EG->getTa() - EG->getJoinTime());
				int damage = (AD2->getPower() * AD2->getHealth() / 100) / sqrt(EG->getHealth());
				EG->setHealth(EG->getHealth() - damage);
				if (EG->getHealth() < 0)
				{
					EG->setTd(gameptr->getTime());
					EG->setDd(EG->getTd() - EG->getTa());
					EG->setDb(EG->getDf() + EG->getDd());
					gameptr->addkilled(EG);
				}
				else
				{
					templist.enqueue(EG);
				}

			}
		}
	}
	while (!templist.isEmpty())
	{
		templist.dequeue(EG);
		gameptr->getearth()->addEarthGunnery(EG);
	}
	while (!tempET.isEmpty())
	{
		tempET.dequeue(ET);
		gameptr->getearth()->addEarthtanks(ET);
	}
	if (gameptr->getmode() == 1) {
		std::cout << "AD " << AD2->getID() << " shots [ ";
		while (!shot.isEmpty()) {
			Unit* unit;
			shot.dequeue(unit);
			std::cout << unit->getID();

			// Check if there are more elements in the list
			if (!shot.isEmpty()) {
				std::cout << " , ";
			}
		}
		std::cout << " ]" << endl;
	}

}



