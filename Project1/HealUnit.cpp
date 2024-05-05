#include "HealUnit.h"
#include"game.h"
HealUnit::HealUnit(int _ID, string type, int _health, int _power, int _attackCapacity, int _jointime,game*g) : Unit(_ID, "HU", _health, _power, _attackCapacity, _jointime,g) 
{
	gameptr = g;
}


void HealUnit::attack(Unit* HU)
{

}
LinkedQueue<EarthSoldiers*>tempS;
LinkedQueue<EarthTanks*>tempT;
void HealUnit::heal()
{
	int i ;
	for ( i =0; i < AttackCapacity; i++) {
		while (!gameptr->emptyUMLS())
		{
			EarthSoldiers* ES = gameptr->getUMLES();
			if (gameptr->currenttimeStep - ES->getTa() > 10)
			{
				gameptr->addkilled(ES);
			}
			else {
				int healthIMP = (Power * Health / 100) / sqrt(ES->getHealth());
				ES->setOriginalH(ES->getHealth());
				ES->setHealth(ES->getHealth() + healthIMP);
				if (ES->getHealth() < 0.2 * ES->getOriginalH())
				{
					tempS.enqueue(ES);
					gameptr->addUMLS(ES, -ES->getHealth());

				}

				else {
					gameptr->getearth()->addEarthSoldier(ES);
				}
			}
		}
		i++;
	}
	while (i < AttackCapacity)
	{
		while(!gameptr->emptyUMLT())
		{
			EarthTanks* ET = gameptr->getUMLET();
			if (gameptr->currenttimeStep - ET->getTa() > 10)
			{
				gameptr->addkilled(ET);
			}
			else {
				int healthIMP2 = (Power * Health / 100) / sqrt(ET->getHealth());
				ET->setOriginalH(ET->getHealth());
				ET->setHealth(ET->getHealth() + healthIMP2);
				if (ET->getHealth() < 0.2 * ET->getOriginalH())
				{
					tempT.enqueue(ET);
					gameptr->addUMLT(ET);

				}

				else {
					gameptr->getearth()->addEarthtanks(ET);
				}
			}
		}
		
	}
	i++;
}
