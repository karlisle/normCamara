#include "calib.h"

using namespace std;
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
        this->video(1);
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
    capture.open(0);

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
        //this->calibcam(frame);
        cv::imshow("Frame", frame);
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
/* La siguiente funcion se usara para calibrar la camara :)!
*/
void Calibrar::calibcam()
{
    string wName = "Frame";
    cv::namedWindow(wName, CV_WINDOW_NORMAL);

   // cv::Mat cpFrame = frame.clone();
   // cv::Mat gFrame;
   // cv::cvtColor(cpFrame, gFrame, CV_BGR2GRAY);
    //cv::imshow(wName, gFrame);
    //##############################################################################################//
    cv::Size boardSize(7,7);

    float squareSize = 1.f; // This is "1 arbitrary unit"
    for (int i = 0; i < 10; ++i)
    {
        cv::Mat image = cv::imread("tablero"+ to_string(i) +".png");

        cv::Size imageSize = image.size();

         // Find the chessboard corners
         vector<vector<cv::Point2f> > imagePoints(1);
         bool found = cv::findChessboardCorners(image, boardSize, imagePoints[0]);
          if(!found)
           {
               cerr << "Could not find chess board!" << endl;
           }

          cv::drawChessboardCorners(image, boardSize, cv::Mat(imagePoints[0]), found );
        }
        vector<vector<cv::Point3f>> objectPoints;
        objectPoints.push_back(this->Create3DChessboardCorners(boardSize, squareSize));

        //cout << objectPoints[0] << endl;
        vector<cv::Mat> rotationVectors;
        vector<cv::Mat> translationVectors;

        cv::Mat distortionCoefficients = cv::Mat::zeros(8, 1, CV_64FC1); // There are 8 distortion coefficients
        cv::Mat cameraMatrix = cv::Mat::eye(3, 3, CV_64FC1);

        int flags = 0;
        double rms = cv::calibrateCamera(objectPoints, imagePoints, imageSize, cameraMatrix,distortionCoefficients, rotationVectors, translationVectors, flags|CV_CALIB_FIX_K4|CV_CALIB_FIX_K5);

        cout << "RMS: " << rms << endl;

        cout << "Camera matrix: " << cameraMatrix << endl;
        cout << "Distortion _coefficients: " << distortionCoefficients << endl;

        cv::imshow(wName, image);
         cv::waitKey(0);
          return;
}

vector<cv::Point3f> Calibrar::Create3DChessboardCorners(cv::Size boardSize, float squareSize)
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
