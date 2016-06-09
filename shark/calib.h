#ifndef CALIB_H
#define CALIB_H

#include <iostream>


#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/videoio/videoio.hpp>

class Calibrar
{
public:
    Calibrar(){
    }
    //-- Menu
    void menu();
    void calibcam();

private:
    void video(int opt);
    std::vector<cv::Point3f> Create3DChessboardCorners(cv::Size boardSize, float squareSize);

};



#endif // CALIB_H
