#include "game.h"
#include<iostream>
#include<sstream>
#include<fstream>
using namespace std;
game::game() {
    randptr = new RandomGen(this);
   earmy = new EarthArmy();
    aarmy = new AlienArmy();
  
   
}
EarthArmy* game::getearth()
{
    return earmy;
}
AlienArmy* game::getalien()
{
    return aarmy;
}
void game::readfile()
{
    ifstream reader;

    reader.open("input_file.txt");
    if (!reader.is_open()) 
        {
            cout << "Error: Could not open input file!" << endl;
            exit(1);  // Or throw an exception
        }


        // Ranges for unit attributes


        reader >>N>>ESper>>ETper>>EGper>> HUper >>ASper >> AMper >> ADper >> Prob >> PowerMinE  >> PowerMaxE >> HealthMinE  >> HealthMaxE
            >> AttackCapMinE  >> AttackCapMaxE >> PowerMinA  >> PowerMaxA >> HealthMinA  >> HealthMaxA >> AttackCapMinA  >> AttackCapMaxA;

    

}

int game::getN()
{
    return N;
}

int game::getESper()
{
    return ESper;
}

int game::getETper()
{
    return ETper;
}

int game::getEGper()
{
    return EGper;
}

int game::getASper()
{
    return ASper;
}

int game::getAMper()
{
    return AMper;
}

int game::getADper()
{
    return ADper;
}

int game::getProb()
{
    return Prob;
}

int game::getPowerMinE()
{
    return PowerMinE;
}

int game::getPowerMaxE()
{
    return PowerMaxE;
}

int game::getHealthMinE()
{
    return HealthMinE;
}

int game::getHealthMaxE()
{
    return HealthMaxE;
}

int game::getAttackCapMinE()
{
    return AttackCapMinE;
}

int game::getAttackCapMaxE()
{
    return AttackCapMaxE;
}

int game::getPowerMinA()
{
    return PowerMinA;
}

int game::getPowerMaxA()
{
    return PowerMaxA;
}

int game::getHealthMinA()
{
    return HealthMinA;
}

int game::getHealthMaxA()
{
    return HealthMaxA;
}

int game::getAttackCapMinA()
{
    return AttackCapMinA;
}

int game::getAttackCapMaxA()
{
    return AttackCapMaxA;
}

void game::printkilledlist()
{
    cout << "===============killed Units=============" << endl;
    cout<<killedlist.getSize()<<" Units [";
    killedlist.print();
    cout<<"] "<< endl;
}


void game::addkilled(Unit* unit1)
{

    if (unit1)
    {

      killedlist.enqueue(unit1);
    
    }
}

int game::getTime()
{

    return currenttimeStep;
}

void game::addUMLT(EarthTanks*tank)
{
    UMLT.enqueue(tank);
}

void game::addUMLS(EarthSoldiers* soldier,int pri)
{
    UMLS.enqueue(soldier, pri);
}

void game::removeUMLS(EarthSoldiers* soldier,int pri)
{
    if (!UMLS.isEmpty()) {
        UMLS.dequeue(soldier,pri);
}
}

void game::removeUMLT(EarthTanks* tank)
{
    UMLT.dequeue(tank);
}

EarthSoldiers* game::getUMLES()
{
    EarthSoldiers* picked;
    if (UMLS.peek(picked)) {
        return picked;
    }
    else {
        return nullptr;
    }
}

EarthTanks* game::getUMLET()
{
    EarthTanks* picked;
    if (UMLT.peek(picked)) {
        return picked;
    }
    else {
        return nullptr;
    }
}



void game::run()
{
    readfile();
    

    for(int i=1;i<51;i++) {
        cout << "current timestep " << i << endl;;
        
        randptr->generateUnits();
  
        earmy->printAllLists();
        aarmy->printAllLists();
     
        //randptr->randaction();
        cout << " ================Units fighting at current timestep==================== " << endl;
        earmy->attack();
        aarmy->attack();
        printkilledlist();
        
}
}

void game::setTime(int t)
{
    currenttimeStep = t;
}

bool game::emptyUMLS()
{
    if (UMLS.isEmpty())
    {
        return true;
    }
    else { return false; }
}

bool game::emptyUMLT()
{
    if(UMLT.isEmpty())
    {
        return true;
    }
    else
    {
        return false;
    }
}




