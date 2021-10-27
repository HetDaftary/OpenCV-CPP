#include<iostream>
#include<opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, char** argv){
    cv::Mat img;
    img = cv::imread("img/lena.jpg", cv::IMREAD_COLOR);
  
    if(!img.data){
        std::cout << "Image not found" << std::endl;
        return -1;
    }
  
    cv::imshow("Lena", img);
    cv::waitKey(10000);
    cv::destroyAllWindows();
}