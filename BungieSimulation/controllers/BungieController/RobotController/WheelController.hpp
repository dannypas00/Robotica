#ifndef WHEEL_CONTROLLER_HEADER
#define WHEEL_CONTROLLER_HEADER

#include <webots/Robot.hpp>
#include <webots/Motor.hpp>

namespace bungie {

class WheelController {

public:

  /// @brief Constructor of the WheelController initializes all motors in the tracks.
  /// @param webots::Robot *robot A pointer to the instance of the WeBots Robot class.
  WheelController(webots::Robot *robot);

  /// @brief Power the motors of the tracks.
  /// @param char direction The direction given as the characters: 'l' for left, 'r' for right, 'f'for forward and 'b' for backwards.
  /// @param double velocity The velocity stands for radians per second the joints in the arm should rotate.
  /// @return void
  void PowerMotors(char direction, double velocity);

  /// @brief Set the position of the motors in the tracks.
  /// @param double position The position the the motors should rotate to.
  /// @return  void
  void SetMotorsPosition(double position);

  /// @brief Set the rotation of the motors in the tracks.
  /// @param double distance The distance the motors in the track should rotate.
  /// @return  void
  void SetRotation(double distance);

  /// @brief Destructor deletes all object made under it's scope.
  ~WheelController();

private:

  /// @brief enum Motor defines the different motors in the tracks for further use.
  enum Motor {
    LEFT_MOTOR, LEFT_PAW_MOTOR,
    RIGHT_MOTOR, RIGHT_PAW_MOTOR,
    LEFT_PAW_ROTATION_MOTOR, RIGHT_PAW_ROTATION_MOTOR,
    TOTAL_MOTORS
  };

  /// @brief An array of motors in the tracks of the WeBots Motor type, initialized with all motors.
  webots::Motor* motors[TOTAL_MOTORS];

};

}

#endif