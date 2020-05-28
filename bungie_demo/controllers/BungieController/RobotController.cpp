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
  left_controller = new WheelController(robot->getMotor("left_motor"));
  right_controller = new WheelController(robot->getMotor("right_motor"));
}

static void RobotController::drive(char direction, double velocity){

}

RobotController::~RobotController(){
  delete robot;
}
}