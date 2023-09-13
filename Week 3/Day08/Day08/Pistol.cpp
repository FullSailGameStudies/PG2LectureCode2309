#include "Pistol.h"

void Pistol::showMe() const
{
	Weapon::showMe();
	std::cout << "Rounds: " << mRounds << " Mag capacity: " << mMagCapacity << "\n";
}
