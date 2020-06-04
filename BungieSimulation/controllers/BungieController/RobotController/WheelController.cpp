#include "WheelController.hpp"

using namespace std;

namespace bungie {
  WheelController::WheelController(webots::Robot *robot)
    : motors { robot->getMotor("left_motor"), robot->getMotor("left_paw_motor"),
               robot->getMotor("right_motor"), robot->getMotor("right_paw_motor"),
               robot->getMotor("left_paw_rotation_motor"), robot->getMotor("right_paw_rotation_motor") }
  {
    for (auto* motor : this->motors) {
      motor->setPosition(INFINITY);
      motor->setVelocity(0.0);
    }
  }
  
  void WheelController::PowerMotors(char direction, double velocity){
    switch(direction){
      case 'f':
        for (auto i = 0; i <= RIGHT_PAW_MOTOR; i++)
          this->motors[i]->setVelocity(velocity);

        break;
      case 'b':
        for (auto i = 0; i <= RIGHT_PAW_MOTOR; i++)
          this->motors[i]->setVelocity(-velocity);

        break;
      case 'l':
        for (auto i = 0; i <= RIGHT_PAW_MOTOR; i++)
          this->motors[i]->setVelocity(i <= LEFT_PAW_MOTOR ? -velocity : velocity);

        break;
      case 'r':
        for (auto i = 0; i <= RIGHT_PAW_MOTOR; i++)
          this->motors[i]->setVelocity(i <= LEFT_PAW_MOTOR ? velocity : -velocity);

        break;
    }
  }
  
  WheelController::~WheelController(){
    for (auto i = 0; i < TOTAL_MOTORS; i++) {
      delete this->motors[i];
      this->motors[i] = nullptr;
    }
  }
}
