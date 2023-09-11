#include "Person.h"
#include <iostream>

void Person::ItsMyBirthday()
{
	++age_;
	std::cout << "It's my birthday!! I'm turning " << age_ << " today!! Let's have some cake!\n";
}
