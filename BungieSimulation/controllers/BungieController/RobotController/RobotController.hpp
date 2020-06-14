#ifndef BUNGIE_CONTROLLER_HEADER
#define BUNGIE_CONTROLLER_HEADER

#include <webots/Robot.hpp>
#include <webots/Motor.hpp>
#include <webots/TouchSensor.hpp>
#include <webots/DistanceSensor.hpp>
#include <webots/Camera.hpp>
#include <webots/Keyboard.hpp>
#include <webots/LED.hpp>

#include "WheelController.hpp"
#include "ArmController.hpp"

#include <cmath>

#define TIME_STEP 64

namespace bungie {

class RobotController {

public:
  /// @brief Gives the instance of the singleton controller class.
  /// @return RobotController& The instance of itself.
  static RobotController& getInstance();
  
  /// @brief Order robot to drive in certain direction at given speed.
  /// @param char direction The direction given as the characters: 'l' for left, 'r' for right, 'f'for forward and 'b' for backwards.
  /// @param double velocity The velocity stands for radians per second the wheels should rotate.
  /// @return void
  void Drive(char direction, double velocity);

  /// @brief Order robot to drive in certain direction until given distance is reached.
  /// @param char direction The direction given as the characters: 'l' for left, 'r' for right, 'f'for forward and 'b' for backwards.
  /// @param double distance The amount of units the robot will move in the given direction.
  /// @return void
  void DriveUnits(char direction, double distance);

  /// @brief Order robot to turn to a certain angle.
  /// @param double deg The number of degrees the robot should turn.
  /// @return void
  void Turn(double deg);

  /// @brief Order robotarm to move in certain direction.
  /// @param char direction The direction given as the characters: 'l' for left, 'r' for right, 'f'for forward and 'b' for backwards.
  /// @param double rotation The rotation stands for the amount of degrees the joints in the arm should rotate.
  /// @return void
  void MoveArm(char direction, double rotation);
  
  /// @brief Opens the grabber of the robot arm.
  /// @return void
  void OpenGrabber();
  
  /// @brief Closes the grabber of the robot arm.
  /// @return void
  void CloseGrabber();

  /// @brief Get the image of the camera at executed tick.
  /// @return const unsigned char* Camera image given by the camera on the robot.
  const unsigned char* getCamera() { return camera->getImage(); }

  /// @brief Get weight of the item in the storagebox on the robot.
  /// @return double Weight of item calcutated from gigen force by a force-3D sensor.
  double getWeightOfStoredObject();
  
  /// @brief Get distance meassured with the front distance sensor in meters.
  /// @return double Distance returned by the front sensor.
  double getDistanceFront();
  
  /// @brief Get distance meassured with the back distance sensor in meters.
  /// @return double Distance returned by the back sensor.
  double getDistanceBack();
  
  /// @brief Set the LED's of the robot on or off with given color.
  /// @param int r The red value for the color from 0 to 255.
  /// @param int g The green value for the color from 0 to 255.
  /// @param int b The blue value for the color from 0 to 255.
  /// @param int number To switch between powering all LED's = 0, the left LED's = 1 and right LED's = 2.
  /// @return void
  void setLED(int r, int g, int b, int number = 0);

  /// @brief Get the WeBots Robot object.
  /// @return webots::Robot& Reference to the WeBots Robot object.
  webots::Robot& getRobot() { return *robot; }

  /// @brief Destructor deletes all object made under it's scope.
  ~RobotController();

private:
  /// @brief The WeBots Robot instance of the controller.
  webots::Robot* robot;

  /// @brief The instance of the WheelController.
  WheelController* wheel_controller;
  
  /// @brief The instance of the ArmController.
  ArmController* arm_controller;
  
  /// @brief The instance of the WeBots Camera.
  webots::Camera* camera;
  
  /// @brief The instance of the WeBots TouchSensor.
  webots::TouchSensor* touch_sensor;
  
  /// @brief The instance of the WeBots DistanceSensor.
  webots::DistanceSensor* distance_sensor_front;
  
  /// @brief The instance of the WeBots DistanceSensor.
  webots::DistanceSensor* distance_sensor_back; 
  
  /// @brief The instance of the WeBots LED.
  webots::LED* led_left;
  
  /// @brief The instance of the WeBots LED.
  webots::LED* led_right;
  
  /// @brief The private constructor of the singleton RobotController.
  RobotController();
  
  /// @brief Initializes all the sensors of the robot, called in constructor.
  /// @return void
  void initSensors();
  
  /// @brief The default private constructor of the RobotController.
  /// @param const RobotController& Reference of the RobotController type.
  RobotController(const RobotController&) = default;

  /// @brief The default private constructor of the RobotController.
  /// @param RobotController&& Reference of the RobotController type.
  RobotController(RobotController&&) = default;

};

}
#endif
