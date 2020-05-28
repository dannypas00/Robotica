#include "ArmController.hpp"

namespace bungie {
  
  ArmController::ArmController(webots::Motor *motor){
    this->motor = motor;
  }
  
  ArmController::~ArmController(){}
  
  void ArmController::MoveArm(double velocity){}
  
  void ArmController::PowerArm(double velocity){}
}