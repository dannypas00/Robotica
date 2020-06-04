#ifndef OBJ_REC_CONTROLLER
#define OBJ_REC_CONTROLLER

#include <iostream>
#include <vector>

#include <webots/Camera.hpp>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "ISubject.hpp"
#include "IObserver.hpp"


using namespace cv;

namespace bungie {
  class ObjectRecognitionController : public ISubject {
    public:
      ObjectRecognitionController(Camera* _cam){ // cv::Mat image
        std::cout << "ObjectRecognition [CREATE]" << std::endl;
        
        //unsigned char img_data[] = {
          // first row, 4 colored pixels
        //  0, 0, 0,
        //  255, 0, 0,
        //  0, 0, 0 ,
        //  0, 255, 0,

          // second row, 4 colored pixels
        //  0, 0, 255,
        //  0, 0, 0,
        //  255, 0, 255,
        //  0, 0, 0
        //};
        
        // get a correct pointer to the data
        //unsigned char * img_data_ptr = (unsigned char*) &img_data;
        
        //cv::Mat img(2, 4, CV_8UC3, img_data_ptr);
        //cv::cvtColor(img, img, cv::COLOR_BGR2RGB);
        Mat fileImg = imread("card_screenshot.png");
        //cv::Mat image = new cv::Mat(_cam->getWidth(), _cam->getHeight(), CV_8UC3, _cam->getImage());
        //cv::namedWindow("window", cv::WINDOW_AUTOSIZE);
        //cv::imshow("window", img);
      };
      ~ObjectRecognitionController(){
        std::cout << "ObjectRecognition [DESTROY]" << std::endl;
      };

      void update(){};
      void detect(){};

      virtual void registObserver(IObserver _observer){};
      virtual void removeObserver(IObserver _observer){};
      virtual void notifyObservers(){};

    private:

  };
}

#endif
