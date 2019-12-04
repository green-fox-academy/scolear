#include "saturation.h"

cv::Mat create_saturated(const cv::Mat& original, double alpha, int beta)
{
    cv::Mat new_image = cv::Mat::zeros(original.size(), original.type());

    /*
    for( int y = 0; y < original.rows; y++ ) {
        for( int x = 0; x < original.cols; x++ ) {
            for( int c = 0; c < original.channels(); c++ ) {
                new_image.at<cv::Vec3b>(y,x)[c] =
                        cv::saturate_cast<uchar>( alpha*original.at<cv::Vec3b>(y,x)[c] + beta );
            }
        }
    }
    */

    original.convertTo(new_image, -1, alpha, beta);
    return new_image;
}
