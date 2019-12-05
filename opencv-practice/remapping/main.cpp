#include <iostream>
#include <opencv2/opencv.hpp>

int main()
{
    cv::Mat src = cv::imread("../Edo-Tokyo.-Tokyo-Blade-Runner-style-nightscapes-Photo-by-Tom-Blachford.jpg");

    if (src.empty()) { std::cout << "Cannot read image: " << std::endl; return -1; }

    cv::Mat dst(src.size(), src.type());
    cv::Mat map_x(src.size(), CV_32FC1);
    cv::Mat map_y(src.size(), CV_32FC1);

    /// Turning it upside down:
    for (int i = 0; i < map_x.rows; ++i) {
        for (int j = 0; j < map_x.cols; ++j) {
            map_x.at<float>(i, j) = (float)j;
            map_y.at<float>(i, j) = (float)(map_x.rows - i);
        }
    }

    cv::remap(src, dst, map_x, map_y, cv::INTER_LINEAR, cv::BORDER_CONSTANT, cv::Scalar(0, 0, 0));

    cv::namedWindow("Original", cv::WINDOW_AUTOSIZE);
    cv::imshow("Original", src);

    cv::namedWindow("Remap test", cv::WINDOW_AUTOSIZE);
    cv::imshow("Remap test", dst);

    /// Histogram equalization:
    // Grayscaling:
    cv::cvtColor(src, src, cv::COLOR_BGR2GRAY);

    cv::namedWindow("Original Grayscale", cv::WINDOW_AUTOSIZE);
    cv::imshow("Original Grayscale", src);

    cv::equalizeHist(src, dst);

    cv::namedWindow("Equalized Histogram", cv::WINDOW_AUTOSIZE);
    cv::imshow("Equalized Histogram", dst);

    cv::waitKey();

    return 0;
}
