#include "HealUnit.h"
#include"game.h"
HealUnit::HealUnit(int _ID, string type, int _health, int _power, int _attackCapacity, int _jointime,game*g) : Unit(_ID, "HU", _health, _power, _attackCapacity, _jointime,g) 
{
	gameptr = g;
}


void HealUnit::attack()
{
	HealUnit* HU = gameptr->getearth()->getHU();
	LinkedQueue<EarthSoldiers*>tempS;
	LinkedQueue<EarthTanks*>tempT;
	EarthSoldiers* ES;
	EarthTanks* ET;
	int i = 0;
	if (!gameptr->emptyUMLS() || !gameptr->emptyUMLT()) {
		while (i < HU->getAttackCapacity() && !gameptr->emptyUMLS()) {

			ES = gameptr->getUMLES();
			gameptr->removeUMLS(ES, -ES->getHealth());
			if (gameptr->getTime() - ES->gettUML() > 10)
			{
				ES->setTd(gameptr->getTime());
				ES->setDd(ES->getTd() - ES->getTa());
				ES->setDb(ES->getDf() + ES->getDd());
				gameptr->addkilled(ES);
			}
			else {
				int healthIMP = (Power * Health / 100) / sqrt(ES->getHealth());
				ES->setHealth(ES->getHealth() + healthIMP);
				if (ES->getHealth() < 0.2 * ES->getOriginalH())
				{
					tempS.enqueue(ES);
				}

				else {
					gameptr->getearth()->addEarthSoldier(ES);
					gameptr->sethealedunits();
				}
				i++;
			}
		}
		while (i < HU->getAttackCapacity() && !gameptr->emptyUMLT())
		{


			ET = gameptr->getUMLET();
			gameptr->removeUMLT(ET);
			if (gameptr->getTime() - ET->gettUML() > 10)
			{
				ET->setTd(gameptr->getTime());
				ET->setDd(ET->getTd() - ET->getTa());
				ET->setDb(ET->getDf() + ET->getDd());
				gameptr->addkilled(ET);
			}
			else {
				int healthIMP2 = (Power * Health / 100) / sqrt(ET->getHealth());

				ET->setHealth(ET->getHealth() + healthIMP2);
				if (ET->getHealth() < 0.2 * ET->getOriginalH())
				{
					tempT.enqueue(ET);
				}

				else {
					gameptr->getearth()->addEarthtanks(ET);
					gameptr->sethealedunits();
				}
				i++;
			}
		}

		while (!tempS.isEmpty()) {
			tempS.dequeue(ES);
			gameptr->addUMLS(ES, -ES->getHealth());
		}
		while (!tempT.isEmpty()) {
			tempT.dequeue(ET);
			gameptr->addUMLT(ET);
		}
		gameptr->getearth()->removehealunit(HU);
		delete HU;
		HU = nullptr;
		

	}

	

}
