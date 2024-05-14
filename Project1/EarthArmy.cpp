#include "EarthArmy.h"
#include<iostream>
using namespace std;


void EarthArmy::addEarthSoldier(EarthSoldiers* soldier)
{
    earthSoldierslist.enqueue(soldier);

}


void EarthArmy::removeEarthSoldier(EarthSoldiers* soldier)
{
    if (!earthSoldierslist.isEmpty())
        earthSoldierslist.dequeue(soldier);
   
}

void EarthArmy::addEarthGunnery(EarthGunnery* gunnery)
{
    int priority = gunnery->getPower() * gunnery->getHealth();
    earthGunnerylist.enqueue(gunnery, priority);

}

void EarthArmy::removeEarthGunnery(EarthGunnery* gunnery)
{
    int priority = gunnery->getPower() * gunnery->getHealth();
    if (!earthGunnerylist.isEmpty())
        earthGunnerylist.dequeue(gunnery, priority);
}

void EarthArmy::addEarthtanks(EarthTanks* tank)
{
    earthtankslist.push(tank);

}

void EarthArmy::removeEarthtanks(EarthTanks* tank)
{
    if (!earthtankslist.isEmpty())
        earthtankslist.pop(tank);
}
void EarthArmy::printearthsoldierlist()
{
    cout << earthSoldierslist.getSize();
    cout << " ES [ ";
    earthSoldierslist.print();
    cout << " ]" << endl;
}
void EarthArmy::printearthgunnerylist()
{
    cout << earthGunnerylist.getSize();
    cout << " EG [";
    earthGunnerylist.print();
    cout << " ]" << endl;
}

void EarthArmy::printearthtankslist()
{
    cout << earthtankslist.getlength();
    cout << " ET [";
    earthtankslist.print();
    cout << " ]" << endl;
}

void EarthArmy::printheallist()
{
    cout << heallist.getlength();
    cout << " HL [";
    heallist.print();
    cout << " ]" << endl;
}

void EarthArmy::addhealunit(HealUnit* unit)
{
    heallist.push(unit);
}

void EarthArmy::removehealunit(HealUnit* unit)
{
    heallist.pop(unit);
}

HealUnit* EarthArmy::getHU()
{
    HealUnit* picked=nullptr;
    if (heallist.peek(picked)) {
        return picked;
    }
    else {
        return nullptr;
    }
}



void EarthArmy::printAllLists()
{
    cout << " ======================  Earth Army Alive Units  ============= " << endl;
    printearthsoldierlist();
    printearthtankslist();
    printearthgunnerylist();
    printheallist();
}

EarthSoldiers* EarthArmy::getES()
{
    EarthSoldiers* picked= nullptr;
    if (earthSoldierslist.peek(picked)) {
        return picked;
    }
    else {
        return nullptr;
    }
}

EarthGunnery* EarthArmy::getEG()
{
    EarthGunnery* picked= nullptr;
    //int pri = picked->getHealth() * picked->getPower();
    if (earthGunnerylist.peek(picked)) {
        return picked;
    }
    else {
        return nullptr;
    }
}

EarthTanks* EarthArmy::getET()
{
    EarthTanks* picked= nullptr;
    if (earthtankslist.peek(picked)) {
        return picked;
    }
    else {
        return nullptr;
    }
}

void EarthArmy::attack()
{
    EarthSoldiers* ES = nullptr;
     ES = getES();
    if (ES != nullptr){
        ES->attack();
}
    EarthGunnery* EG = nullptr;
        EG=getEG();
    if (EG != nullptr) {
        EG->attack();
    }
    EarthTanks* ET = getET();
    if (ET != nullptr) {
        ET->attack();
    }
    HealUnit* HU = nullptr;
    HU = getHU();
    if (HU != nullptr) {
        HU->attack();
    }
}

int EarthArmy::getESlistsize()
{
    return earthSoldierslist.getSize();
}

int EarthArmy::getEGlistsize()
{
    return earthGunnerylist.getSize();
}

int EarthArmy::getETlistsize()
{
    return earthtankslist.getSize();
}

int EarthArmy::getEarmysize()
{
    return getESlistsize() + getEGlistsize() + getETlistsize();
}






