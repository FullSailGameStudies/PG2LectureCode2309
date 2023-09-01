﻿// Day03.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include "ThemeSong.h"

std::string postFix(std::string fileName, int postFixNumber = 1) //postFixNumber is optional
{
    return fileName + "_" + std::to_string(postFixNumber);
}

void Print(const std::vector<std::string>& names)
{
    std::cout << "  VECTOR OF NAMES   \n";
    for (auto& name : names)
    {
        std::cout << name << "\n";
    }
}

int main()
{

    /*
        ╔═══════════════════════════════╗
        ║Parameters: optional parameters║
        ╚═══════════════════════════════╝
        https://www.geeksforgeeks.org/default-arguments-c/

        Unless specified, parameters to a method are required.
        However, you can make parameters optional, meaning when calling the method, you aren't required to pass values for the optional parameters.

        REQUIREMENT:
            - all optional parameters have to be at the end of the list of parameters
            - in the list of parameters, assign a value to any parameter you want to be optional
    */
    std::string file = "highScores";

    std::string postfile = postFix(file); //if you don't pass a value, the default value will be used for the optional parameter
    std::cout << postfile << "\n";

    postfile = postFix(file, 5); //if a value is passed, it will be used for the optional parameter
    std::cout << postfile << "\n";



    /*
        CHALLENGE 1:

            Write a method called batTheme.
            Add an optional parameter to determine how many "na" are printed. The default value should be 13.
            
            If the calling code does not pass a value for the parameter, 
                print "na na na na na na na na na na na na na Batman".
            If a value is passed, print the number of "na" equal to the value.
            EX: if 6 is passed, print "na na na na na na Batman"

    */

    ThemeSong::BatTheme();
    ThemeSong::BatTheme(25);





    /*
        ╔═══════════╗
        ║ vector<T> ║
        ╚═══════════╝

        [  copying a vector  ]
        https://www.geeksforgeeks.org/ways-copy-vector-c/

        here are 3 ways to copy a vector:
        1) copy each element manually
        2) assignment "=" operator
        3) passing a vector to the constructor of another vector

    */
    std::vector<int> scores = { 1,2,3,4,5 };

    //1) copy each element manually
    std::vector<int> scores2;
    for (size_t i = 0; i < scores.size(); i++)
        scores2.push_back(scores[i]);

    //2) assignment "=" operator
    std::vector<int> scores3 = scores;//makes a copy

    //3) passing a vector to the constructor of another vector
    std::vector<int> scores4(scores);




    /*
        CHALLENGE 2:

            Copy the JLA vector and add some villains to the new vector. 
            Don't modify the original JLA vector.
    */
    std::vector<std::string> JLA = { "Batman", "Wonder Woman", "Superman", "Flash" };
    std::vector<std::string> DC = JLA;
    DC.push_back("The Joker");
    DC.push_back("Lex Luthor");
    DC.push_back("Bizzaro");
    DC.push_back("Bane");
    DC.push_back("Killer Croc");
    Print(JLA);
    Print(DC);
}