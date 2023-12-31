﻿// Day05.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <iomanip>      // std::setw

enum class Weapon
{
	Sword, Axe, Spear, Mace
};

int LinearSearch(std::vector<int> searchVector, int searchTerm)
{
	for (int i = 0; i < searchVector.size(); i++)
	{
		if (searchTerm == searchVector.at(i))
		{
			return i;
		}
	}
	return -1;
}


int main()
{
	/*
		╔═════════╗
		║Searching║
		╚═════════╝

		There are 2 ways to search a vector: linear search or binary search

		CHALLENGE 1:

			write a method to linear search the numbers list.
				The method should take 2 parameters: vector of ints to search, int to search for.
				The method should return -1 if NOT found or the index if found.

			The algorithm:
				1) start at the beginning of the vector
				2) compare each item in the vector to the search item
				3) if found, return the index
				4) if reach the end of the vector, return -1 which means not found

	*/
	std::vector<int> numbers = { 0,1,2,3,4,5,6 };
	int searchNumber = 5;
	int foundIndex = LinearSearch(numbers, searchNumber);
	if (foundIndex == -1)
		std::cout << searchNumber << " was not found!\n";
	else
		std::cout << "Found " << searchNumber << " at index " << foundIndex << "\n";



	/*
		╔═══════════════════╗
		║ map<TKey, TValue> ║
		╚═══════════════════╝

		[  Creating a map  ]

		map<TKey, TValue>  - an associative collection.
			TKey is a placeholder for the type of the keys.
			TValue is a placeholder for the type of the values.

		When you want to create a map variable,
			1) replace TKey with whatever type of data you want to use for the keys
			2) replace TValue with the type you want to use for the values


		[  Adding items to a map  ]

		There are 2 ways to add items to a Dictionary:
		1) using the insert method.
		3) using [key] = value
	*/

	std::map<std::string, float> menu;
	menu["Pineapple Pizza"] = 18.99F;//adds it
	menu["Pineapple Pizza"] = 21.99F;//overwrites the value
	menu["Pepperoni Pizza"] = 14.99F;
	menu["Shrimp Scallop Alfredo"] = 23.99F;

	std::pair<std::string, float> menuItem = std::make_pair("Carnivore Pizza", 19.99F);
	menuItem = std::make_pair("Pineapple Pizza", 25.99F);
	auto wasInserted = menu.insert(menuItem);
	if (wasInserted.second)
		std::cout << menuItem.first << " was inserted\n";
	else
		std::cout << menuItem.first << " was already in the map." << (*wasInserted.first).second;//it does not OVERWRITE


	std::map<Weapon, int> dorasBackpack;//will store the counts of each kind of weapon

	//returns an iterator and a bool. 
	//if the key is already in the map, it will NOT insert it -- the bool will be false.
	auto inserted = dorasBackpack.insert(std::make_pair(Weapon::Sword, 5));
	if (inserted.second == false) //meaning not inserted
		std::cout << "The key was already in the map. It was not inserted.\n";
	else
		std::cout << "The key was inserted in the map.\n";

	dorasBackpack[Weapon::Axe] = 3;
	dorasBackpack[Weapon::Axe] = 7;//simply overwrites the value if the key is already in the map


	/*
		CHALLENGE 2:

			Create a map that stores names (string) and grades. Call the variable grades.
			Add students and grades to your map.

	*/
	std::vector<std::string> names{ "KC", "Kain", "Dillon", "Evan", "Alex", "Christopher", "Jerry", "Mohamad Ali" };

	srand(time(NULL));
	std::map<std::string, float> grades;
	for (auto& name : names)
	{
		//grades[name] = rand() % 101;

		auto gradeInserted = grades.insert(std::make_pair(name, rand() % 101));
		if (gradeInserted.second)
			std::cout << name << " was added to PG2. Good luck!\n";
		else
			std::cout << name << " was somehow already in the course. hmmm.\n";
	}





	/*
		╔═══════════════════╗
		║ map<TKey, TValue> ║
		╚═══════════════════╝

		[  Looping over a map  ]

		You should use a ranged-based for loop when needing to loop over the entire map.

	*/
	for (auto const& [key, val] : dorasBackpack) //requires C++ 20
	{
		switch (key)
		{
		case Weapon::Sword:
			std::cout << "Sword: ";
			break;
		case Weapon::Axe:
			std::cout << "Axe: ";
			break;
		case Weapon::Spear:
			std::cout << "Spear: ";
			break;
		case Weapon::Mace:
			std::cout << "Mace: ";
			break;
		default:
			break;
		}
		std::cout << val << "\n";
	}

	std::cout << "\n-*-*-Chez Fez-*-*-\n";
	for (auto& [menuItemName, itemPrice] : menu)
	{
		std::cout << menuItemName << " " << itemPrice << "\n";
	}
	std::cout << "\n\n";


	/*
		CHALLENGE 4:

			Loop over your grades map and print each student name and grade.

	*/
	std::cout << "\n   PG2 2309   \n";
	for (auto& [studentName, studentGrade] : grades)
	{
		std::cout << std::setw(3) << studentGrade << " " << studentName << "\n";
	}



	/*
		╔═══════════════════╗
		║ map<TKey, TValue> ║
		╚═══════════════════╝

		[  Checking for a key in a map  ]

		use the find method to check if the key is in the map

		will return map.end() if NOT found.

	*/
	std::map<Weapon, int>::iterator foundIter = dorasBackpack.find(Weapon::Mace);
	if (foundIter == dorasBackpack.end()) //meaning it was NOT found
	{
		std::cout << "Dora did not find any maces.\n";
	}
	else
	{
		//can safely grab the value for the key
		std::cout << "Dora found " << foundIter->second << " Maces\n";
	}

	std::string itemToFind = "Chicken Nugget Pizza";
	menu[itemToFind] = 13.99F;
	auto foundItem = menu.find(itemToFind);
	if (foundItem != menu.end())
	{
		float oldPrice = foundItem->second;
		menu[itemToFind] = oldPrice * 1.05F;
		std::cout << itemToFind << " was " << oldPrice << " but now costs " << foundItem->second << ". Thanks Putin!\n";//first is the key, second is the value
	}
	else
		std::cout << itemToFind << " was not found.\n";



	/*
		CHALLENGE 5:

			look for a specific student in the map.
			If the student is found, print out the student's grade
			else print out a message that the student was not found

	*/
	/*
		CHALLENGE 6:

			Pick any student and curve the grade (add 5) that is stored in the grades map

	*/
	std::string student = "KC";
	auto foundStudent = grades.find(student);
	if (foundStudent != grades.end())
	{
		float oldGrade = foundStudent->second;
		grades[student] = std::min<float>(100, oldGrade + 5);
		std::cout << student << " grade was " << oldGrade << " but is " << foundStudent->second << ". Thanks Garrett!\n";//first is the key, second is the value
	}
	else
		std::cout << student << " was not found.\n";


	auto nextStudent = grades.erase(foundStudent);
	//if (nextStudent == grades.end())
	//	std::cout << "Bruce never gets dropped!\n";
	//else
	//	std::cout << student << " was dropped.\n";



	/*
		╔═══════════════════╗
		║ map<TKey, TValue> ║
		╚═══════════════════╝

		[  Updating a value for a key in a map  ]

		To update an exisiting value in the map, use the [ ]


	*/
	dorasBackpack[Weapon::Axe] = 1;//updates the count for the axe



	/*
		CHALLENGE 6:

			Pick any student and curve the grade (add 5) that is stored in the grades map

	*/

	int numberOfItemsRemoved = menu.erase("Cheeseburger Pizza");
	if (numberOfItemsRemoved > 0)
		std::cout << itemToFind << " was removed from the menu. \n";
	else
		std::cout << itemToFind << " was not found.\n";
}