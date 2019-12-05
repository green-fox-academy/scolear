#include <iostream>
#include <opencv2/opencv.hpp>
#include "demosaicing.h"


int main()
{
    cv::Mat src = cv::imread("../parrot-raw.png");
    cv::imshow("Parrot raw", src);

    cv::Mat res = demosaicing_nearest(src);

    cv::imshow("Demosaiced nearest", res);

    cv::waitKey();
    return 0;
}
