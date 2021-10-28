#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

bool showImageOfVideo(cv::Mat img, std::string nameOfWindow, int timeInMilliSeconds = 0) {
    cv::imshow(nameOfWindow, img);
    char toBreak = cv::waitKey(timeInMilliSeconds);
    if (toBreak == 'q' || toBreak == 'Q') return true;
    return false;
}

int main() {
    cv::VideoCapture cap;
    cap.open("data/input/videos/videoplayback.mp4");

    cv::Mat frame;

    while (true) {
        cap >> frame;
        if (frame.empty() || showImageOfVideo(frame, "Video", 30)) {
            break;
        }
    }

    cv::destroyWindow("Video");

    return 0;
}