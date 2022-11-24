#include "layer.h"
#include "net.h"
#include "src/h/YoloV5Utils.h"
#if defined(USE_NCNN_SIMPLEOCV)
#include "simpleocv.h"
#else
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#endif
#include <float.h>
#include <stdio.h>
#include <vector>

#include <iostream>
using namespace std;

#include<opencv2/opencv.hpp>
using namespace cv;

int main(int argc, char** argv )
{
    const char* imagepath = argv[1];

    cv::Mat img = cv::imread(imagepath, 1);
    if (img.empty())
    {
        fprintf(stderr, "cv::imread %s failed\n", imagepath);
        return -1;
    }

    YoloV5Utils yolov5;

    int64 tic, toc;
    tic = cv::getTickCount();

    std::vector<Object> objects;
    yolov5.detect_yolov5(img, objects);

    toc = cv::getTickCount() - tic;
    double time = toc / double(cv::getTickFrequency());
    double fps = double(1.0) / time;

    cout << "Time:" << time << endl;
    cout << "FPS:" << fps << endl;
    yolov5.draw_objects(img, objects, "../result.jpeg");
    return 0;
}