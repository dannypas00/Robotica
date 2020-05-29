#ifndef BUNGIE_CONTROLLER_HEADER
#define BUNGIE_CONTROLLER_HEADER

#include <webots/Robot.hpp>
#include <webots/Motor.hpp>

//Testing
#include <webots/Keyboard.hpp>

#include "WheelController.hpp"

#define TIME_STEP 64


namespace bungie {

class RobotController {
  public:
  static RobotController& getInstance();
  
  void Drive(char direction, double velocity);
  //TODO: Add drive towards function
    
  webots::Robot& getRobot() { return *robot; }
  
  ~RobotController();
    
  private:
  webots::Robot *robot;
  
  WheelController* wheel_controller;
  RobotController();
};

}
#endif