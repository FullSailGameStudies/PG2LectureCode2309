#pragma once


//abstract base class
class Weapon
{
public:
	virtual int calcDamage() = 0;//pure virtual
};

class Grenade : public Weapon
{
public:
	//required to implement
	int calcDamage()
	{
		return 10;
	}
};