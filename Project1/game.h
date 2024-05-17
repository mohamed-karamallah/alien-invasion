#include<iostream>
#include"Unit.h"
#include"EarthArmy.h"
#include"AlienArmy.h"
#include<sstream>
#include"RandomGen.h"
#include"EarthGunnery.h"
using namespace std;

class game
{
private:

	RandomGen* randptr;
	EarthArmy *earmy;
	AlienArmy *aarmy;
	LinkedQueue<Unit*> killedlist;
	LinkedQueue<EarthTanks*>UMLT;
	priQueue<EarthSoldiers*>UMLS;
	int N=0;
	int ESper=0;
	int ETper=0;
	int EGper=0;
	int HUper=0;
	int ASper=0;
	int AMper=0;
	int ADper=0;
	int Prob=0;
	int PowerMinE=0;
	int PowerMaxE=0;
	int HealthMinE=0;
	int HealthMaxE=0;
	int AttackCapMinE=0;
	int AttackCapMaxE=0;
	int PowerMinA=0;
	int PowerMaxA=0;
	int HealthMinA=0;
	int HealthMaxA=0;
	int AttackCapMinA=0;
	int AttackCapMaxA=0;
	int currenttimeStep=0 ;
	int mode=0;
	int healedunits = 0;
public:
	
	
	game();
	EarthArmy* getearth();
	AlienArmy* getalien();
	void readfile();
	int getN();
	int getESper();
	int getETper();
	int getEGper();
	int getASper();
	int getAMper();
	int getADper();
	int getProb();
	int getPowerMinE();
	int getPowerMaxE();
	int getHealthMinE();
	int getHealthMaxE();
	int getAttackCapMinE();
	int getAttackCapMaxE();
	int getPowerMinA();
	int getPowerMaxA();
	int getHealthMinA();
	int getHealthMaxA();
	int getAttackCapMinA();
	int getAttackCapMaxA();
	void printkilledlist();
	void addkilled(Unit* unit1);
	int getTime();
	void addUMLT(EarthTanks*tank);
	void addUMLS(EarthSoldiers*soldier,int pri);
	void removeUMLS(EarthSoldiers* soldier,int pri);
	void removeUMLT(EarthTanks* tank);
	EarthSoldiers* getUMLES();
	EarthTanks* getUMLET();
	void run();
	void setTime();
	bool emptyUMLS();
	bool emptyUMLT();
	void printfile();
	int getmode();
	void printUML();
	void sethealedunits();
	int gethealedunits();

};