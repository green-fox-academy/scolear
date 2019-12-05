#include "demosaicing.h"

cv::Mat demosaicing_nearest(const cv::Mat& image)
{
    int rows = image.rows;
    int columns = image.cols;
    int n_channels = image.channels();

    std::vector<cv::Mat> channels(n_channels);

    cv::Mat red, green, blue, dst;

    cv::split(image, channels);

    blue = channels[0].clone();
    green = channels[1].clone();
    red = channels[2].clone();

    for (int i = 1; i < rows - 1; ++i)
    {
        for (int j = 1; j < columns - 1; ++j)
        {
            if (channels[0].at<uchar>(i, j) == 0) {
                RED_BLUE_handler(channels, blue, 0, i, j);
            }

            if (channels[1].at<uchar>(i, j) == 0) {
                GREEN_handler(channels, green, i, j);
            }

            if (channels[2].at<uchar>(i, j) == 0) {
                RED_BLUE_handler(channels, red, 2, i, j);
            }
        }
    }

    std::vector<cv::Mat> result = {blue, green, red};
    cv::merge(result, dst);
    return dst;
}

void RED_BLUE_handler(const std::vector<cv::Mat> &channels, cv::Mat &result, int flag, int i, int j)
{
    if (channels[flag].at<uchar>(i, j + 1) != 0) {
        // blue row
        result.at<uchar>(i, j) = (channels[flag].at<uchar>(i, j - 1) + channels[flag].at<uchar>(i, j + 1)) / 2;
    } else if (channels[flag].at<uchar>(i - 1, j) != 0) {
        // non-blue row, under blue
        result.at<uchar>(i, j) = (channels[flag].at<uchar>(i - 1, j) + channels[flag].at<uchar>(i + 1, j)) / 2;
    } else {
        // non-blue row, in-between
        result.at<uchar>(i, j) = (channels[flag].at<uchar>(i - 1, j - 1) + channels[flag].at<uchar>(i - 1, j + 1) + channels[flag].at<uchar>(i + 1, j - 1) + channels[flag].at<uchar>(i + 1, j + 1)) / 4;
    }
}

void GREEN_handler(const std::vector<cv::Mat> &channels, cv::Mat &result, int i, int j)
{
    result.at<uchar>(i, j) = (channels[1].at<uchar>(i, j - 1) + channels[1].at<uchar>(i, j + 1) + channels[1].at<uchar>(i - 1, j) + channels[1].at<uchar>(i + 1, j)) / 4;
}