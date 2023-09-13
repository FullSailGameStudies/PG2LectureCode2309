#pragma once
#include "Weapon.h"
#include <iostream>
class Pistol : public Weapon
{
public:
	Pistol(int rounds, int magCap, int range, int damage) : 
		Weapon(range, damage), mRounds(rounds), mMagCapacity(magCap)
	{
	}
private:
	int mRounds, mMagCapacity;
};
