#include "RandomGen.h"
#include "game.h"

RandomGen::RandomGen(game * g)
{
    gameptr = g;
    IDE = 1;
    IDA = 2000;
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // Seed for random number generation to the current time

}

void RandomGen::generateUnits()
{
    int A = rand() % 100 + 1; // Generate a random number between 1 and 100

    if (A <= gameptr->getProb()) {
        generateEarthUnits();
        generateAlienUnits();
    }
    
    //gameptr->setTime();

}



void RandomGen::generateEarthUnits()
{


    for (int i = 0; i < gameptr->getN(); i++) {
        int B = rand() % 100 + 1;

        if (B <= gameptr->getESper()) {
            int Health = getRandomInRange(gameptr->getHealthMinE(), gameptr->getHealthMaxE());
            int power = getRandomInRange(gameptr->getPowerMinE(), gameptr->getPowerMaxE());
            int capacity = getRandomInRange(gameptr->getAttackCapMinE(), gameptr->getAttackCapMaxE());
            EarthSoldiers* ES = new EarthSoldiers(IDE, "ES", gameptr->getTime(), Health, power, capacity,gameptr);
            gameptr->getearth()->addEarthSoldier(ES);
            IDE++;
            TotalcountES++;
        }
        else if (B <= gameptr->getESper() + gameptr->getETper()) {


            int Health = getRandomInRange(gameptr->getHealthMinE(), gameptr->getHealthMaxE());
            int power = getRandomInRange(gameptr->getPowerMinE(), gameptr->getPowerMaxE());
            int capacity = getRandomInRange(gameptr->getAttackCapMinE(), gameptr->getAttackCapMaxE());
            EarthTanks* ET = new EarthTanks(IDE, "ET", gameptr->getTime(), Health, power, capacity, gameptr);
            gameptr->getearth()->addEarthtanks(ET);
            IDE++;
            TotalcountET++;
        }
        else if(B<=gameptr->getESper()+gameptr->getETper()+gameptr->getEGper()) {
            int Health = getRandomInRange(gameptr->getHealthMinE(), gameptr->getHealthMaxE());
            int power = getRandomInRange(gameptr->getPowerMinE(), gameptr->getPowerMaxE());
            int capacity = getRandomInRange(gameptr->getAttackCapMinE(), gameptr->getAttackCapMaxE());
            int priorty = Health * power;
            EarthGunnery* EG = new EarthGunnery(IDE, "EG", gameptr->getTime(), Health, power, capacity, gameptr);
            gameptr->getearth()->addEarthGunnery(EG, priorty);
            IDE++;
            TotalcountEG++;
        }
        else {
            int Health = getRandomInRange(gameptr->getHealthMinE(), gameptr->getHealthMaxE());
            int power = getRandomInRange(gameptr->getPowerMinE(), gameptr->getPowerMaxE());
            int capacity = getRandomInRange(gameptr->getAttackCapMinE(), gameptr->getAttackCapMaxE());
            HealUnit* HU = new HealUnit(IDE, "HU", gameptr->getTime(), Health, power, capacity, gameptr);
            gameptr->getearth()->addhealunit(HU);
            IDE++;
            TotalcountHU++;


        }

    }

}

void RandomGen::generateAlienUnits()
{
    for (int i = 0; i < gameptr->getN(); i++) {
        int B = rand() % 100 + 1;

        if (B <= gameptr->getASper()) {
            int Health = getRandomInRange(gameptr->getHealthMinA(), gameptr->getHealthMaxA());
            int power = getRandomInRange(gameptr->getPowerMinA(), gameptr->getPowerMaxA());
            int capacity = getRandomInRange(gameptr->getAttackCapMinA(), gameptr->getAttackCapMaxA());
            AlienSoldiers* AS = new AlienSoldiers(IDA, "AS", gameptr->getTime(), Health, power, capacity, gameptr);
            gameptr->getalien()->addAlienSoldier(AS);
            IDA++;
            TotalcountAS++;
        }
        else if (B <= gameptr->getASper() + gameptr->getAMper()) {

            int Health = getRandomInRange(gameptr->getHealthMinA(), gameptr->getHealthMaxA());
            int power = getRandomInRange(gameptr->getPowerMinA(), gameptr->getPowerMaxA());
            int capacity = getRandomInRange(gameptr->getAttackCapMinA(), gameptr->getAttackCapMaxA());
            AlienMonsters* AM = new AlienMonsters(IDA, "AM", gameptr->getTime(), Health, power, capacity, gameptr);
            gameptr->getalien()->addAlienMonster(AM);
            IDA++;
            TotalcountAM++;
        }
        else {
            int Health = getRandomInRange(gameptr->getHealthMinA(), gameptr->getHealthMaxA());
            int power = getRandomInRange(gameptr->getPowerMinA(), gameptr->getPowerMaxA());
            int capacity = getRandomInRange(gameptr->getAttackCapMinA(), gameptr->getAttackCapMaxA());
            AlienDrones* AD = new AlienDrones(IDA, "AD", gameptr->getTime(), Health, power, capacity, gameptr);
            gameptr->getalien()->addAlienDrone(AD);
            IDA++;
            TotalcountAD++;
        }

    }
}

int RandomGen::getESTotalcount()
{
    return TotalcountES;
}

int RandomGen::getEGTotalcount()
{
    return TotalcountEG;
}

int RandomGen::getETTotalcount()
{
    return TotalcountET;
}

int RandomGen::getHUTotalcount()
{
    return TotalcountHU;
}

int RandomGen::getASTotalcount()
{
    return TotalcountAS;
}

int RandomGen::getAMTotalcount()
{
    return TotalcountAM;
}

int RandomGen::getADTotalcount()
{
    return TotalcountAD;
}

int RandomGen::getRandomInRange(int min, int max)
{
    return min + rand() % (max - min + 1);
}