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

protected:

private:
	std::string mMake, _model;
	int year_; //m_iYear

};

