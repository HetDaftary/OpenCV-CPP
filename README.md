# OpenCV-CPP
Practicing OpenCV C++

## Installation

- [Guide for Windows](https://www.youtube.com/watch?v=m9HBM1m_EMU)
- [Guide for Linux](https://github.com/lvnlinh1812/Build_OpenCv_Cplusplus)

## General Info 

- Compiling C++ code with GNU/G++ on Linux.

        g++ test.cpp -o test -std=c++11 `pkg-config --cflags --libs`

- Namespace to be used to call OpenCV functions: <b>cv</b>.
- Ubuntu or a Debian based distro is recommended to use has Arch based distros tend to get some weird errors related to path.
- We are using a python file to compile and run the programs for convenience. 
- Way to compile and run with python program.

        python3 compileAndRun.py src/readAndShowImage.cpp
- We pass the cpp file path to python3 code as argv.
- <b>Note</b> that all the programs are tested from working directory and thus paths are written with respect to the working directory.

## Read Images

- Function to be used <b>imread</b>.
- Namespace: <b>cv</b>.
- 1: Coloured Image.
- 0: Gray scaled Image.
- There are many other modes which can be referred to by [Link](https://stackoverflow.com/questions/56063512/what-does-flag-1-in-imread-of-opencv-mean)
- [Code File](src/readAndShowImage.cpp)
<img src = "img/Screenshot 2021-10-28 at 15-43-46 what does flag -1 in imread of opencv mean.png">

## Show Image to user

- Function to be used: <b>imshow</b>
- You also need <b>cv::waitKey and cv::destroyAllWindows() or cv::destroyWindow</b> with this function.
- For example:

        void showImage(cv::Mat img, std::string nameOfWindow, int timeInMilliSeconds = 0) {
            cv::imshow(nameOfWindow, img);
            cv::waitKey(timeInMilliSeconds);
            cv::destroyWindow(nameOfWindow);
        }

- The default value is 0 which means that the window will not be automatically closed. You can consider it has infinite time.
- cv::destroyWindow only closes one window.
- cv::destroyAllWindows closes all the windows made by OpenCV.
- [Code File](src/readAndShowImage.cpp)

## Write an image file.

- Function to be used: <b>imwrite</b>.
- You need to pass fileName and image file(cv::Mat type file) to save the image.
- [Code File](src/writeImage.cpp)
