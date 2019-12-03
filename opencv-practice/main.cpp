#ifdef _WIN32
#define PATH "..\\..\\..\\"
#endif

#ifdef linux
#define PATH "../"
#endif

#include <iostream>
#include <opencv2/opencv.hpp>

int main()
{
    cv::Mat image;
    image = cv::imread(PATH "cyberpunk_room.jpg", 1);

    if ( !image.data )
    {
        printf("No image data \n");
        return -1;
    }

    cv::namedWindow("Display Image", cv::WINDOW_AUTOSIZE );
    cv::imshow("Display Image", image);
    cv::waitKey(0);
    return 0;
}
