//
// Created by Sebastian Molina on 10/14/16.
//

#ifndef BASICVISION_PRINT2TEXT_H
#define BASICVISION_PRINT2TEXT_H

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

int openFile(string fileName);
int closeFile();
int write2File(int id, int val1, int val2, int val3);
int string2File(string text);
int int2File(int num);
#endif //BASICVISION_PRINT2TEXT_H
