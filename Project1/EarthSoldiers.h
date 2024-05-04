#pragma once
#include <iostream>
#include"Unit.h"
#include"AlienSoldiers.h"
#include"LinkedQueue.h"
using namespace std;
class EarthSoldiers : public Unit
{
private:
    int originalHealth;

public:
    EarthSoldiers(int _ID, string _type, int _health, int _power, int _attackCapacity, int _jointime, game* g);
    void attack(Unit*ES);
    void setOriginalH(int h);
    int getOriginalH();
   


};
