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
  
  camera = robot->getCamera("front_CAM");
  camera->enable(TIME_STEP);
}


void RobotController::Drive(char direction, double velocity){
  wheel_controller->PowerMotors(direction, velocity);
}

void RobotController::DriveUnits(char direction, double distance) {
  if (direction == 'b')
    distance *= -1;
  wheel_controller->SetMotorsPosition(distance);
}

void RobotController::Rotate(double deg) {
  //Radial of 1.570 == 90 degrees
  //1.9145945 radials per unit rotated
  //0.82 units ~= 90 degrees
  //~0.0091111 units per degree
  wheel_controller->SetRotation(deg * 0.0091111);
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