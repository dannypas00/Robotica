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
    motor->setVelocity(0.0);
  }
}

void ArmController::PowerJointMotors(char direction, double velocity) {
  switch (direction) {
  case 'u':
    for (int i = ARM_BASE_MOTOR; i < TOTAL_MOTORS; i++)
      this->motors[i]->setVelocity(velocity);

    break;

  case 'd':
    for (int i = ARM_BASE_MOTOR; i < TOTAL_MOTORS; i++)
      this->motors[i]->setVelocity(-velocity);

    break;

  case 'l':
    this->motors[ARM_ROTATION_MOTOR]->setVelocity(velocity);
    break;

  case 'r':
    this->motors[ARM_ROTATION_MOTOR]->setVelocity(-velocity);
    break;

  }
}

  
ArmController::~ArmController() {
  for (auto i = 0; i < TOTAL_MOTORS; i++)
    this->motors[i] = nullptr;
}

}
