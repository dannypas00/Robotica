// File:          RobotVisionTestController.cpp
// Date:
// Description:
// Author:
// Modifications:

// You may need to add webots include files such as
// <webots/DistanceSensor.hpp>, <webots/Motor.hpp>, etc.
// and/or to add some other includes
#include <webots/Robot.hpp>
#include <webots/Camera.hpp>
#include <iostream>

#include <Python.h>
//#include "ObjectRecognitionController.hpp"
//#include <opencv2/opencv.hpp>

// All the webots classes are defined in the "webots" namespace
using namespace webots;
//using namespace bungie;

// This is the main program of your controller.
// It creates an instance of your Robot instance, launches its
// function(s) and destroys it at the end of the execution.
// Note that only one instance of Robot should be created in
// a controller program.
// The arguments of the main function can be specified by the
// "controllerArgs" field of the Robot node
int main(int argc, char **argv) {
  // create the Robot instance.
  Robot* robot = new Robot();
  //Camera* cam = robot->getCamera("camera");
  //cam->enable(10);
  //cv::Mat fileImg = cv::imread("objectrecognition/card_screenshot.png");
  
  /*std::cout << "ON!" << std::endl;
  const unsigned char* image = cam->getImage();
  int byteSize = cam->getWidth() * cam->getHeight() * 4;
  std::cout << "camera-size: " << std::to_string(byteSize) << std::endl;
  for (int x = 0; x < cam->getWidth(); x++) {
    for (int y = 0; y < cam->getHeight(); y++) {
      unsigned char r = Camera::imageGetRed(image, cam->getWidth(), x, y);
      unsigned char g = Camera::imageGetGreen(image, cam->getWidth(), x, y);
      unsigned char b = Camera::imageGetBlue(image, cam->getWidth(), x, y);
      //std::cout << "r" << std::to_string(r) << std::endl;
    }
  }*/
  
  std::string _className = "python_test.py";
  std::string _functionName = "returnValue";
  
  PyObject *pName, *pModule, *pFunc;
  PyObject *pArgs, *pValue;
  int i;

  Py_Initialize();
  
  pName = PyUnicode_FromString("python_test");
  /* Error checking of pName left out */

  pModule = PyImport_Import(pName);
  Py_DECREF(pName);

  if (pModule != NULL) {
      pFunc = PyObject_GetAttrString(pModule, _functionName.c_str());
      pValue = PyObject_CallObject(pFunc, pArgs);
      Py_XDECREF(pFunc);
      Py_DECREF(pModule);
      
      std::cout << "return value: " << pValue << std::endl;
  }
  else {
      PyErr_Print();
      std::cout << "failed to load " << _className << std::endl;
  }
  Py_Finalize();
  
  /*
  
  
  
  int a = cam->saveImage(".png", 1);
  
  std::cout << "camera-save_int: " << std::to_string(a) << std::endl;YY
  try{
    Py_Initialize();
    PyRun_SimpleString("print('hello')\n");
    Py_Finalize();
  }catch(const std::exception& e){
    std::cout << "error: " << e.what() << "\n";
  }
  std::cout << "B\n";*/
  
  //ObjectRecognitionController* con = new ObjectRecognitionController(cam);
  
  //con->update();
  
  
  int timeStep = (int)robot->getBasicTimeStep();
  
  // Main loop:
  // - perform simulation steps until Webots is stopping the controller
  while (robot->step(timeStep) != -1) {
    // Read the sensors:
    // Enter here functions to read sensor data, like:
    //  double val = ds->getValue();
    
    // Process sensor data here.
    
    // Enter here functions to send actuator commands, like:
    //  motor->setPosition(10.0);
  };

  // Enter here exit cleanup code.
  
  delete robot;
  return 0;
}
