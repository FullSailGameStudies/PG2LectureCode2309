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

	Pistol operator+(Pistol const& otherPistol)
	{
		int magCap = std::max<int>(mMagCapacity, otherPistol.mMagCapacity);
		int rounds = std::min<int>(magCap, mRounds + otherPistol.mRounds);
		Pistol newPistol(rounds, magCap, range(), damage());
		return newPistol;
	}

	void showMe() const override;
private:
	int mRounds, mMagCapacity;
};

