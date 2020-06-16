// File:          RobotVisionTestController.cpp
// Date:
// Description:
// Author: Sidney Dijkstra
// Modifications:

#include <webots/Robot.hpp>
#include <webots/Camera.hpp>
#include <iostream>
#include <functional>

#include "PythonController.hpp"
#include "ObjectRecognitionController.hpp"
#include "ObjectRecognitionData.hpp"
#include "ObjectRecognitionObserver.hpp"

// All the webots classes are defined in the "webots" namespace
using namespace webots;
using namespace bungie;

bool done = false;

void onQrCallback(ObjectRecognitionData* _data){
  QrCode* qr = (QrCode*)_data;
  std::string text = qr->getData();
  std::cout << "card_type->" << text << std::endl;
}

void onCardCallback(ObjectRecognitionData* _data){
  Card* card = (Card*)_data;
  std::string text = card->getCardType();
  std::cout << "card_type->" << text << std::endl;
}

void onMineralCallback(ObjectRecognitionData* _data){
  Mineral* mineral = (Mineral*)_data;
  std::string text = mineral->getMin();
  std::cout << "mineral_info->" << text << std::endl;
}

void onTemperatureCallback(ObjectRecognitionData* _data){
  Temperature* temperature = (Temperature*)_data;
  std::string text = temperature->getState();
  std::cout << "temperature_state->" << text << std::endl;
}

int main(int argc, char **argv) {
  // create the Robot instance.
  Robot* robot = new Robot();
  int timeStep = (int)robot->getBasicTimeStep();
  Camera* cam = robot->getCamera("camera");
  cam->enable(timeStep);
  
  PythonController::getInstance().init();
  PythonController::getInstance().setModule("pythonInterpreter");
  PythonController::getInstance().callFunction("init");
  
  ObjectRecognitionObserver* observerA = new ObjectRecognitionObserver(ObjectRecognitionType::QRCODE, &onQrCallback);
  ObjectRecognitionObserver* observerB = new ObjectRecognitionObserver(ObjectRecognitionType::CARD, &onCardCallback);
  ObjectRecognitionObserver* observerC = new ObjectRecognitionObserver(ObjectRecognitionType::MINERAL, &onMineralCallback);
  ObjectRecognitionObserver* observerD = new ObjectRecognitionObserver(ObjectRecognitionType::TEMPERATURE, &onTemperatureCallback);
  
  ObjectRecognitionController::getInstance().registObserver(observerA);
  ObjectRecognitionController::getInstance().registObserver(observerB);
  ObjectRecognitionController::getInstance().registObserver(observerC);
  ObjectRecognitionController::getInstance().registObserver(observerD);
  
  while (robot->step(timeStep) != -1) {
    ObjectRecognitionController::getInstance().detectAll(cam);
  };
  
  PythonController::getInstance().exit();
  
  delete cam;
  delete robot;
  return 0;
}
