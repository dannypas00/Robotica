#ifndef BUNGIE_CONTROLLER_HEADER
#define BUNGIE_CONTROLLER_HEADER

#include <webots/Robot.hpp>
#include <webots/Motor.hpp>

//Testing
#include <webots/Keyboard.hpp>

#include "WheelController.hpp"
#include "ArmController.hpp"

#include <webots/Camera.hpp>

#define TIME_STEP 64


namespace bungie {

class RobotController {
  public:
  static RobotController& getInstance();
  
  void Drive(char direction, double velocity);
  void DriveUnits(char direction, double distance);
  
  void MoveArm(char direction, double velocity);
  
  const unsigned char* getCamera() { return camera->getImage(); }
 
  webots::Robot& getRobot() { return *robot; }
  
  ~RobotController();
    
  private:
  webots::Robot *robot;
  
  WheelController* wheel_controller;
  ArmController* arm_controller;
  
  webots::Camera *camera;
  RobotController();
  RobotController(const RobotController&) = default;
};

}
#endif