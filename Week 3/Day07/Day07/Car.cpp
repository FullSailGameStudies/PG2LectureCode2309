#include "Car.h"
#include <iostream>

int Car::_numberOfCarsMade = 0;

void Car::VehicleInformation() //instance methods can access instance fields AND static fields
{
	std::cout << year_ << " " << mMake << " " << _model << "\n" << "Number of cars made: " << _numberOfCarsMade;
}
