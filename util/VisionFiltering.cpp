//
// Created by Sebastian Molina on 8/5/16.
//

#include "VisionFiltering.h";

filterImageInfo* filterImage(Scalar lowerRange, Scalar upperRange, filterImageInfo* info)
{
    Scalar lineColor = Scalar(0, 255, 0);

    int x;
    int y;
    int w;
    int h;

    Mat hsv;
    cvtColor(info->frame.clone(), hsv, COLOR_BGR2HSV);

    Mat mask;
    inRange(hsv, lowerRange, upperRange, mask);
    info->mask = mask;

    vector<vector<Point>> contours;
    findContours(mask.clone(), contours, RETR_TREE, CHAIN_APPROX_TC89_KCOS, Point(0, 0));

    info->passedTest = 0;

    for(int i = 0; i < contours.size(); i++)
    {
        Rect rect = boundingRect(contours[i]);
        x = rect.x;
        y = rect.y;
        w = rect.width;
        h = rect.height;

        //ninja switch min to 50 buoy switch to 15
        if (rect.width < 1000 && rect.width > 400 && rect.height < 1000 && rect.height > 400)
        {
            Point pt1 = Point(x, y);
            Point pt2 = Point(x + w, y + h);
            rectangle(info->frame, pt1, pt2, lineColor, 4);
            info->passedTest = 1;
            //cout << "found Ninja at: " << upperRange << lowerRange << "\n";
        }
    }
    return info;
}
