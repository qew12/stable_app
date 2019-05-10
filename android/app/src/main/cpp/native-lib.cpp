#include <jni.h>
#include <opencv2/opencv.hpp>


void preprocess(cv::Mat& image){
    cvtColor(image, image, CV_BGR2GRAY);
    cv::threshold(image, image, 130, 255, cv::THRESH_BINARY);
}

extern "C" {

JNIEXPORT void JNICALL
Java_e_qew_cv9_MainActivity_IncreaseContrast(JNIEnv *, jobject, jlong addrRgba) {
    cv::Mat &src = *(cv::Mat *) addrRgba;
    preprocess(src);
}

}
