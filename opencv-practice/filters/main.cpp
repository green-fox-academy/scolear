#include <iostream>
#include <opencv2/opencv.hpp>
#include <QtWidgets/qmessagebox.h>

int threshold_value = 0;
int threshold_type = 3;
int const max_value = 255;
int const max_type = 4;
int const max_binary_value = 255;

const char* trackbar_type = "Type: \n 0: Binary \n 1: Binary Inverted \n 2: Truncate \n 3: To Zero \n 4: To Zero Inverted";
const char* trackbar_value = "Value";

typedef struct userData {
    cv::Mat src;
    cv::Mat dst;
    const char* window_name;
} user_data_t, *user_data_p;

static void Threshold_Demo( int, void* userData)
{
    /* 0: Binary
     1: Binary Inverted
     2: Threshold Truncated
     3: Threshold to Zero
     4: Threshold to Zero Inverted
    */

    cv::Mat src = ((user_data_p)userData)->src;
    cv::Mat dst = ((user_data_p)userData)->dst;
    const char* window_name = ((user_data_p)userData)->window_name;

    threshold(src, dst, threshold_value, max_binary_value, threshold_type);
    imshow(window_name, dst);
}

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

    cv::namedWindow("Original", cv::WINDOW_AUTOSIZE);
    cv::imshow("Original", src);

    user_data_t userData = {src, dst, "2D Filter Tests"};

    cv::createTrackbar( trackbar_type,
                    "2D Filter Tests", &threshold_type,
                    max_type, Threshold_Demo, &userData );
    cv::createTrackbar( trackbar_value,
                    "2D Filter Tests", &threshold_value,
                    max_value, Threshold_Demo, &userData );
    Threshold_Demo( 0, &userData);

    QMessageBox mBox(QMessageBox::Icon::Question, "Hallod", "Adjal mar egy cigit!", QMessageBox::StandardButton::Ok | QMessageBox::StandardButton::Ignore);
    mBox.show();

    cv::waitKey();

    return 0;
}
