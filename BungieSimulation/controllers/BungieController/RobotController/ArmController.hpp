#ifndef ARM_CONTROLLER_HEADER
#define ARM_CONTROLLER_HEADER

#include <webots/Motor.hpp>
#include <webots/Robot.hpp>

namespace bungie {

/// @brief Class used for controlling the arm of the Bungie Rover.
class ArmController {

public:

  /// @brief Constructs a new ArmController instance.
  /// @param webots::Robot* A pointer to the robot containing the arm to control.
  ArmController(webots::Robot* robot);
  
  /// @brief Moves the arm into the given direction.
  /// @param direction The direction to turn the arm into.
  /// @param velocity The velocity, in radians per second, at which to rotate the arm.
  /// @return void
  void PowerJointMotors(char direction, double velocity);
  
  /// @brief Moves the arm into the given direction.
  /// @param direction The direction to turn the arm into.
  /// @param velocity The velocity, in radians per second, at which to rotate the arm.
  /// @return void
  void PowerClawMotors(char direction, double velocity);
  
  /// @brief Deconstructs the ArmController instance.
  ~ArmController();

private:

  /// @brief An enum, enumerating every motor used in the arm.
  enum Motor {
      ARM_ROTATION_MOTOR, ARM_BASE_MOTOR, 
      ARM_MID_MOTOR, ARM_END_MOTOR,
      TOTAL_MOTORS
  };

  /// @brief The motors powering the arm.
  webots::Motor* motors[TOTAL_MOTORS];

};

}

#endif
