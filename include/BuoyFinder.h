//
// Created by Sebastian Molina on 10/28/16.
//

#ifndef BASICVISION_BUOYFINDER_H
#define BASICVISION_BUOYFINDER_H

#include <iostream>
#include <iomanip>
#include <opencv2/opencv.hpp>
#include "VisionFiltering.h"

using namespace cv;
using namespace std;

int findBuoys(filterImageInfo* info, int lower);

#endif //BASICVISION_BUOYFINDER_H
