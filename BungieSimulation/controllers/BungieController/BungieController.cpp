// File:          bungie_controller.cpp
// Date:
// Description:
// Author:
// Modifications:

// You may need to add webots include files such as
// <webots/DistanceSensor.hpp>, <webots/Motor.hpp>, etc.
// and/or to add some other includes
#include <RobotController/RobotController.hpp>
#include <webots/Keyboard.hpp>
//#include "MachineIntelligence/MeasureWeightController.h"
//#include "MachineIntelligence/Strategies/TransportRockStrategy.h"
//#include "MachineIntelligence/NSA.h"

// All the webots classes are defined in the "webots" namespace
using namespace webots;
using namespace bungie;

// This is the main program of your controller.
// It creates an instance of your Robot instance, launches its
// function(s) and destroys it at the end of the execution.
// Note that only one instance of Robot should be created in
// a controller program.
// The arguments of the main function can be specified by the
// "controllerArgs" field of the Robot node
int main(int argc, char **argv) {
  // get the time step of the current world.
  int timeStep = (int)RobotController::getInstance().getRobot().getBasicTimeStep();
  // You should insert a getDevice-like function in order to get the
  // instance of a device of the robot. Something like:
  //  Motor *motor = robot->getMotor("motorname");
  //  DistanceSensor *ds = robot->getDistanceSensor("dsname");
  //  ds->enable(timeStep);
  Keyboard keyboard = Keyboard();
  keyboard.enable(32);

    //NSA nsa = NSA();
    //MeasureWeightController weightController = MeasureWeightController();
    //TransportRockStrategy strategy = TransportRockStrategy(weightController);
    //MoonSurvivalStrategy strategy = MoonSurvivalStrategy();
    //nsa.ExecuteAssignment(strategy);
    
    //RobotController::getInstance().DriveUnits('f', 5);
    RobotController::getInstance().Rotate(90);
  
  // Main loop:
  // - perform simulation steps until Webots is stopping the controller
  while (RobotController::getInstance().getRobot().step(timeStep) != -1) {
    // Read the sensors:
<<<<<<< HEAD
    //RobotController::getInstance().MoveUnits(1.0, 'f');
=======
>>>>>>> 76c29f908538a372027564c3c7b8f882f165e5a9
    // Enter here functions to read sensor data, like:
    //  double val = ds->getValue();
    int pressed_key = keyboard.getKey();
    switch(pressed_key){
    case Keyboard::UP:
      RobotController::getInstance().Drive('f', 1.0);
      break;
    case Keyboard::DOWN:
      RobotController::getInstance().Drive('b', 1.0);
      break;
    case Keyboard::LEFT:
      RobotController::getInstance().Drive('l', 1.0);
      break;
    case Keyboard::RIGHT:
      RobotController::getInstance().Drive('r', 1.0);
      break;
      /*case 'W':
      RobotController::getInstance().MoveArm('u', 1.0);
      break;
      case 'S':
      RobotController::getInstance().MoveArm('d', 1.0);
      break;
      case 'A':
      RobotController::getInstance().MoveArm('l', 1.0);
      break;
      case 'D':
      RobotController::getInstance().MoveArm('r', 1.0);
      break;*/
    default:
      //RobotController::getInstance().Drive('f', 0.0);
      //RobotController::getInstance().MoveArm('l', 0.0);
      //RobotController::getInstance().MoveArm('u', 0.0);
      break;
    }
    
    // Process sensor data here.

    // Enter here functions to send actuator commands, like:
    //  motor->setPosition(10.0);
  };

  // Enter here exit cleanup code.
  
  return 0;
}
