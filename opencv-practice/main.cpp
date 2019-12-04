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
    image = cv::imread(PATH "cyberpunk_room.jpg", 1);

    if (!image.data)
    {
        printf("No image data \n");
        return -1;
    }

    double alpha = 5.0;
    int beta = 20;

    cv::namedWindow("Original", cv::WINDOW_AUTOSIZE);
    cv::imshow("Original", image);

    cv::namedWindow("Saturated", cv::WINDOW_AUTOSIZE);
    cv::imshow("Saturated", create_saturated(image, alpha, beta));
    cv::waitKey(0);

    return 0;
}
