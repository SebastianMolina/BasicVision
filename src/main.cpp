#include <iostream>
#include <opencv2/opencv.hpp>
#include <NinjaFinder.h>
#include <CamTracker.h>
#include "VisionFiltering.h"
#include "Print2Text.h"
using namespace std;
using namespace cv;

int main() {
    filterImageInfo* info;
    int lower;

    //Blue Threshold
    findColor(Scalar(102, 46, 32), Scalar(151, 255, 255), info);

    //findNinjas(info, lower);
    //findBuoys(info, lower);
}