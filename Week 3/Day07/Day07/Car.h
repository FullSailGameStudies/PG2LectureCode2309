#pragma once
#include <string>


class Car
{
public:
	//ctor (constructor)
	//Car() //default (no parameters)
	//{

	//}

	Car(int year, std::string make, std::string model) : 
		mMake(make), 
		_model(model)
	{
		++_numberOfCarsMade;
		//year_ = year; //assign the parameter to the field
		Year(year);
		//mMake = make;
		//_model = model;
	}

	void VehicleInformation();

	//getter
	int Year() const { return year_; }

	//setter
	void Year(int year)
	{
		if (year >= 1908 && year <= 2025)
			year_ = year;
	}

	//static methods can ONLY access static members (fields/methods)
	//static methods do not have the 'this' parameter
	static void CarReport() 
	{
		std::cout << "number of cars made: " << _numberOfCarsMade << "\n";
	}

protected:

private:
	//field at the INSTANCE level
	//to access instance fields/methods, we use the variable. EX: heroDB.Count();
	std::string mMake, _model; //NON-static. each Car instance has its own year,make,model
	int year_; //m_iYear

	//field at the CLASS level
	//to access STATIC members (fields/methods), we use the class name. EX: Hero::Compare(hero1,hero2,sortBy)
	static int _numberOfCarsMade;//SHARED across all instances of Car. only 1 of these.

};

