#include "Unit.h"
#include"game.h"

Unit::Unit(int _ID, string _type, int _joinTime, int _health, int _power, int _attackCapacity,game*g) : ID(_ID), Type(_type), JoinTime(_joinTime), Health(_health), Power(_power), AttackCapacity(_attackCapacity) 
{
	 gameptr = g;

}
Unit::Unit()
{

}
string Unit::getType()
{
	return Type;
}

int Unit::getID()
{
	return ID;
}

int Unit::getHealth()
{
	return Health;
}

int Unit::getPower()
{
	return Power;
}

int Unit::getAttackCapacity()
{
	return AttackCapacity;
}

int Unit::getJoinTime()
{
	return JoinTime;
}

void Unit::setID(int newID)
{if (newID>0)
	ID = newID;
else
cout << "error" << endl;
}

void Unit::setType(const string& newType)
{
}

void Unit::setJoinTime(int newJoinTime)
{
	if (newJoinTime > 0 && newJoinTime < 50)
		JoinTime = newJoinTime;
	else
		cout << "error" << endl;
}

void Unit::setHealth(int newHealth)
{
	Health = newHealth;
}

void Unit::setPower(int newPower)
{
	Power = newPower;
}

void Unit::setAttackCapacity(int newAttackCapacity)
{
	AttackCapacity = newAttackCapacity;
}

void Unit::setTa(int t)
{
	Ta = t;
}

void Unit::setTd(int t)
{
	Td = t;
}

int Unit::getTd()
{
	return Td;
}

int Unit::getTa()
{
	return Ta;
}

void Unit::setDf(int t)
{
	Df = t;
}

void Unit::setDd(int t)
{
	Dd = t;
}

void Unit::setDb(int t)
{
	Db = t;
}

void Unit::settUML(int t)
{
	tUML = t;
}

int Unit::getDf()
{
	return Df;
}

int Unit::getDd()
{
	return Dd;
}

int Unit::getDb()
{
	return Db;
}

int Unit::gettUML()
{
	return tUML;
}




