// File:           bungie_controller.cpp
// Date:           10/06/2020
// Description:    Main class for the controller
// Author:         Ghosts
// Modifications:

#include <RobotController/RobotController.hpp>
#include <webots/Keyboard.hpp>

#include <iostream>

#include "MachineIntelligence/MeasureWeightController.h"
#include "MachineIntelligence/Strategies/TransportRockStrategy.h"
#include "MachineIntelligence/NSA.h"

// All the webots classes are defined in the "webots" namespace
using namespace webots;
using namespace bungie;

// This is the main program of the controller.
// It creates an instance of your Robot instance, launches its
// function(s) and destroys it at the end of the execution.
// Note that only one instance of Robot should be created in
// a controller program.
// The arguments of the main function can be specified by the
// "controllerArgs" field of the Robot node

/// @brief The main function of the controller
/// @param int argc The amount of arguments passed to the main function.
/// @param char **argv An array of c-style strings containing the arguments passed to the main function.
/// @return int, 0 if no errors accured.
int main(int argc, char **argv) {
  // get the time step of the current world.
  int timeStep = (int)RobotController::getInstance().getRobot().getBasicTimeStep();
  Keyboard keyboard = Keyboard();
  keyboard.enable(32);
  RobotController::getInstance().setLED(255, 255, 255);
  //NSA nsa = NSA();
  //MeasureWeightController weightController = MeasureWeightController();
  //TransportRockStrategy strategy = TransportRockStrategy(weightController);
  //MoonSurvivalStrategy strategy = MoonSurvivalStrategy();
  //nsa.ExecuteAssignment(strategy);
  
  //RobotController::getInstance().DriveUnits('f', 5);
  RobotController::getInstance().Turn(90);
  
  // Main loop:
  // - perform simulation steps until Webots is stopping the controller
  while (RobotController::getInstance().getRobot().step(timeStep) != -1) {
    //RobotController::getInstance().MoveUnits(1.0, 'f');
    std::cout << RobotController::getInstance().getDistanceFront() << std::endl;
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
    case 'W':
      RobotController::getInstance().MoveArm('u', 12.0);
      RobotController::getInstance().setLED(255, 0, 0);
      break;
    case 'S':
      RobotController::getInstance().MoveArm('d', 12.0);
      RobotController::getInstance().setLED(0, 255, 0, 1);
      break;
    case 'A':
      RobotController::getInstance().MoveArm('l', 12.0);
      RobotController::getInstance().setLED(0, 0, 255, 2);
      break;
    case 'D':
      RobotController::getInstance().MoveArm('r', 12.0);
      RobotController::getInstance().setLED(255, 255, 255);
      break;
    default:
      RobotController::getInstance().Drive('f', 0.0);
      break;
    }
  };
  // Exit and cleanup code.
  
  return 0;
}
