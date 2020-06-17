#include "RobotController.hpp"

using namespace std;

namespace bungie {

RobotController& RobotController::getInstance(){
   static RobotController instance;
   return instance;
}
  
RobotController::RobotController(){
  robot = new webots::Robot();
  wheel_controller = new WheelController(robot);
  arm_controller = new ArmController(robot, 1.0);
  
  this->initSensors();
}

void RobotController::initSensors(){
  camera = robot->getCamera("front_CAM");
  camera->enable(TIME_STEP);
  
  touch_sensor = robot->getTouchSensor("touch_sensor");
  touch_sensor->enable(TIME_STEP);
  
  distance_sensor_front = robot->getDistanceSensor("distance_sensor_front");
  distance_sensor_front->enable(TIME_STEP);
  
  distance_sensor_back = robot->getDistanceSensor("distance_sensor_back");
  distance_sensor_back->enable(TIME_STEP);
  
  led_left = robot->getLED("LED_left");
  led_right = robot->getLED("LED_right");
}

void RobotController::Drive(char direction, double velocity){
  wheel_controller->PowerMotors(direction, velocity);
}

void RobotController::DriveUnits(char direction, double distance) {
  if (direction == 'b')
    distance *= -1;
  wheel_controller->SetMotorsPosition(distance);
}

void RobotController::Turn(double deg) {
  //Radial of 1.570 == 90 degrees
  //1.9145945 radials per unit rotated
  //0.82 units ~= 90 degrees
  //~0.0091111 units per degree
  wheel_controller->SetRotation(deg * 0.0091111);
}

void RobotController::MoveArm(char direction, double rotation){
  switch (direction) {
  case 'u':
    arm_controller->Rotate(+rotation);
    break;

  case 'd':
    arm_controller->Rotate(-rotation);
    break;

  case 'l':
    arm_controller->Rotate(ArmController::ROTATABLE_BASE, +rotation);
    break;

  case 'r':
    arm_controller->Rotate(ArmController::ROTATABLE_BASE, -rotation);
    break;
  }
}

void RobotController::OpenGrabber(){
  arm_controller->RotateGrabberJoints(60);
}

void RobotController::CloseGrabber(){
  arm_controller->RotateGrabberJoints(0);
}

double RobotController::getWeightOfStoredObject(){
  const double* force = touch_sensor->getValues();
  return (sqrt((force[0]*force[0])+(force[1]*force[1])+(force[2]*force[2]))/3.73);
}

double RobotController::getDistanceFront(){
  return distance_sensor_front->getValue();
}

double RobotController::getDistanceBack(){
  return distance_sensor_back->getValue();
}

void RobotController::setLED(int r, int g, int b, int number) {
  int color = ((( r << 8) | g) <<8) | b;
  switch(number){
    case 0:
      led_left->set(color);
      led_right->set(color);
      break;
    case 1:
      led_left->set(color);
      led_right->set(0);
      break;
    case 2:
      led_left->set(0);
      led_right->set(color);
      break;
  }
}

RobotController::~RobotController(){
  delete robot;
  delete wheel_controller;
  delete arm_controller;
  delete camera;
  delete touch_sensor;
}

}