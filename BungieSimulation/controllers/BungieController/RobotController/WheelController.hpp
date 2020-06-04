#ifndef WHEEL_CONTROLLER_HEADER
#define WHEEL_CONTROLLER_HEADER

#include <webots/Robot.hpp>
#include <webots/Motor.hpp>
#include <webots/Brake.hpp>

namespace bungie {
class WheelController {
  public:
    WheelController(webots::Robot *robot);
    ~WheelController();

    void PowerMotors(char direction, double velocity);
  private:
    webots::Motor *left_motor;
    webots::Motor *right_motor;
};
}

#endif
