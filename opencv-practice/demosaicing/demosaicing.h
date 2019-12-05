#ifndef DEMOSAICING_DEMOSAICING_H
#define DEMOSAICING_DEMOSAICING_H

#include <opencv2/opencv.hpp>
#include <cstdlib>

cv::Mat demosaicing_nearest(const cv::Mat& image);
void RED_BLUE_handler(const std::vector<cv::Mat> &channels, cv::Mat &result, int flag, int i, int j);
void GREEN_handler(const std::vector<cv::Mat> &channels, cv::Mat &result, int i, int j);

#endif //DEMOSAICING_DEMOSAICING_H
