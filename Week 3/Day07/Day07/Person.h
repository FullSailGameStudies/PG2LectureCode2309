#pragma once
#include <string>

class Person
{
public:
	Person(int age, std::string name)
	{
		SetAge(age);
		_Name = name;
	}


	int GetAge() const { return age_; }
	void SetAge(int age)
	{
		if (age >= 0 && age <= 120)
			age_ = age;
	}
	std::string GetName() const { return _Name; }
	void SetName(std::string newName)
	{
		_Name = newName;
	}

	void ItsMyBirthday();

private:
	int age_;
	std::string _Name;
};

