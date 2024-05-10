#include "AlienArmy.h"





void AlienArmy::addAlienSoldier(AlienSoldiers* soldier)
{
	alienSoldierslist.enqueue(soldier);


}

void AlienArmy::removeAlienSoldier(AlienSoldiers* soldier)
{
	alienSoldierslist.dequeue(soldier);
}

void AlienArmy::addAlienDrone(AlienDrones* drone1)
{
	aliendroneslist.pushBack(drone1);

}

void AlienArmy::removeAlienDrone(AlienDrones* drone1, AlienDrones* drone2)
{
	if (drone1 == nullptr) {
		aliendroneslist.popBack(drone2);
	}
	else if (drone2 == nullptr) {
		aliendroneslist.popFront(drone1);
	}
	else if (drone1 == drone2) {
		aliendroneslist.popFront(drone1);
		drone2 = nullptr;
	}
	else {
		aliendroneslist.popFront(drone1);
		aliendroneslist.popBack(drone2);
	}
}

void AlienArmy::removeAlienDronefront(AlienDrones* drone)
{
	aliendroneslist.popFront(drone);
}

void AlienArmy::removeAlienDroneback(AlienDrones* drone)
{
	aliendroneslist.popBack(drone);
}

void AlienArmy::addAlienMonster(AlienMonsters* monster1)
{
	// Add monsters to the BagLinkedList by calling public add function of BagLinkedList
	alienmonstersList.addElement(monster1);

}

void AlienArmy::removeAlienMonster(AlienMonsters* monster1)
{
	alienmonstersList.removeElementrandomly(monster1);
}
void AlienArmy::printaliensoldierlist()
{
	cout << alienSoldierslist.getSize();
	cout << " AS [ ";
	alienSoldierslist.print();
	cout << " ]" << endl;
}
void AlienArmy::printaliendronelist()
{
	cout << aliendroneslist.getSize();
	cout << " AD [";
	aliendroneslist.print();
	cout << " ]" << endl;

}
void AlienArmy::printAllLists()
{
	cout << "======================  Alien Army Alive Units  ============= " << endl;;
	printaliensoldierlist();
	printMonstersList();
	printaliendronelist();
}
AlienSoldiers* AlienArmy::getAS()
{
	AlienSoldiers* picked;
	if (alienSoldierslist.peek(picked)) {
		return picked;
	}
	else {
		return nullptr;
	}
}

void AlienArmy::getAD(AlienDrones*& pickedfront, AlienDrones*& pickedback)
{


	if (aliendroneslist.peekFront(pickedfront) && aliendroneslist.peekBack(pickedback)) {

		return;
	}



}


AlienMonsters* AlienArmy::getAM()
{
	AlienMonsters* picked= alienmonstersList.peek();
	
	return picked;
}

void AlienArmy::printMonstersList()
{
	cout << alienmonstersList.getSize();
	cout << " AM [ ";
	alienmonstersList.print();
	cout << " ]" << endl;
}

void AlienArmy::attack()
{
	AlienSoldiers* AS=nullptr;
	 AS = getAS();
	if (AS != nullptr) {
		AS->attack();
	}
	/*AlienMonsters* AM = getAM();
	if (AM != nullptr) {
		AM->attack();
	}*/
}
int AlienArmy::getASlistsize()
{
	return alienSoldierslist.getSize();
}

int AlienArmy::getADlistsize()
{
	return aliendroneslist.getSize();
}

int AlienArmy::getAMlistsize()
{
	return alienmonstersList.getSize();;
}




