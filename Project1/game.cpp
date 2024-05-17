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
    cout << "===============  Killed Units  =============" << endl;
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
    int i = 1;

    cout << "welcome!\nselect a simulation mode : \n1)interactive mode\n2)silent mode\n";
    cin >> mode;
    if (mode == 1) {
        for ( i ; i < 41; i++) {

            currenttimeStep = i;
            cout << "Current Timestep " << i << endl;
            randptr->generateUnits();

            earmy->printAllLists();
            aarmy->printAllLists();
            
            
            cout << " ================  Units fighting at current timestep  ==================== " << endl;
            earmy->attack();
            aarmy->attack();
            printkilledlist();
            printUML();
            //system("pause");
        }
        while (earmy->getEarmysize() != 0 && aarmy->getAarmysize() != 0) {
            currenttimeStep = i;

            cout << "Current Timestep " << i << endl;

            randptr->generateUnits();
            earmy->printAllLists();
            aarmy->printAllLists();
            //system("pause");
            cout << " ================  Units fighting at current timestep  ==================== " << endl;
            earmy->attack();
            aarmy->attack();
            printkilledlist();
            printUML();
            
            if(currenttimeStep==500){
                cout << "Draw"<<endl;
                break;

            }
           i++;
        }
        if (earmy->getEarmysize() != 0&&currenttimeStep<500) {
            cout << "Earth Army won" << endl;
        }
        else if (aarmy->getAarmysize() != 0&&currenttimeStep<500) {
            cout << "Alien Army won" << endl;
        }
        
    }
    if (mode == 2) {
        cout << "Silent Mode" << "\n" << "Simulation Starts" << "\n";
        for ( i ; i < 41; i++) {
            currenttimeStep = i;
            
            randptr->generateUnits();
            earmy->attack();
            aarmy->attack();
        }
        while (earmy->getEarmysize() != 0 && aarmy->getAarmysize() != 0) {
            currenttimeStep = i;

            //  cout << "Current Timestep " << i << endl;

            randptr->generateUnits();
            earmy->attack();
            aarmy->attack();
            if (currenttimeStep == 500) {
                cout << "Draw" << endl;
                break;

            }
            i++;
        }
        cout << "Simulation ends, Outputfile is created" << "\n";
    }

    printfile();
}
   


void game::setTime()
{
    currenttimeStep++;
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

void game::printfile()
{
    Unit* unit;
    AlienDrones* AD1;
    AlienDrones* AD2;
    aarmy->getAD(AD1, AD2);
    int DfE=0;
    int DdE = 0;
    int DbE = 0;
    int countE = 0;
    int DfA = 0;
    int DdA = 0;
    int DbA = 0;
    int countA = 0;
    ofstream writer("output_file.txt");
    writer << "Td\t\t" << "ID\t\t" << "Tj\t\t" << "Df\t\t" << "Dd\t\t" << "Db" <<"\n";
    while (!killedlist.isEmpty()) {
        killedlist.dequeue(unit);
        if (unit->getID() < 1000) {
            DfE = DfE + unit->getDf();
            DdE = DdE + unit->getDd();
            DbE = DbE + unit->getDb();
            countE++;
        }
        else if(unit->getID()>=2000) {
            DfA = DfA + unit->getDf();
            DdA = DdA + unit->getDd();
            DbA = DbA + unit->getDb();
            countA++;
        }
        writer << unit->getTd() << "\t\t" << unit->getID() << "\t\t" << unit->getJoinTime() << "\t\t" << unit->getDf() << "\t\t" << unit->getDd() << "\t\t" << unit->getDb()<<"\n\n";



    }

    if ((earmy->getEG() != nullptr || earmy->getES() != nullptr || earmy->getET() != nullptr) && (aarmy->getAS() != nullptr || aarmy->getAM() != nullptr||AD1!=nullptr)) 
    {
        writer << "Battle result: Draw\n\n ";
    }
    else if (earmy->getEG() != nullptr || earmy->getES() != nullptr || earmy->getET() != nullptr) {
        writer << "Battle result: Win\n\n ";
    }
    else {
        writer << "Battle result: Loss\n\n";
    }
    int ESdes = (randptr->getESTotalcount() - earmy->getESlistsize());
    int EGdes = (randptr->getEGTotalcount() - earmy->getEGlistsize()) ;
    int ETdes = (randptr->getETTotalcount() - earmy->getETlistsize()) ;
    
    writer << "For Earth Army :\n";
    writer << "Total number of ES " << randptr->getESTotalcount() <<"\n";
    writer << "Total number of ET " << randptr->getETTotalcount() << "\n";
    writer << "Total number of EG " << randptr->getEGTotalcount() <<"\n";
    writer << "Total number of HU " << randptr->getHUTotalcount() << "\n";
    writer << "percentage of destructed ES relative to their total " << static_cast<double>(ESdes) / randptr->getESTotalcount() * 100.0 << "\n";
    writer << "percentage of destructed ET relative to their total " << static_cast<double>(ETdes) / randptr->getETTotalcount() * 100.0 << "\n";
    writer << "percentage of destructed EG relative to their total " << static_cast<double>(EGdes) / randptr->getEGTotalcount() * 100.0 << "\n";
    writer << "percentage of total destructed Earth units relative to their total " << ((static_cast<double>(ESdes) + EGdes + ETdes) / (randptr->getESTotalcount() + randptr->getETTotalcount() + randptr->getEGTotalcount())) * 100.0<<"\n";
    writer << "percentage of healed units relative to total earth units " << (gethealedunits() / (static_cast<double>(randptr->getESTotalcount()) + randptr->getETTotalcount() + randptr->getEGTotalcount())) * 100.0<<"\n";
    writer << "Average of Df for Earth army units " << static_cast<double>(DfE) / countE << "\n";
    writer << "Average of Dd for Earth army units " << static_cast<double>(DdE) / countE << "\n";
    writer << "Average of Db for Earth army units " << static_cast<double>(DbE) / countE << "\n";
    writer << "Df/Db percentage for Earth army " << static_cast<double>(DfE) / DbE << "\n";
    writer << "Dd/Db percentage for Earth army " << static_cast<double>(DdE) / DbE << "\n";

    int ASdes = (randptr->getASTotalcount() - aarmy->getASlistsize());
    int AMdes = (randptr->getAMTotalcount() - aarmy->getAMlistsize());
    int ADdes = (randptr->getADTotalcount() - aarmy->getADlistsize());

    writer << "For Alien Army :\n";
    writer << "Total number of AS " << randptr->getASTotalcount() << "\n";
    writer << "Total number of AM " << randptr->getAMTotalcount() << "\n";
    writer << "Total number of AD " << randptr->getADTotalcount() << "\n";
    writer << "percentage of destructed AS relative to their total " << static_cast<double>(ASdes) / randptr->getASTotalcount() * 100.0 << "\n";
    writer << "percentage of destructed AM relative to their total " << static_cast<double>(AMdes) / randptr->getAMTotalcount() * 100.0 << "\n";
    writer << "percentage of destructed AD relative to their total " << static_cast<double>(ADdes) / randptr->getADTotalcount() * 100.0 << "\n";
    writer << "percentage of total destructed Alien units relative to their total " << ((static_cast<double>(ASdes) + AMdes + ADdes) / (randptr->getASTotalcount() + randptr->getAMTotalcount() + randptr->getADTotalcount())) * 100.0<<"\n";
    writer << "Average of Df for Alien army units " << static_cast<double>(DfA) / countA << "\n";
    writer << "Average of Dd for Alien army units " << static_cast<double>(DdA) / countA << "\n";
    writer << "Average of Db for Alien army units " << static_cast<double>(DbA) / countA << "\n";
    writer << "Df/Db percentage for Alien army " << static_cast<double>(DfA) / DbA << "\n";
    writer << "Dd/Db percentage for Alien army " << static_cast<double>(DdA) / DbA << "\n";
    
}

int game::getmode()
{
    return mode;
}

void game::printUML()
{
    cout << UMLS.getSize() + UMLT.getSize();
    cout << " UML[";
    UMLS.print();
    UMLT.print();
    cout << " ]"<<endl;
}

void game::sethealedunits()
{
    healedunits++;
}

int game::gethealedunits()
{
    return healedunits;
}







