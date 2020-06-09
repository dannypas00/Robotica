#include "ArmController.hpp"

namespace bungie {
  
  ArmController::ArmController(webots::Robot *robot) 
    : motors { 
      robot->getMotor("arm_rotation_motor"), robot->getMotor("arm_base_motor"),
      robot->getMotor("arm_mid_motor"), robot->getMotor("arm_end_motor")
    }
    {
    for (auto* motor : this->motors) {
      motor->setPosition(INFINITY);
      motor->setVelocity(1.0);
    }
  }
  
  void ArmController::MoveArm(double velocity){
  
  }
  
  void ArmController::PowerJointMotors(char direction, double velocity) {
        switch (direction) {
        case 'u':
            for (int i = ARM_BASE_MOTOR; i <= ARM_END_MOTOR; i++)
            {

                //this->motors[i]->setPosition(2.09); //120 deg in radians
                currentPos += 0.001;
                this->motors[i]->setPosition(currentPos);
            }
            break;
        case 'd':
            for (int i = ARM_BASE_MOTOR; i <= ARM_END_MOTOR; i++)
            {
                //this->motors[i]->setPosition(1.57); //90 deg in radians
                currentPos -= 0.001;
                this->motors[i]->setPosition(currentPos);
            }
            break;
        case 'l':
            this->motors[ARM_ROTATION_MOTOR]->setVelocity(velocity);

            break;
        case 'r':
            this->motors[ARM_ROTATION_MOTOR]->setVelocity(-velocity);
            
            break;
        }
    }
  
    
  ArmController::~ArmController(){
   for (auto i = 0; i < TOTAL_MOTORS; i++) {
      delete this->motors[i];
      this->motors[i] = nullptr;
    }
  }
}