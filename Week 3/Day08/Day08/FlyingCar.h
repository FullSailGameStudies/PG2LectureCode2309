#pragma once
#include "Car.h"
#include <iostream>
class FlyingCar : public Car
{
public:
	FlyingCar(int maxAltitude, int year, std::string make, std::string model) :
		Car(year, make, model), mMaxAltitude(maxAltitude)
	{
		std::cout << "Flying Car\n";
	}

private:
	int mMaxAltitude;
};

