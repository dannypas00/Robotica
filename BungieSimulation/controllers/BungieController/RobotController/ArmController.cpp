#include "ArmController.hpp"

namespace bungie {

ArmController::ArmController(webots::Robot* robot, const double velocity)
  : robot(robot),
    motors {
      robot->getMotor("arm_rotation_motor"), robot->getMotor("arm_base_motor"),
      robot->getMotor("arm_mid_motor"), robot->getMotor("arm_end_motor")
    },
    positionSensors {
      robot->getPositionSensor("arm_rotation_sensor"), robot->getPositionSensor("arm_base_sensor"),
      robot->getPositionSensor("arm_mid_sensor"), robot->getPositionSensor("arm_end_sensor")
    },
    velocity(velocity)
{
  for (auto* motor : this->motors) {
    motor->setPosition(0.0);
    motor->setVelocity(velocity);
  }

  for (auto* positionSensor : this->positionSensors) {
    positionSensor->enable(robot->getBasicTimeStep());
  }
}

void ArmController::SetVelocity(const double velocity) {
  this->velocity = fabs(velocity);

  for (auto* motor : this->motors)
    motor->setVelocity(this->velocity);
}

void ArmController::Rotate(const double rotation) {
    this->Rotate(rotation, rotation, rotation);
}

void ArmController::Rotate(const double base_rotation, const double shoulder_rotation, const double elbow_rotation, const double wrist_rotation) {
    this->Rotate(ROTATABLE_BASE, base_rotation);
    this->Rotate(shoulder_rotation, elbow_rotation, wrist_rotation);
}

void ArmController::Rotate(const double shoulder_rotation, const double elbow_rotation, const double wrist_rotation) {
    this->Rotate(SHOULDER_JOINT, shoulder_rotation);
    this->Rotate(ELBOW_JOINT, elbow_rotation);
    this->Rotate(WRIST_JOINT, wrist_rotation);
}

void ArmController::Rotate(Device device, const double rotation) {
    this->SetRotation(device, this->GetRotation(device) + rotation);
}

double ArmController::GetRotation(Device device) const {
  return convertRadToDeg(this->positionSensors[device]->getValue());
}

void ArmController::SetRotations(const double angle) {
  this->SetRotations(angle, angle, angle);
}

void ArmController::SetRotations(const double base_angle, const double shoulder_angle, const double elbow_angle, const double wrist_angle) {
  this->SetRotation(ROTATABLE_BASE, base_angle);
  this->SetRotations(shoulder_angle, elbow_angle, wrist_angle);
}

void ArmController::SetRotations(const double shoulder_angle, const double elbow_angle, const double wrist_angle) {
  this->SetRotation(SHOULDER_JOINT, shoulder_angle);
  this->SetRotation(ELBOW_JOINT, elbow_angle);
  this->SetRotation(WRIST_JOINT, wrist_angle);
}

void ArmController::SetRotation(Device device, double angle) {
  static constexpr auto THRESHOLD = 0.001;

  auto motor = this->motors[device];
  auto positionSensor = this->positionSensors[device];

  angle = convertDegToRad(angle);
  motor->setPosition(angle);

  while (fabs(positionSensor->getValue() - angle) > THRESHOLD) {
    if (this->robot->step(this->robot->getBasicTimeStep()) == -1)
      break;
  }
}

double ArmController::convertRadToDeg(const double radians) {
  static constexpr auto DEGREES_PER_RADIAN = 360.0/(2.0*M_PI);
  return radians * DEGREES_PER_RADIAN;
}

double ArmController::convertDegToRad(const double degrees) {
  static constexpr auto RADIANS_PER_DEGREE = (2.0*M_PI)/360.0;
  return degrees * RADIANS_PER_DEGREE;
}
  
ArmController::~ArmController() {
  for (auto device = 0; device < TOTAL_DEVICES; device++) {
    this->motors[device] = nullptr;
    this->positionSensors[device] = nullptr;
  }
}

}
