#ifndef ARM_CONTROLLER_HEADER
#define ARM_CONTROLLER_HEADER

#include <webots/Motor.hpp>
#include <webots/PositionSensor.hpp>
#include <webots/Robot.hpp>

#include <cmath>

namespace bungie {

/// @brief Class used for controlling the arm of the Bungie Rover.
class ArmController {

public:

  /// @brief An enum, enumerating every device used in the arm.
  enum Device {
      ROTATABLE_BASE, SHOULDER_JOINT, ELBOW_JOINT, WRIST_JOINT, 
      LEFT_CLAW_JOINT, RIGHT_CLAW_JOINT,
      TOTAL_DEVICES
  };

  /// @brief Constructs a new ArmController instance.
  /// @param robot A pointer to the robot containing the arm to control.
  /// @param velocity The velocity at which to rotate the arm (default = 0.0).
  ArmController(webots::Robot* robot, double velocity = 0.0);

  /// @brief Sets the velocity at which to rotate the arm.
  /// @param velocity The velocity at which to rotate the arm.
  /// @return void
  void SetVelocity(double velocity);

  /// @brief Convenience method, rotate every hingejoint in the arm.
  /// @param rotation The amount of degrees to rotate the joints.
  /// @return void
  void Rotate(double rotation);

  /// @brief Convenience method, rotating the base, shoulder, elbow and wrist joints.
  /// @param base_rotation The amount of degrees to rotate the base.
  /// @param shoulder_rotation The amount of degrees to rotate the shoulder joint.
  /// @param elbow_rotation The amount of degrees to rotate the elbow joint.
  /// @param wrist_rotation The amount of degrees to rotate the wrist joint.
  /// @return void
  void Rotate(double base_rotation, double shoulder_rotation, double elbow_rotation, double wrist_rotation);
  
  /// @brief Convenience method, rotating the shoulder, elbow and wrist joints.
  /// @param shoulder_rotation The amount of degrees to rotate the shoulder joint.
  /// @param elbow_rotation The amount of degrees to rotate the elbow joint.
  /// @param wrist_rotation The amount of degrees to rotate the wrist joint.
  /// @return void
  void Rotate(double shoulder_rotation, double elbow_rotation, double wrist_rotation);

  /// @brief Rotates the specified joint the given amount of degrees.
  /// @param device The device associated with the joint to rotate.
  /// @param rotation The amount of degrees to rotate the specified joint.
  /// @return void
  void Rotate(Device device, double rotation);

  /// @brief Gets the current rotation of the specified joint.
  /// @param device The device associated with the joint.
  /// @return double The current rotation of the specified joint.
  double GetRotation(Device device) const;

  /// @brief Convenience method, sets the rotation of every hingejoint in the arm.
  /// @param angle The amount of degrees to set the rotation to.
  /// @return void
  void SetRotations(double angle);

  /// @brief Convenience method, sets the rotation of the base, shoulder, elbow and wrist joints.
  /// @param base_angle The amount of degrees to set the rotation of the base to.
  /// @param shoulder_angle The amount of degrees to set the rotation of the shoulder joint to.
  /// @param elbow_angle The amount of degrees to set the rotation of the elbow joint to.
  /// @param wrist_angle The amount of degrees to set the rotation of the wrist joint to.
  /// @return void
  void SetRotations(double base_angle, double shoulder_angle, double elbow_angle, double wrist_angle);

  /// @brief Convenience method, sets the rotation of the shoulder, elbow and wrist joints.
  /// @param shoulder_angle The amount of degrees to set the rotation of the shoulder joint to.
  /// @param elbow_angle The amount of degrees to set the rotation of the elbow joint to.
  /// @param wrist_angle The amount of degrees to set the rotation of the wrist joint to.
  /// @return void
  void SetRotations(double shoulder_angle, double elbow_angle, double wrist_angle);

  /// @brief Sets the rotation of the specified joint to the given angle.
  /// @param device The device associated with the joint to set the rotation of.
  /// @param angle The amount of degrees to set the rotation of the specified joint to.
  /// @return void
  void SetRotation(Device device, double angle);
  
  /// @brief Sets the rotation of the grabber joints to the given angle.
  /// @param position The amount of degrees to set the rotaton of the grabber joints to.
  /// @return void
  void RotateGrabberJoints(double position);
  
  /// @brief Deconstructs the ArmController instance.
  ~ArmController();

private:

  /// @brief The robot containing the arm being controlled.
  webots::Robot* robot;
  /// @brief The motors powering the arm.
  webots::Motor* motors[TOTAL_DEVICES];
  webots::PositionSensor* positionSensors[TOTAL_DEVICES];

  /// @brief The velocity at which the arm rotates.
  double velocity;

  /// @brief Convenience method, converts radians to degrees.
  /// @param radians The amount in radians.
  /// @return double The amount in degrees.
  static double convertRadToDeg(double radians);

  /// @brief Convenience method, converts degrees to radians.
  /// @param degrees The amount in degrees.
  /// @return double The amount in radians.
  static double convertDegToRad(double degrees);

};

}

#endif
