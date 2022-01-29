from sys import argv
from os import system

if __name__ == "__main__":
    '''
    echo $fileName
    
    ./build/$fileName.
    '''

    fileName = argv[1].split("/")[-1]
    fileNameWithoutExtension = fileName.split(".")[0]

    system("g++ {} -o \"build/{}.out\" --std=c++11 `pkg-config --cflags --libs opencv`".format(argv[1], fileNameWithoutExtension))

    system("./build/{}.out".format(fileName))