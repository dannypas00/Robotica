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
  arm_controller = new ArmController(robot);
}


void RobotController::Drive(char direction, double velocity){
  wheel_controller->PowerMotors(direction, velocity);
}

void RobotController::MoveUnits(char direction, double units){
   
}

void RobotController::MoveArm(char direction, double velocity){
  arm_controller->PowerJointMotors(direction, velocity);
}

RobotController::~RobotController(){
  delete robot;
  delete wheel_controller;
  delete arm_controller;
}
}