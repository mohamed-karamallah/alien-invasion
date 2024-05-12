#pragma once
#include"LinkedQueue.h"
#include"LinkedStack.h"
#include"priQueue.h"
#include"EarthSoldiers.h"
#include"EarthGunnery.h"
#include"Earthtanks.h"
#include"HealUnit.h"
class EarthArmy {
private:
    LinkedQueue<EarthSoldiers*> earthSoldierslist;
    priQueue<EarthGunnery*> earthGunnerylist;
    LinkedStack<EarthTanks*>earthtankslist;
    LinkedStack<HealUnit*>heallist;

public:

    void addEarthSoldier(EarthSoldiers* soldier);
    void removeEarthSoldier(EarthSoldiers* soldier);
    void addEarthGunnery(EarthGunnery* gunnery1);
    void removeEarthGunnery(EarthGunnery* gunnery);
    void addEarthtanks(EarthTanks* tank);
    void removeEarthtanks(EarthTanks* tank);
    void printearthsoldierlist();
    void printearthgunnerylist();
    void printearthtankslist();
    void printheallist();
    void addhealunit(HealUnit* unit);
    void removehealunit(HealUnit* unit);
    HealUnit* getHU();
    void printAllLists();
    EarthSoldiers* getES();
    EarthGunnery* getEG();
    EarthTanks* getET();
    void attack();
    int getESlistsize();
    int getEGlistsize();
    int getETlistsize();
   
};