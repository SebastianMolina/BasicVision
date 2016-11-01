//
// Created by Sebastian Molina on 10/28/16.
//

#include "Print2Text.h"
#include "VisionFiltering.h"
#include "BuoyFinder.h"

int findBuoys(filterImageInfo* info, int lower)
{

    Mat frame = imread("/Users/SebastianMolina/Desktop/buoys3.png", CV_LOAD_IMAGE_COLOR);

    Scalar greenBuoyLower = Scalar(62, 0, 190);
    Scalar greenBuoyUpper = Scalar(180, 255, 255);

    Scalar yellowBuoyLower = Scalar(31, 0, 190);
    Scalar yellowBuoyUpper = Scalar(69, 255, 255);

    Scalar redBuoyLower = Scalar(0, 0, 190);
    Scalar redBuoyUpper = Scalar(67, 255, 255);

    vector<Scalar> greenBuoy = {greenBuoyLower, greenBuoyUpper};
    vector<Scalar> yellowBuoy = {yellowBuoyLower, yellowBuoyUpper};
    vector<Scalar> redBuoy = {redBuoyLower, redBuoyUpper};

    vector<vector<Scalar>> buoys = {greenBuoy, yellowBuoy, redBuoy};

    for(int buoy = 0; buoy < buoys.size(); buoy++)
    {
        lower = buoys[buoy][0][0];
        for (int hue = buoys[buoy][1][0]; hue >= lower; hue -= 5)
        {
            info = new filterImageInfo;
            info->frame = frame.clone();
            buoys[buoy][0][0] = hue;
            info = filterImage(buoys[buoy][0], buoys[buoy][1], info);
            if(info->passedTest){cout << hue << ", " << lower << "\n"; write2File(buoy, buoys[buoy][0][0], buoys[buoy][0][1], buoys[buoy][0][2]);}
            imshow("Image after Filtering", info->frame);
            imshow("Image Mask", info->mask);
            if (waitKey(20) > 0) break;
            delete (info);
            sleep(.5);
        }
        cout << "Buoy: " << buoy << "\n";
        if(buoy == 2)
        {
            closeFile();
        }
    }

    openFile("TestText1.txt");
}
