#include <iostream>
#include <opencv2/opencv.hpp>
#include <ctime>
#include <string>

int main() {

    cv::VideoCapture cap(0);

    if(!cap.isOpened()){
        std::cout << "Error opening video stream or file" << std::endl;
        return -1;
    }

    cv::Ptr<cv::BackgroundSubtractor> pBackSub;
    pBackSub = cv::createBackgroundSubtractorKNN();

    cv::Mat frame, fgMask;

    while (1) {
        cap >> frame;
        if (frame.empty()) break;

        pBackSub->apply(frame, fgMask, 0.01);

        imshow("Frame", frame);
        imshow("FG Mask", fgMask);

        int keyboard = cv::waitKey(30);
        if (keyboard == 'q' || keyboard == 27)
            break;
    }
    return 0;
}