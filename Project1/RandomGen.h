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
    int TotalcountES=0;
    int TotalcountEG=0;
    int TotalcountET=0;
    int TotalcountHU = 0;
    int TotalcountAS=0;
    int TotalcountAM=0;
    int TotalcountAD=0;


public:
    
    RandomGen(game *);
    void generateUnits();
    void generateEarthUnits();
    void generateAlienUnits();
    void randaction();
    int getESTotalcount();
    int getEGTotalcount();
    int getETTotalcount();
    int getHUTotalcount();
    int getASTotalcount();
    int getAMTotalcount();
    int getADTotalcount();
    int getRandomInRange(int min, int max);
    

};