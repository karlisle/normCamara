#include "calibrar.h"
#include <stdio.h>


void Calibrar::menu()
{
    cout << "\t*****************************" << endl;
    cout << "\t*   Seleccione una opción   *" << endl;
    cout << "\t* 1) Normalizar             *" << endl;
    cout << "\t* 0) Salir             *" << endl;
    cout << "\t****************************" << endl;
    cout << "\t>>> ";


    int opcion;
    cin >> opcion;

    switch (opcion)
    {
    case 1:
        this->video(0);
        break;
    default:
        exit(0);
        break;
    }
}
void Calibrar::video(int opt)
{
    cout << "Inicalizando componentes...." << endl;

    cv::VideoCapture capture;
    capture.open(1);

    if (!capture.isOpened()) {
        cout << "Camera could not be loded..." << endl;
        this->menu();
    }

    cv::Mat orgFrame;
    int key = 0;
    /**********************************************************************************/
    while (1) {
        cv::Mat frame;
        cv::Mat cpFrame;
        capture.read(frame);
        //cpFrame = frame.clone();
        /**********************************************************************************/
        if (frame.rows == 0 || frame.cols == 0)
        {
            cout << "ERROR: No frame data" << endl;
            this->menu();
        }
        this->calibcam(frame);
        //cv::imshow("Frame", frame);
        /**********************************************************************************/
        char k = cv::waitKey(1);
        if (k == 'r')
            {
                cout << "regresando al menu principal" << endl;
                capture.release();
                cv::destroyAllWindows();
                this->menu();
             }
        /**********************************************************************************/
    }
    /**********************************************************************************/
}
/* El siguiente metodo hace una deteccion basica de rostros
*/

vector<int> Calibrar::faces(cv::Mat frame)
{
    string wName = "Frame";
    cv::namedWindow(wName, CV_WINDOW_AUTOSIZE);

    cv::Mat cpFrame = frame.clone();
    cv::Mat gFrame;
    cv::cvtColor(cpFrame, gFrame, CV_BGR2GRAY);
    cv::imshow(wName, gFrame);

    vector<int> faces;
    return faces;

}
/* La siguiente funcion se usara para calibrar la camara :)!
*/
void Calibrar::calibcam(cv::Mat frame)
{
    string wName = "Frame";
    cv::namedWindow(wName, CV_WINDOW_AUTOSIZE);

    cv::Mat cpFrame = frame.clone();
    cv::Mat gFrame;
    cv::cvtColor(cpFrame, gFrame, CV_BGR2GRAY);
    //cv::imshow(wName, gFrame);
    //##############################################################################################//
    cv::Size boardSize(6, 4);

      float squareSize = 1.f; // This is "1 arbitrary unit"

      //cv::Mat image = cv::imread("../cosos/tablero.png");
      cv::Mat image = frame.clone();


      cv::namedWindow( "Image View", 1 );

      cv::Size imageSize = image.size();

      // Find the chessboard corners
      std::vector<std::vector<cv::Point2f> > imagePoints(1);
      bool found = cv::findChessboardCorners(image, boardSize, imagePoints[0]);
      if(!found)
        {
        std::cerr << "Could not find chess board!" << std::endl;
        }

      cv::drawChessboardCorners(image, boardSize, cv::Mat(imagePoints[0]), found );
    /*
      std::vector<std::vector<cv::Point3f> > objectPoi1nts;
      objectPoints[0] = this->Create3DChessboardCorners(boardSize, squareSize);

      std::vector<cv::Mat> rotationVectors;
      std::vector<cv::Mat> translationVectors;

      cv::Mat distortionCoefficients = cv::Mat::zeros(8, 1, CV_64F); // There are 8 distortion coefficients
      cv::Mat cameraMatrix = cv::Mat::eye(3, 3, CV_64F);

      int flags = 0;
      double rms = calibrateCamera(objectPoints, imagePoints, imageSize, cameraMatrix,
                      distortionCoefficients, rotationVectors, translationVectors, flags|CV_CALIB_FIX_K4|CV_CALIB_FIX_K5);

      std::cout << "RMS: " << rms << std::endl;

      std::cout << "Camera matrix: " << cameraMatrix << std::endl;
      std::cout << "Distortion _coefficients: " << distortionCoefficients << std::endl;
*/
      cv::imshow("Image View", image);

}
std::vector<cv::Point3f> Calibrar::Create3DChessboardCorners(cv::Size boardSize, float squareSize)
{
  // This function creates the 3D points of your chessboard in its own coordinate system

  std::vector<cv::Point3f> corners;

  for( int i = 0; i < boardSize.height; i++ )
  {
    for( int j = 0; j < boardSize.width; j++ )
    {
      corners.push_back(cv::Point3f(float(j*squareSize),float(i*squareSize), 0));
    }
  }
  return corners;
}


















