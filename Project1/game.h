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
	int N;
	int ESper;
	int ETper;
	int EGper;
	int HUper;
	int ASper;
	int AMper;
	int ADper;
	int Prob;
	int PowerMinE;
	int PowerMaxE;
	int HealthMinE;
	int HealthMaxE;
	int AttackCapMinE;
	int AttackCapMaxE;
	int PowerMinA;
	int PowerMaxA;
	int HealthMinA;
	int HealthMaxA;
	int AttackCapMinA;
	int AttackCapMaxA;


protected:


public:
	int currenttimeStep=1;
	
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
	void setTime(int t);
	bool emptyUMLS();
	bool emptyUMLT();
	void printfile();
	

};