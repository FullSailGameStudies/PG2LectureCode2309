#pragma once
#include <iostream>
#include <string>

class Superhero
{
	std::string name_;
	std::string secret_;
	int age_;

public:

	Superhero(std::string name, std::string secret, int age) :
		name_(name), secret_(secret), age_(age)
	{

	}

	void WhoAmI()
	{
		std::cout << "Hello citizen! I am " << name_ << "! (aka " << secret_ << "). And I am " << age_ << " years old!!\n";
	}
};

