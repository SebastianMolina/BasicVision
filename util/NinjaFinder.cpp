//
// Created by Sebastian Molina on 10/28/16.
//

#include "VisionFiltering.h"
#include "Print2Text.h"
#include "NinjaFinder.h"

int findNinjas(filterImageInfo* info, int lower)
{

    Mat frame = imread("/Users/SebastianMolina/Desktop/Ninja.png", CV_LOAD_IMAGE_COLOR);

    Scalar purpleNinjaLower = Scalar(134, 0, 0);
    Scalar purpleNinjaUpper = Scalar(180,255,255);

    Scalar blueNinjaLower = Scalar(97, 0, 0);
    Scalar blueNinjaUpper = Scalar(139, 255, 255);

    Scalar greenNinjaLower = Scalar(64, 37, 0);
    Scalar greenNinjaUpper = Scalar(95, 255, 255);

    vector<Scalar> purpleNinja = {purpleNinjaLower, purpleNinjaUpper};

    vector<Scalar> blueNinja = {blueNinjaLower, blueNinjaUpper};
    vector<Scalar> greenNinja = {greenNinjaLower, greenNinjaUpper};

    vector<vector<Scalar>> ninjas = {purpleNinja, blueNinja, greenNinja};

    openFile("NinjaFinder.txt");

    for(int ninja = 0; ninja < ninjas.size(); ninja++)
    {
        lower = ninjas[ninja][0][0];
        for (int hue = ninjas[ninja][1][0]; hue >= lower; hue -= 5)
        {
            info = new filterImageInfo;
            info->frame = frame.clone();
            ninjas[ninja][0][0] = hue;
            info = filterImage(ninjas[ninja][0], ninjas[ninja][1], info);
            if(info->passedTest){cout << hue << ", " << lower << "\n"; write2File(ninja, ninjas[ninja][0][0], ninjas[ninja][0][1], ninjas[ninja][0][2]);}
            imshow("Image after Filtering", info->frame);
            imshow("Image Mask", info->mask);
            if (waitKey(20) > 0) break;
            delete (info);
            sleep(.5);
        }
        cout << "Buoy: " << ninja << "\n";
        if(ninja == 2)
        {
            closeFile();
        }
    }

}
