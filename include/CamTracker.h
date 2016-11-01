//
// Created by Sebastian Molina on 10/28/16.
//

#ifndef BASICVISION_CAMTRACKER_H
#define BASICVISION_CAMTRACKER_H

#include <iostream>
#include <iomanip>
#include <opencv2/opencv.hpp>
#include "VisionFiltering.h"

using namespace cv;
using namespace std;

int findColor(Scalar lower, Scalar upper, filterImageInfo* info);

#endif //BASICVISION_CAMTRACKER_H
