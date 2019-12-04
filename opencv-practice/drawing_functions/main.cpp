#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include "color_definitions.h"

#define SIZE 500
#define BACKGROUND_COLOR cv::Scalar(0, 0, 0)

void MyEllipse(cv::Mat img, double angle, const cv::Scalar& color);
void MyFilledCircle(cv::Mat img, cv::Point center, const cv::Scalar& color);
void MyLine(cv::Mat img, cv::Point start, cv::Point end, const cv::Scalar& color);

int main() {

    cv::Mat image(SIZE, SIZE, CV_8UC3, BACKGROUND_COLOR);

    for (int j = 0; j < SIZE; j += 20) {
        MyLine(image, cv::Point(j,0), cv::Point(j, SIZE), cv::Scalar(255, 255, 255));
    }

    for (int i = 0; i < 180; i += 10) {
        MyEllipse(image, i, RED);
    }

    MyFilledCircle(image, cv::Point(SIZE/2, SIZE/2), BLACK);

    cv::putText(image, "Enter the Void", cv::Point(0, SIZE), 2, 2, WHITE, 5);

    cv::namedWindow("Display", cv::WINDOW_AUTOSIZE);
    cv::imshow("Display", image);

    cv::waitKey();

    return 0;
}

void MyEllipse(cv::Mat img, double angle, const cv::Scalar& color)
{
    int thickness = 2;
    int lineType = 8;

    cv::ellipse(img,
            cv::Point(SIZE/2, SIZE/2),
            cv::Size(SIZE/3, SIZE/12),
            angle,
            0,
            360,
            color,
            thickness,
            lineType);
}

void MyFilledCircle(cv::Mat img, cv::Point center, const cv::Scalar& color)
{
    cv::circle(img,
               center,
               SIZE/19,
               color,
               cv::FILLED,
               cv::LINE_8);
}

void MyLine(cv::Mat img, cv::Point start, cv::Point end, const cv::Scalar& color)
{
    int thickness = 2;
    int lineType = cv::LINE_8;

    line( img,
          start,
          end,
          color,
          thickness,
          lineType );
}