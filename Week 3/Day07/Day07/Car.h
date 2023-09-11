#pragma once
#include <string>


class Car
{
public:

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

