#include "AlienMonsters.h"
#include"game.h"
AlienMonsters::AlienMonsters(int _ID, string type, int _health, int _power, int _attackCapacity, int _jointime, game* g) : Unit(_ID, "AM", _health, _power, _attackCapacity, _jointime,g) 
{ gameptr = g; }


void AlienMonsters::attack()
{
    AlienMonsters* AM = gameptr->getalien()->getAM();
    EarthTanks* ET;
    EarthSoldiers* ES;
    LinkedQueue<Unit*>shot;
    LinkedQueue<EarthSoldiers*>tempES;
    LinkedQueue<EarthTanks*>tempET;


    for (int i = 0; i < AM->getAttackCapacity() / 2; i++) {
        ES = gameptr->getearth()->getES();
        if (ES != NULL)
        {
            gameptr->getearth()->removeEarthSoldier(ES);
            shot.enqueue(ES);
            ES->setOriginalH(ES->getHealth());
            if (ES->getTa() == 0)
            {
                ES->setTa(gameptr->getTime());
            }
            ES->setDf(ES->getTa() - ES->getJoinTime());
            int damage = (AM->getPower() * AM->getHealth() / 100) / sqrt(ES->getHealth());
            ES->setHealth(ES->getHealth() - damage);
            if (ES->getHealth() < 0)
            {
                ES->setTd(gameptr->getTime());
                ES->setDd(ES->getTd() - ES->getTa());
                ES->setDb(ES->getDf() + ES->getDd());
                gameptr->addkilled(ES);
            }
            else if (ES->getHealth() > 0 && ES->getHealth() < 0.2 * ES->getOriginalH()) {
                ES->settUML(gameptr->getTime());

                gameptr->addUMLS(ES, 0);
            }
            else {
                tempES.enqueue(ES);
            }

        }
        else
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
                int damage = (AM->getPower() * AM->getHealth() / 100) / sqrt(ET->getHealth());
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

    for (int i = 0; i < AM->getAttackCapacity() / 2; i++) {
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
            int damage = (AM->getPower() * AM->getHealth() / 100) / sqrt(ET->getHealth());
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
        else
        {
            ES = gameptr->getearth()->getES();
            if (ES != NULL)
            {
                gameptr->getearth()->removeEarthSoldier(ES);
                shot.enqueue(ES);
                ES->setOriginalH(ES->getHealth());
                if (ES->getTa() == 0)
                {
                    ES->setTa(gameptr->getTime());
                }
                ES->setDf(ES->getTa() - ES->getJoinTime());
                int damage = (AM->getPower() * AM->getHealth() / 100) / sqrt(ES->getHealth());
                ES->setHealth(ES->getHealth() - damage);
                if (ES->getHealth() < 0)
                {
                    ES->setTd(gameptr->getTime());
                    ES->setDd(ES->getTd() - ES->getTa());
                    ES->setDb(ES->getDf() + ES->getDd());
                    gameptr->addkilled(ES);
                }
                else if (ES->getHealth() > 0 && ES->getHealth() < 0.2 * ES->getOriginalH()) {
                    ES->settUML(gameptr->getTime());

                    gameptr->addUMLS(ES, 0);
                }
                else {
                    tempES.enqueue(ES);
                }
            }
        }
    }


    while (!tempES.isEmpty())
    {
        tempES.dequeue(ES);
        gameptr->getearth()->addEarthSoldier(ES);
    }
    while (!tempET.isEmpty())
    {
        tempET.dequeue(ET);
        gameptr->getearth()->addEarthtanks(ET);
    }
    if (gameptr->getmode() == 1) {
        std::cout << "AM " << AM->getID() << " shots [ ";
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




