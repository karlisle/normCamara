#ifndef CALIBRAR_H
#define CALIBRAR_H

#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/calib3d/calib3d.hpp>

#include <opencv2/videoio/videoio.hpp>
#include <iostream>

using namespace std;

class Calibrar
{
public:
    Calibrar(){
    }
    void menu();

private:
    void video(int opt);

    void calibcam(cv::Mat frame);

    vector<int> faces(cv::Mat frame);
    vector<cv::Point3f> Create3DChessboardCorners(cv::Size boardSize, float squareSize);

};

#endif // CALIBRAR_H
