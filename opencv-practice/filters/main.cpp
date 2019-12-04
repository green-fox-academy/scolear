#include <iostream>
#include <opencv2/opencv.hpp>

int main() {

    cv::Mat src = cv::imread("../Edo-Tokyo.-Tokyo-Blade-Runner-style-nightscapes-Photo-by-Tom-Blachford.jpg", 1);
    cv::Mat dst;


    cv::Point anchor = cv::Point(-1, -1);
    double delta = 0;
    int ddepth = -1;
    int kernel_size = 3;

    // cv::Mat kernel = cv::Mat::ones(kernel_size, kernel_size, CV_32F) / (float)(kernel_size * kernel_size);

    float kernel_layout[] = {0.2, 1.1, -0.4, 0.2, -0.3, 0.5, 1.9, -2, 0.1};
    cv::Mat kernel(kernel_size, kernel_size, CV_32F, kernel_layout);

    std::cout << kernel << std::endl;

    cv::filter2D(src, dst, ddepth, kernel, anchor, delta, cv::BORDER_DEFAULT);

    cv::namedWindow("2D Filter Tests", cv::WINDOW_AUTOSIZE);
    cv::imshow("2D Filter Tests", dst);

    cv::namedWindow("Original", cv::WINDOW_AUTOSIZE);
    cv::imshow("Original", src);
    cv::waitKey();

    return 0;
}
