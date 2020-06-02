#ifndef ARM_CONTROLLER_HEADER
#define ARM_CONTROLLER_HEADER

#include <webots/Motor.hpp>

namespace bungie {

class ArmController {
  public:
    ArmController(webots::Motor *motor);
    ~ArmController();
    
    void MoveArm(double velocity);
  private:
    webots::Motor *motor;
    
    void PowerArm(double velocity);
};
}

#endif