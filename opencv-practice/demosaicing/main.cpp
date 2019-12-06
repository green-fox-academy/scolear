#include <iostream>
#include <opencv2/opencv.hpp>
#include "demosaicing.h"


int main()
{
    cv::Mat src = cv::imread("../parrot-raw.png");
    cv::imshow("Parrot raw", src);

    auto start = std::chrono::steady_clock::now();

    cv::Mat res = demosaicing_nearest(src);

    auto finish = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start);

    std::cout << elapsed.count() << " ms" << std::endl;

    cv::imshow("Demosaiced nearest", res);

    cv::waitKey();
    return 0;
}
