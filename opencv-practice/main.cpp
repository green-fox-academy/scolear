#ifdef _WIN32
#define PATH "..\\..\\..\\"
#endif

#ifdef linux
#define PATH "../"
#endif

#include <iostream>
#include <opencv2/opencv.hpp>
#include "saturation.h"


int main()
{
    cv::Mat image;
    image = cv::imread(PATH "smallfern.jpg", 1);

    cv::Mat image2;
    image2 = cv::imread(PATH "minearl2.jpg", 1);

    if (!image.data) {printf("No image data \n"); return -1;}
    if (!image2.data) {printf("No image2 data \n"); return -1;}

    double alpha = 5.0;
    int beta = 20;

    cv::namedWindow("Original", cv::WINDOW_AUTOSIZE);
    cv::imshow("Original", image);

    cv::namedWindow("Saturated", cv::WINDOW_AUTOSIZE);
    cv::imshow("Saturated", create_saturated(image, alpha, beta));

    cv::Mat blend;
    cv::addWeighted(image, 0.5, image2, 0.5, 0.0, blend);
    cv::namedWindow("Blended", cv::WINDOW_AUTOSIZE);
    cv::imshow("Blended", blend);

    cv::waitKey(0);

    return 0;
}
