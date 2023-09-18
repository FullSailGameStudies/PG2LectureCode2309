﻿// Day10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>



/*
    ╔══════════╗
    ║ File I/O ║
    ╚══════════╝

    3 things are required for File I/O:
    1) Open the file
    2) read/write to the file
    3) close the file



*/
int main()
{
    std::cout << "Hello PG2!\n";

    std::string fileName = "pg2_2309.csv";
    std::string filePath = "C:\\temp\\2309\\";

    /*

        ╔════════════════╗
        ║ write csv data ║
        ╚════════════════╝

        [  Open the file  ]
        [  Write to the file  ]
        [  Close the file  ]

        you need the path to the file
            use full path ( drive + directories + filename )
            or use relative path ( directories + filename )
            or current directory ( filename )

        Make sure to separate the data in the file with a delimiter.
        The delimiter is important because it is used
            to separate the data when reading the file back in.


        Lecture code: set a filePath variable, open an output file, write some csv data to it
    */

    std::string fullPath = filePath + fileName;


    {
        //creates the file at the full path location
        //  IF the file already exists, it will overwrite it
        std::ofstream outputFile(fullPath);
        if (outputFile.is_open())
        {
            char delimiter = '|';
            outputFile << 13 << delimiter << "Batman!" << delimiter << true << delimiter << 13.7 << delimiter << 420;
            outputFile.close();
        }
        else
            std::cout << "The file (" << fullPath << ") was not opened.\n";
    }//the file is closed when the variable goes out of scope\

    {
        std::ifstream inputFile(fullPath);
        if (inputFile.is_open())
        {
            std::string line;
            std::getline(inputFile, line);
            std::cout << line << "\n";
        }
        else
            std::cout << "The file (" << fullPath << ") was not opened.\n";
    }


    /*

        ╔═══════════════╗
        ║ read csv data ║
        ╚═══════════════╝

        [  Open the file  ]
        [  read the file  ]
        [  Close the file  ]

        Lecture code: using the filePath variable, open an input file, use getline to read a line, print the line
    */


    /*

        ╔═════════════════════╗
        ║ parsing csv strings ║
        ╚═════════════════════╝
        
        use getline on a string stream instead of a file stream

        Lecture code: 
            using the line read in above, use a stringstream to split the line using getline.
            store the separate items in a vector
            parse each item in the vector to an appropriate variable.
        

    */





    /*

        CHALLENGE:

        Parse the multi csv string (below) to get the data.
        NOTE: the data is a collection of object data.
        There are multiple delimiters.
        Separate on the first delimiter (collectionSeparator) to get the csv data for each object.
        Then, separate the object csv data on objectSeparator to get the details of the object.

        EX: hero#hero#hero   each hero is separated by a #
            name^secret^age  the details of each hero is separated by a ^

    */
    std::string multi = "Batman^Bruce Wayne^35#Superman^Clark Kent^25#Wonder Woman^Diana Prince^25#Aquaman^Arthur Curry^12";
    char collectionSeparator = '#';
    char objectSeparator = '^';
}