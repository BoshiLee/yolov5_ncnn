//
// Created by snick on 2022/11/23.
//

#ifndef YOLOV5_CPLUS_YOLOV5UTILS_H
#define YOLOV5_CPLUS_YOLOV5UTILS_H

#include <opencv2/opencv.hpp>
#include <net.h>
struct Object
{
    cv::Rect_<float> rect;
    int label;
    float prob;
};
#define MAX_STRIDE 64

class YoloV5Utils {
public:


    inline float intersection_area(const Object& a, const Object& b);
    void qsort_descent_inplace(std::vector<Object>& faceobjects, int left, int right);
    void qsort_descent_inplace(std::vector<Object>& faceobjects);
    void nms_sorted_bboxes(const std::vector<Object>& faceobjects, std::vector<int>& picked, float nms_threshold, bool agnostic = false);
    inline float sigmoid(float x);
    void generate_proposals(const ncnn::Mat& anchors, int stride, const ncnn::Mat& in_pad, const ncnn::Mat& feat_blob, float prob_threshold, std::vector<Object>& objects);
    int detect_yolov5(cv::Mat& bgr, std::vector<Object>& objects);
    void draw_objects(cv::Mat& bgr, std::vector<Object>& objects, const cv::String& outpath);
};


#endif //YOLOV5_CPLUS_YOLOV5UTILS_H
