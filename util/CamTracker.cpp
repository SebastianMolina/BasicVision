//
// Created by Sebastian Molina on 10/28/16.
//

#include "VisionFiltering.h";

VideoCapture cap(0);
Mat frame;

int findColor(Scalar lower, Scalar upper, filterImageInfo* info)
{
    while(1)
    {
        info = new filterImageInfo;
        cap >> frame;
        info->frame = frame.clone();
        info = filterImage(lower, upper, info);
        imshow("Camera", info->frame);
        delete info;
    }
}



