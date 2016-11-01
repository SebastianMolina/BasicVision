//
// Created by Sebastian Molina on 10/28/16.
//

#ifndef BASICVISION_NINJAFINDER_H
#define BASICVISION_NINJAFINDER_H

#include <iostream>
#include <iomanip>
#include <opencv2/opencv.hpp>
#include "VisionFiltering.h"

using namespace cv;
using namespace std;

int findNinjas(filterImageInfo* info, int lower);

#endif //BASICVISION_NINJAFINDER_H
