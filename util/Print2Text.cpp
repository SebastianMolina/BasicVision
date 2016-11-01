//
// Created by Sebastian Molina on 10/14/16.
//

#include "Print2Text.h"

ofstream myFile;

int openFile(string fileName)
{
    myFile.open("/Users/SebastianMolina/Desktop/" + fileName, ios::app);
}

int closeFile()
{
    myFile.close();
}

int write2File(int id, int val1, int val2, int val3)
{
    //srand(time(NULL));
    //id = rand() % 20;
    myFile << id << " " <<val1 << " " << val2 << " " <<val3 << "\n";
}

int string2File(string text)
{
    myFile << text << "\n";
}

int int2File(int num)
{
    myFile << num << "\n";
}

