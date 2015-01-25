#include "cv.h"
#include "highgui.h"
IplImage* GetThresholdedImage(IplImage* img){
  // Convert the image into an HSV image
  IplImage* imgHSV = cvCreateImage(cvGetSize(img), 8, 3);
  cvCvtColor(img, imgHSV, CV_BGR2HSV);
  IplImage* imgThreshed = cvCreateImage(cvGetSize(img), 8, 1);
  // Set yellow to white and all other colors to black
  //cvInRangeS(imgHSV, cvScalar(20, 100, 100), cvScalar(30, 255, 255), imgThreshed);
  cvInRangeS(imgHSV, cvScalar(10, 100, 100), cvScalar(40, 255, 255), imgThreshed);
  cvReleaseImage(&imgHSV);
  return imgThreshed;
}
int main()
{
  // Initialize capturing live feed from the camera
  CvCapture* capture = 0;

  capture = cvCaptureFromCAM(0);

  // Couldn't get a device? Throw an error and quit
  if(!capture){
    printf("Could not initialize capturing...");
    return -1;
  }
  cvNamedWindow("video");
  cvNamedWindow("thresh");
  while(true){
    // Will hold a frame captured from the camera
    IplImage* frame = 0;
    frame = cvQueryFrame(capture);
    // If we couldn't grab a frame... quit
    if(!frame)
      break;
    // If this is the first frame, we need to initialize it
    // Holds the yellow thresholded image (yellow = white, rest = black)
    IplImage* imgYellowThresh = GetThresholdedImage(frame);


    cvShowImage("thresh", imgYellowThresh);
    cvShowImage("video", frame);
    // Quit on keypress
    int c = cvWaitKey(10);
    if(c!=-1){
      break;
    }
    cvReleaseImage(&imgYellowThresh);
  }
  // We're done using the camera. Other applications can now use it
  cvReleaseCapture(&capture);
  return 0;
}
