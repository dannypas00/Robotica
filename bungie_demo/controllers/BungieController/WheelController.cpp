#include "WheelController.hpp"

using namespace std;

namespace bungie {
  WheelController::WheelController(webots::Motor *motor){//, webots::Brake *brake) {
    this->motor = motor;
    //this->brake = brake;
  }
  
  WheelController::~WheelController(){}
  
  void WheelController::PowerMotor(double velocity){
    motor->setVelocity(velocity);
  }
}
