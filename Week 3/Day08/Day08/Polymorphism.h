#pragma once
#include <iostream>
#include <string>

/*

	COMPILE-TIME Polymorphism

	Method Overloading:
		- changing the number of parameters
		- changing the types of the parameters

*/
class Calculator
{
public:
	int add(int n1, int n2);
	int add(int n1, int n2, int n3);
	float add(float f1, float f2);
	double add(double d1, double d2);
};


/*

	COMPILE-TIME Polymorphism

	Operator Overloading

*/
class Account
{
private:
	double mBalance;

public:
	Account(double initialBalance) : mBalance(initialBalance)
	{
		
	}
	Account operator+(Account const& otherAccount)
	{
		Account result(0);
		result.mBalance = mBalance + otherAccount.mBalance;
		return result;
	}
};




/*

	RUNTIME Polymorphism

	method overriding

*/
class base
{
private:
	int mNum;
public:
	base(int num) : mNum(num)
	{

	}
	virtual void print()
	{
		std::cout << "Hello base " << mNum << "\n";
	}
};

class derived : public base
{
private:
	std::string mStr;
public:
	derived(std::string str, int num) : base(num), mStr(str)
	{ }

	void print() override //its an override now b/c the base is virtual
	{
		//fully override (don't call the base version)
		// 
		//   or...
		// 
		//extension override (call the base version)
		base::print();
		std::cout << "\t Hello derived " << mStr << "\n";
	}
};
