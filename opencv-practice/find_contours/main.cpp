#include <iostream>
#include <cstdio>
#include <ctime>
#include <string>
#include <opencv2/opencv.hpp>

cv::Mat src_gray;
cv::Mat frame_gray;
int thresh = 100;
cv::RNG rng(12345);
time_t rawtime;
struct tm * timeinfo;

void thresh_callback(int, void* );
void thresh_callback_video(int, void* );

int main()
{
    cv::Mat src = cv::imread("../Edo-Tokyo.-Tokyo-Blade-Runner-style-nightscapes-Photo-by-Tom-Blachford.jpg", 1);

    cv::VideoCapture cap(0);

    if(!cap.isOpened()){
        std::cout << "Error opening video stream or file" << std::endl;
        return -1;
    }

    cv::cvtColor(src, src_gray, cv::COLOR_BGR2GRAY);
    cv::blur(src_gray, src_gray, cv::Size(3,3));

    cv::namedWindow("Frame", cv::WINDOW_AUTOSIZE);
    cv::namedWindow("Contours", cv::WINDOW_AUTOSIZE);

    cv::imshow("Contours", src);

    const int max_thresh = 255;
    cv::createTrackbar("Canny thresh:", "Contours", &thresh, max_thresh, thresh_callback);
    thresh_callback(0, 0);

    cv::createTrackbar("Canny thresh:", "Frame", &thresh, max_thresh, thresh_callback);

    while(1) {

        cv::Mat frame;
        // Capture frame-by-frame
        cap >> frame;

        // If the frame is empty, break immediately
        if (frame.empty())
            break;

        cv::cvtColor(frame, frame_gray, cv::COLOR_BGR2GRAY);
        cv::blur(frame_gray, frame_gray, cv::Size(3,3));

        // Display the resulting frame
        imshow( "Frame", frame );
        thresh_callback_video(0, 0);

        // Press  ESC on keyboard to exit
        char c = (char)cv::waitKey(25);
        if (c == 27) break;
    }

    // When everything done, release the video capture object
    cap.release();

    // Closes all the frames
    cv::destroyAllWindows();

    cv::waitKey();

    return 0;
}

void thresh_callback(int, void* )
{
    cv::Mat canny_output;
    cv::Canny(src_gray, canny_output, thresh, thresh*2);

    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i> hierarchy;

    cv::findContours(canny_output, contours, hierarchy, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);
    cv::Mat drawing = cv::Mat::zeros(canny_output.size(), CV_8UC3);

    for( size_t i = 0; i< contours.size(); i++) {
        cv::Scalar color = cv::Scalar(rng.uniform(0, 256), rng.uniform(0,256), rng.uniform(0,256));
        drawContours( drawing, contours, (int)i, color, 2, cv::LINE_8, hierarchy, 0 );
    }

    imshow( "Contours", drawing );
}

void thresh_callback_video(int, void* )
{
    cv::Mat canny_output;
    cv::Canny(frame_gray, canny_output, thresh, thresh*2);

    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i> hierarchy;

    cv::findContours(canny_output, contours, hierarchy, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);
    cv::Mat drawing = cv::Mat::zeros(canny_output.size(), CV_8UC3);

    for( size_t i = 0; i< contours.size(); i++) {
        cv::Scalar color = cv::Scalar(rng.uniform(0, 256), rng.uniform(0,256), rng.uniform(0,256));
        drawContours( drawing, contours, (int)i, color, 2, cv::LINE_8, hierarchy, 0 );
    }

    imshow( "Frame", drawing );

    char c = (char)cv::waitKey(25);
    if (c == 32) {
        time(&rawtime);
        timeinfo = localtime(&rawtime);
        cv::imwrite((std::string)"../screencap" + asctime(timeinfo) + ".jpg", drawing);
    }
}