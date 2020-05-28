#ifndef WHEEL_CONTROLLER_HEADER
#define WHEEL_CONTROLLER_HEADER

#include <webots/Motor.hpp>

namespace bungie {

class WheelController {
  public:
    WheelController(webots::Motor *motor);//, webots::Brake *brake);
    ~WheelController();
    
    void PowerMotor(double velocity);
    void PowerBrake(double velocity);
  private:
    webots::Motor *motor;
    webots::Brake *brake;
};
}

#endif