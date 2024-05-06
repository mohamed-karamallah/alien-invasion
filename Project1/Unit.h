#pragma once
#include<iostream>
#include <string.h>

using namespace std;
class game;

class Unit
{
protected:
	int ID;
	int JoinTime;
	int Health;
	int Power;
	int AttackCapacity;
	string Type;
	game* gameptr ;
	int  Ta=0;
	int Df;
	int Dd;
	int Db;
	int tUML;
	int Td;

public:
	Unit();
	Unit(int _ID, string _type, int _joinTime, int _health, int _power, int _attackCapacity,game*g);
	virtual void attack() = 0;
	string getType();
		int getID();
	int getHealth();
		int getPower();
		int getAttackCapacity();
		int getJoinTime();
		// Setters for each attribute
		void setID(int newID);
		void setType(const string& newType);
		void setJoinTime(int newJoinTime);
		void setHealth(int newHealth);
		void setPower(int newPower);
		void setAttackCapacity(int newAttackCapacity);
		void setTa(int t);
		void setTd(int t);
		int getTd();
		int getTa();
		void setDf(int t);
		void setDd(int t);
		void setDb(int  t);
		void settUML(int t);
		int getDf();
		int getDd();
		int getDb();
		int gettUML();

		
};


