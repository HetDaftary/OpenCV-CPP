#include<iostream>
#include<opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void showImage(cv::Mat img, std::string nameOfWindow, int timeInMilliSeconds = 0) {
    cv::imshow(nameOfWindow, img);
    cv::waitKey(timeInMilliSeconds);
    cv::destroyWindow(nameOfWindow);
}

int main(int argc, char** argv){
    cv::Mat img;
    img = cv::imread("data/input/images/lena.jpg", cv::IMREAD_COLOR);
  
    if(!img.data){
        std::cout << "Image not found" << std::endl;
        return -1;
    }
  
    showImage(img, "Lena", 10000);
}