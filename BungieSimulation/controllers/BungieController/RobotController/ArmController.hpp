#ifndef ARM_CONTROLLER_HEADER
#define ARM_CONTROLLER_HEADER

#include <webots/Motor.hpp>
#include <webots/Robot.hpp>

namespace bungie {

class ArmController {
  public:
  ArmController(webots::Robot *robot);
  ~ArmController();
  
  void MoveArm(double velocity);
  void PowerJointMotors(char direction, double velocity);
  
  private:
  enum Motor {
      ARM_ROTATION_MOTOR, ARM_BASE_MOTOR, 
      ARM_MID_MOTOR, ARM_END_MOTOR,
      TOTAL_MOTORS
    };
    
  double currentPos;
    
  webots::Motor* motors[TOTAL_MOTORS];
};
}

#endif