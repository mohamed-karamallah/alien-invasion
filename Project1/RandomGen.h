#pragma once
#include <iostream>
#include<cstdlib>
#include<ctime>
#include <fstream>
#include <sstream>
#include <random>


using namespace std;
class game;
class RandomGen
{
    
    game* gameptr;
    int IDA;
    int IDE;
    int prob;
    int N;
    int minpowerA;
    int maxpowerA ;
    int maxhealthA;
    int minhealthA;

    int mincapacityA;
    int maxcapacityA;
    int minpowerE;
    int maxpowerE;
    int maxhealthE;
    int minhealthE;
    int mincapacityE;
    int maxcapacityE;
    int ES;
    int ET;
    int EG;
    int AS;
    int AD;
    int AM;

public:
    
    RandomGen(game *);
    void generateUnits();
    void generateEarthUnits();
    void generateAlienUnits();
    //int getRandomInt(int min, int max);
    void randaction();
  /*  int gethealthE();
    int getpowerE();
    int getAttackcapeE();
    int getRandomInRange_healthE(int min, int max);
    int getRandomInRange_powerE(int min, int max);
    int getRandomInRange_capacityE(int min, int max);
    int getRandomInRange_healthA(int min, int max);
    int getRandomInRange_powerA(int min, int max);
    int getRandomInRange_capacityA(int min, int max);*/
    int getRandomInRange(int min, int max);

};