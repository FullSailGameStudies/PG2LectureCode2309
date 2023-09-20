// Day11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Car.h"
#include <vector>
#include <fstream>

void DumpGarage(const std::vector<Car>& cars, std::ostream& stream, char delim)
{
	bool isFirst = true;
	for (auto& car : cars)
	{
		if (!isFirst)
			stream << "\n";
		car.serialize(stream, delim);
		isFirst = false;
	}
}
int main()
{
	std::cout << "Gone in 60 Seconds!\n";//https://carbuzz.com/features/beyond-eleanor-gone-in-60-seconds-car-names#:~:text=The%20Complete%20List%20Of%20Gone%20In%2060%20Seconds,8%201961%20Porsche%20Speedster%20-%20%22Natalie%22%20More%20items


	std::vector<Car> garage;
	garage.push_back(Car(1967, "Ford", "Shelby Mustang GT500"));
	garage.push_back(Car(1956, "Ford", "T Bird"));
	garage.push_back(Car(1961, "Porsche", "Speedster"));
	garage.push_back(Car(1965, "Pontiac", "GTO"));
	garage.push_back(Car(1969, "Plymouth", "Hemi Cuda"));

	/*
		╔═════════════╗
		║ Serializing ║
		╚═════════════╝

		Saving the state (data) of objects

		Lecture Code: serialize the vector of Cars to a file.
			Data Format:
				separates cars. EX: car1|car2|car3
				separates data inside a car. EX: 1967;Ford;Shelby Mustang GT500

	*/
	std::string filePath = "myGarage.csv";
	{
		std::ofstream outFile(filePath);
		if(outFile.is_open())
			DumpGarage(garage, outFile, ',');
	}


	std::cout << "\n  MY GARAGE  \n";
	DumpGarage(garage, std::cout, ',');



	/*
		╔═══════════════╗
		║ Deserializing ║
		╚═══════════════╝

		Recreating the objects from the saved state (data) of objects

		Lecture Code:
			Open the file
			Read in each line
			split each line to get each car
			split each car to get the car details

	*/

	std::vector<Car> stolenCars;
	std::ifstream inFile(filePath);
	std::string line;
	if (inFile.is_open())
	{
		while (!inFile.eof())
		{
			std::getline(inFile, line);//get the next car line

			Car lifted(line, ',');
			stolenCars.push_back(lifted);
		}
	}
	std::cout << "\n  Nick's GARAGE  \n";
	DumpGarage(stolenCars, std::cout, '\t');
}