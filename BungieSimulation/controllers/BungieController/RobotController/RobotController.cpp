#include "RobotController.hpp"

using namespace std;

namespace bungie {

RobotController& RobotController::getInstance(){
   static RobotController instance;
   return instance;
}
  
RobotController::RobotController(){
  // create the Robot instance.
  robot = new webots::Robot();
  wheel_controller = new WheelController(robot);
}


void RobotController::Drive(char direction, double velocity){
  wheel_controller->PowerMotors(direction, velocity);
}

void RobotController::DriveUnits(char direction, double velocity, double distance) {
  if (direction == 'b')
    distance *= -1;
  wheel_controller->SetMotorsPosition(distance, velocity);
}

RobotController::~RobotController(){
  delete robot;
  delete wheel_controller;
}
}