#ifndef OBJ_REC_CONTROLLER
#define OBJ_REC_CONTROLLER

#include <iostream>
#include <vector>

#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"

#include "ISubject.hpp"
#include "IObserver.hpp"


namespace bungie {
  class ObjectRecognitionController : public ISubject {
    public:
      ObjectRecognitionController(){ // cv::Mat image
        std::cout << "ObjectRecognition [CREATE]" << std::endl;


         //cv::Mat image = cv::imread("card_screenshot.png");
         //cv::namedWindow("window", cv::WINDOW_AUTOSIZE);
         //cv::imshow("window", image);
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
