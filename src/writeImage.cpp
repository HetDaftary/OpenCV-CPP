#include <iostream>
#include <cstdlib>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main() {
    cv::Mat img = cv::imread("data/input/images/lena.jpg");
    // If path where result file is stored does not exist, we make a new folder for the path.
    system("if [ ! -f data/Results/writeImage/ ]; then mkdir -p data/Results/writeImage/; fi");
    cv::imwrite("data/Results/writeImage/lena.jpg", img);
    return 0;
}