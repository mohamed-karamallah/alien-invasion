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
    gameptr->currenttimeStep++;

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
        }
        else if (B <= gameptr->getESper() + gameptr->getETper()) {


            int Health = getRandomInRange(gameptr->getHealthMinE(), gameptr->getHealthMaxE());
            int power = getRandomInRange(gameptr->getPowerMinE(), gameptr->getPowerMaxE());
            int capacity = getRandomInRange(gameptr->getAttackCapMinE(), gameptr->getAttackCapMaxE());
            EarthTanks* ET = new EarthTanks(IDE, "ET", gameptr->getTime(), Health, power, capacity, gameptr);
            gameptr->getearth()->addEarthtanks(ET);
            IDE++;
        }
        else if(B<=gameptr->getESper()+gameptr->getETper()+gameptr->getEGper()) {
            int Health = getRandomInRange(gameptr->getHealthMinE(), gameptr->getHealthMaxE());
            int power = getRandomInRange(gameptr->getPowerMinE(), gameptr->getPowerMaxE());
            int capacity = getRandomInRange(gameptr->getAttackCapMinE(), gameptr->getAttackCapMaxE());
            int priorty = Health * power;
            EarthGunnery* EG = new EarthGunnery(IDE, "EG", gameptr->getTime(), Health, power, capacity, gameptr);
            gameptr->getearth()->addEarthGunnery(EG, priorty);
            IDE++;
        }
        else {
            int Health = getRandomInRange(gameptr->getHealthMinE(), gameptr->getHealthMaxE());
            int power = getRandomInRange(gameptr->getPowerMinE(), gameptr->getPowerMaxE());
            int capacity = getRandomInRange(gameptr->getAttackCapMinE(), gameptr->getAttackCapMaxE());
            HealUnit* HU = new HealUnit(IDE, "HU", gameptr->getTime(), Health, power, capacity, gameptr);
            gameptr->getearth()->addhealunit(HU);
            IDE++;
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
        }
        else if (B <= gameptr->getASper() + gameptr->getADper()) {


            int Health = getRandomInRange(gameptr->getHealthMinA(), gameptr->getHealthMaxA());
            int power = getRandomInRange(gameptr->getPowerMinA(), gameptr->getPowerMaxA());
            int capacity = getRandomInRange(gameptr->getAttackCapMinA(), gameptr->getAttackCapMaxA());
            AlienDrones* AD = new AlienDrones(IDA, "AD", gameptr->getTime(), Health, power, capacity, gameptr);
            gameptr->getalien()->addAlienDrone(AD);
            IDA++;
        }
        else {
            int Health = getRandomInRange(gameptr->getHealthMinA(), gameptr->getHealthMaxA());
            int power = getRandomInRange(gameptr->getPowerMinA(), gameptr->getPowerMaxA());
            int capacity = getRandomInRange(gameptr->getAttackCapMinA(), gameptr->getAttackCapMaxA());
            AlienMonsters* AM = new AlienMonsters(IDA, "AM", gameptr->getTime(), Health, power, capacity, gameptr);
            gameptr->getalien()->addAlienMonster(AM);
            IDA++;
        }

    }
}


//void RandomGen::randaction()
//{
//    int r = getRandomInRange(1, 100);
//    if (r > 0 && r < 10)
//    {
//
//        EarthSoldiers* soldier = gameptr->getearth()->getES();
//        if (soldier == NULL)
//            return;
//        gameptr->getearth()->removeEarthSoldier(soldier);
//        gameptr->getearth()->addEarthSoldier(soldier);
//
//
//
//
//
//    }
//    else if (r > 10 && r < 20) {
//
//        EarthTanks* tank = gameptr->getearth()->getET();
//        if (tank == NULL)
//            return;
//        gameptr->getearth()->removeEarthtanks(tank);
//        gameptr->addkilled(tank);
//
//    }
//    else if (r > 20 && r < 30) {
//
//        EarthGunnery* gunnery = gameptr->getearth()->getEG();
//        if (gunnery == NULL)
//            return;
//        gameptr->getearth()->removeEarthGunnery(gunnery, 1);
//        if (gunnery)
//            gunnery->setHealth(0.5 * gunnery->getHealth());
//    }
//    /*else if (r > 30 && r < 40) {
//
//        AlienSoldiers* soldier = gameptr->getalien()->getAS();
//        if (soldier == NULL)
//            return;
//        AlienArmy* temp[5];
//        for (int i = 0; i < 5; i++) {
//            gameptr->getalien()->removeAlienSoldier(soldier);
//            if (soldier)
//            {
//                soldier->setHealth(0.5 * soldier->getHealth());
//                temp[i]->addAlienSoldier(soldier);
//                gameptr->getalien()->addAlienSoldier(soldier);
//            }
//        }
//    }*/
//    else if (r > 40 && r < 50) {
//
//        AlienMonsters* monster = gameptr->getalien()->getAM();
//        if (monster == NULL)
//            return;
//        for (int i = 0; i < 5; i++) {
//            gameptr->getalien()->removeAlienMonster(monster);
//            gameptr->getalien()->addAlienMonster(monster);
//        }
//    }
//    /*else if (r > 50 && r < 60) {
//        AlienDrones* drone1=nullptr;
//        AlienDrones* drone2=nullptr;
//        gameptr->getalien()->getAD(drone1, drone2);
//        for (int i = 0; i < 3; i++) {
//            if (drone1 == nullptr||drone2==nullptr) {
//                return;
//            }
//            else if (drone1 == drone2) {
//                drone2 = nullptr;
//                gameptr->getalien()->removeAlienDrone(drone1, drone2);
//                gameptr->addkilled(drone1);
//            }
//            else if (drone1 == drone2) {
//                drone2 = nullptr;
//                gameptr->getalien()->removeAlienDrone(drone1, drone2);
//                gameptr->addkilled(drone1);
//            }
//            else //if(drone1!=drone2){
//            {
//                gameptr->getalien()->removeAlienDrone(drone1, drone2);
//                gameptr->addkilled(drone1);
//                gameptr->addkilled(drone2);
//
//
//            }
//        }
//    }*/
//}*/




int RandomGen::getRandomInRange(int min, int max)
{
    return min + rand() % (max - min + 1);
}