#ifndef WHEEL_CONTROLLER_HEADER
#define WHEEL_CONTROLLER_HEADER

#include <webots/Robot.hpp>
#include <webots/Motor.hpp>

namespace bungie {

class WheelController {

  public:

    WheelController(webots::Robot *robot);
    ~WheelController();
    
    void PowerMotors(char direction, double velocity);
    void SetMotorsPosition(double position);
    void SetRotation(double distance);

  private:

    enum Motor {
      LEFT_MOTOR, LEFT_PAW_MOTOR,
      RIGHT_MOTOR, RIGHT_PAW_MOTOR,
      LEFT_PAW_ROTATION_MOTOR, RIGHT_PAW_ROTATION_MOTOR,
      TOTAL_MOTORS
    };

    webots::Motor* motors[TOTAL_MOTORS];

};

}

#endif