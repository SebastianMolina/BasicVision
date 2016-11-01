//
// Created by Sebastian Molina on 8/5/16.
//

#ifndef BASICVISION_VISIONFILTERING_H
#define BASICVISION_VISIONFILTERING_H

#include <iostream>
#include <iomanip>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

struct filterImageInfo
{
    Mat frame;
    Mat mask;
    int passedTest;
};

filterImageInfo* filterImage(Scalar lowerRange, Scalar upperRange, filterImageInfo* info);

#endif //BASICVISION_VISIONFILTERING_H
