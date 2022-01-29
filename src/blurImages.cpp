#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void showImage(cv::Mat img, std::string nameOfWindow, int timeInMilliSeconds = 0) {
    cv::imshow(nameOfWindow, img);
    cv::waitKey(timeInMilliSeconds);
    cv::destroyWindow(nameOfWindow);
}

int main() {
    cv::Mat img = cv::imread("data/input/images/lena.jpg");
    cv::Mat dest;
    // Reading the image

    // If path for the result, does not exist, we make it.
    const char* resultPath = "data/Results/BlurImages";
    char* pathChecker = new char[150];
    sprintf(pathChecker, "if [ ! -f %s ] ; then mkdir %s; fi", resultPath, resultPath);
    system(pathChecker);

    // Using threading because I want all the images at the same time.
    showImage(img, "Raw Image", 10000);
    char* rawImagePath = new char[100];
    sprintf(rawImagePath, "%s/RawImage.jpg", resultPath);
    cv::imwrite(rawImagePath, img); 

    cv::blur(img, dest, cv::Size(9, 9));

    showImage(dest, "Normal Blur", 10000);
    char* normalBlurPath = new char[100];
    sprintf(normalBlurPath, "%s/NormalBlurImage.jpg", resultPath);
    cv::imwrite(normalBlurPath, dest);

    cv::medianBlur(img, dest, 9);

    showImage(dest, "Median Blur", 10000);
    char* meidanBlurPath = new char[100];
    sprintf(meidanBlurPath, "%s/MeidanBlur.jpg", resultPath);
    cv::imwrite(meidanBlurPath, dest);

    cv::GaussianBlur(img, dest, cv::Size(9, 9), 0, 0, 4);
    
    showImage(dest, "Gaussian Blur", 10000);
    char* gaussianBlurPath = new char[100];
    sprintf(gaussianBlurPath, "%s/GaussianBlur.jpg", resultPath);
    cv::imwrite(gaussianBlurPath, dest);

    cv::resize(img, dest, img.size(), 0.75, 0.75, cv::INTER_CUBIC);
    
    showImage(dest, "Resized Image", 10000);
    char* resizedImagePath = new char[100];
    sprintf(resizedImagePath, "%s/ResizedImage.jpg", resultPath);
    cv::imwrite(resizedImagePath, dest);

    return 0;
}