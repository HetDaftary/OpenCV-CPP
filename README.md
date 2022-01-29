# OpenCV-CPP
Learning OpenCV C++

## Installation

- [Guide for Windows](https://towardsdatascience.com/install-and-configure-opencv-4-2-0-in-windows-10-vc-d132c52063a1)
- Note that it is OpenCV Website -> Library -> Releases and not Resources -> Releases.
- It is either a typo on the website side or OpenCV changed it right now.
- For Linux: Just run [Install-OpenCV.sh](scripts/Install-OpenCV.sh)
- This script depends on opencv.pc file in the scripts folder.
- So prefer to go in the scripts folder and run it.
- The opencv.pc file should be in the same dir from where you are running.

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

## Write an image file

- Function to be used: <b>imwrite</b>.
- You need to pass fileName and image file(cv::Mat type file) to save the image.
- [Code File](src/writeImage.cpp)

## Load a video file

- Function to be use: Same as images.
- Type that handles videos: <b>cv::VideoCapture</b>
- You can use the following function to show a frame of the video


        bool showImageOfVideo(cv::Mat img, std::string nameOfWindow, int timeInMilliSeconds = 0) {
            cv::imshow(nameOfWindow, img);
            char toBreak = cv::waitKey(timeInMilliSeconds);
            if (toBreak == 'q' || toBreak == 'Q') return true;
            return false;
        }

- Here we use toBreak to store return value of waitKey to know which key was pressed.
- <b>cv::waitKey</b> listens to the keyboard and breaks and returns the first key pressed in the time.
- When user presses 'q' or 'Q'(i.e. q but when caps lock is on), we want to end the video playing.
- [Code File](src/loadVideo.cpp)

## Making a trackbar using OpenCV

- You need an action to change trackbar which is done with a function.
- The functions to be used: <b>cv::createTrackbar, cv::setTrackbarPos</b>
- Create Trackbar function:

        cv::createTrackbar("trackbar", "Window", NULL, frames, onTrackbarChange, NULL);

- Here onTrackbarChange is a function that program has to call when we change the value of trackbar with mouse.

        void onTrackbarChange(int pos, void*) {
            cap.set(cv::CAP_PROP_POS_FRAMES, pos);
            if (!dontset) {
                run = 1;
            }
            dontset = 0;
        }
- Function signature(arguments and return type) is important here.
- [Code File](src/trackbar.cpp)

## Blur in OpenCV 

There 3 main types of blur
- Normal blur: <b>cv::blur</b>
		
		cv::blur(img, dest, cv::Size(9, 9));

- Median blur: <b>cv::medianBlur</b>

		cv::medianBlur(img, dest, 9);

- Gaussian blur: <b>cv::GaussianBlur</b>

		cv::GaussianBlur(img, dest, cv::Size(9, 9), 0.0, 0.0, 4);

- Resize the image(Decrease the size): <b>cv::resize</b>

		cv::resize(img, dest, img.size(), 0.75, 0.75, cv::INTER_CUBIC);

- [Code File](src/blurImages.cpp)
