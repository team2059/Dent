#include "cv.h"
#include "highgui.h"

using namespace std;
using namespace cv;
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

IplImage* GetImageEdges(IplImage *img){
    const int lowerEdgeThresh = 10;
    const int editRatio = 3;
    Mat org, dst;
    //Convert the IplImage to a mat
    org = img;
    //Blur the image "org" and output it to dst
    GaussianBlur(org,dst,Size(5,5),0,0);
    //Copy dst to org to keep naming correct
    org = dst;
    //Use canny to find edges
    Canny(org,dst,lowerEdgeThresh,lowerEdgeThresh*3,3);
    //Convert the Mat back to an image
    img->imageData = (char *) dst.data;
    return img;
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
    //Display the image after getting the edges of the yellowThresholded image
    cvShowImage("thresh", GetImageEdges(imgYellowThresh));
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
