#include "WheelController.hpp"

using namespace std;

namespace bungie {
  WheelController::WheelController(webots::Robot *robot) {
    this->left_motor = robot->getMotor("left_motor");
    this->right_motor = robot->getMotor("right_motor");
    
    left_motor->setPosition(INFINITY);
    right_motor->setPosition(INFINITY);
    
    left_motor->setVelocity(0.0);
    right_motor->setVelocity(0.0); 
  }
  
  void WheelController::PowerMotors(char direction, double velocity){
    switch(direction){
      case 'f':
        left_motor->setVelocity(velocity);
        right_motor->setVelocity(velocity);
        break;
      case 'b':
        left_motor->setVelocity(-velocity);
        right_motor->setVelocity(-velocity);
        break;
      case 'l':
        left_motor->setVelocity(-velocity);
        right_motor->setVelocity(velocity);
        break;
      case 'r':
        left_motor->setVelocity(velocity);
        right_motor->setVelocity(-velocity);
        break;
    }
  }
  
  WheelController::~WheelController(){
    delete left_motor;
    delete right_motor;
  }
}
