#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

cv::VideoCapture cap;
int run = 1, dontset = 0;

void onTrackbarChange(int pos, void* temp) {
    cap.set(cv::CAP_PROP_POS_FRAMES, pos);
    if (!dontset) {
        run = 1;
    }
    dontset = 0;
}

int main() {
    Mat frame;
    char returnOfWaitKey, temp;

    cap.open("data/input/videos/videoplayback.mp4");

    int frames = (int)cap.get(cv::CAP_PROP_FRAME_COUNT);
    int height = (int)cap.get(cv::CAP_PROP_FRAME_HEIGHT);
    int width = (int)cap.get(cv::CAP_PROP_FRAME_WIDTH);

    // NOTE: Window needs to be created before trackbar in order to see trackbar on Window.
    namedWindow("Window", cv::WINDOW_AUTOSIZE);

    // Some tutorials use an int value to pass has third argument but it is decrepated now.
    // It is better to use NULL at third argument.
    cv::createTrackbar("trackbar", "Window", NULL, frames, onTrackbarChange, NULL);

    while (true) {
        if (run) {
            cap >> frame;
            if (frame.empty()) {
                break;
            }

            int currentPos = cap.get(cv::CAP_PROP_POS_FRAMES);
            dontset=1;
            cv::setTrackbarPos("trackbar", "Window", currentPos);

            cv::imshow("Window", frame);
            if (returnOfWaitKey != 'r' || returnOfWaitKey != 'R') {    
                run = 0;
            }
        }

        temp = (char) cv::waitKey(30);
        if  (temp > 0) {
            returnOfWaitKey = temp;
        }
        if (returnOfWaitKey == 'q' || returnOfWaitKey == 'Q') {
            break;
        } else if (returnOfWaitKey == 's' || returnOfWaitKey == 'S') {
            run = 0;
        } else if (returnOfWaitKey == 'r' || returnOfWaitKey == 'R') {
            run = 1;
        }
    }

    cv::destroyWindow("Window");

    return 0;
}