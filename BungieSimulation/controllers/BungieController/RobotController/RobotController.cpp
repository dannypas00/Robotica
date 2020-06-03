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

void RobotController::MoveUnits(double distance, char direction, double velocity) {
  return;
}

RobotController::~RobotController(){
  delete robot;
  delete wheel_controller;
}
}