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
#include "MachineIntelligence/MeasureWeightController.h"
#include "MachineIntelligence/Strategies/TransportRockStrategy.h"
#include "MachineIntelligence/NSA.h"
#include "MachineIntelligence/Strategies/GateStrategy.h"
#include "MachineIntelligence/Strategies/MoonSurvivalStrategy.h"
#include "MachineIntelligence/Strategies/ScanQRCodeStrategy.h"
#include "MachineIntelligence/Strategies/DynamicDanceStrategy.h"
#include "MachineIntelligence/Strategies/TraverseMoonStrategy.h"
#include "MachineIntelligence/Strategies/RaceStrategy.h"
// #include <webots/supervisor.hpp>

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
  bool executingStrategy = false;
  // You should insert a getDevice-like function in order to get the
  // instance of a device of the robot. Something like:
  //  Motor *motor = robot->getMotor("motorname");
  //  DistanceSensor *ds = robot->getDistanceSensor("dsname");
  //  ds->enable(timeStep);
  Keyboard keyboard = Keyboard();
  keyboard.enable(32);
  
  // webots::Supervisor *supervisor = new webots::Supervisor();

  // do this once only
  // webots::Node *robot_node = supervisor->getFromDef("BUNGIE_ROVER");
  // webots::Field *trans_field = robot_node->getField("rotation");
  // const double *values = trans_field->getSFVec3f();
      // std::cout << "MY_ROBOT is at position: " << values[0] << ' '
              // << values[1] << ' ' << values[2] << std::endl;
  
  // Initiate NSA()
  NSA nsa = NSA();
  
  // All strategies and required classes
  MeasureWeightController weightController = MeasureWeightController();
  TransportRockStrategy tr_strategy = TransportRockStrategy(weightController);
  MoonSurvivalStrategy ms_strategy = MoonSurvivalStrategy();
  DynamicDanceStrategy dance_strategy = DynamicDanceStrategy();
  TraverseMoonStrategy traverse_moon = TraverseMoonStrategy();
  ScanQRCodeStrategy qr_strategy = ScanQRCodeStrategy();
  GateStrategy gt_strategy = GateStrategy();
  
  // Main loop:
  // - perform simulation steps until Webots is stopping the controller
  
  // Commands: 
  // - U: Navigate Maze
  // - I: Moon Survival
  // - O: TransportRock
  // - H: Poortje
  // - J: Dance
  // - K: TraverseMoon
  // - L: Vision / QR
  
  while (RobotController::getInstance().getRobot().step(16) != -1) {
    // Get pressed key, -1 = none pressed
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
      case 'R':
        std::cout << "Stopped running strategy!" << std::endl;
        executingStrategy = false;
        break;
      case 'U':
        if (!executingStrategy) {
          executingStrategy = true;
          RobotController::getInstance().Rotate(90);
        }
        break;
      case 'I':
        if (!executingStrategy) {
          executingStrategy = true;
          nsa.ExecuteAssignment(ms_strategy);
        }
        break;
      case 'O':
        if (!executingStrategy) {
          executingStrategy = true;        
          // nsa.ExecuteAssignment(tr_strategy);
        }
        break;
      case 'H':
        if (!executingStrategy) {
          executingStrategy = true;
          nsa.ExecuteAssignment(gt_strategy);
        }
        break;
      case 'J':
        if (!executingStrategy) {
          executingStrategy = true;
          nsa.ExecuteAssignment(dance_strategy);
        }
        break;
      case 'K':
        if (!executingStrategy) {
          executingStrategy = true;
          nsa.ExecuteAssignment(traverse_moon);
        }
        break;
      case 'L':
        if (!executingStrategy) {
          executingStrategy = true;
          nsa.ExecuteAssignment(qr_strategy);
        }
        break;
      default:
        //TODO: werkt niet met strategies, omdat het moven asyncrhoon gaat glitched rotate
        // If not exexcuting a strategy, stop when no buttons pressed
        // if (!executingStrategy) {
                // RobotController::getInstance().Drive('f', 0.0);
        // }
        //RobotController::getInstance().MoveArm('l', 0.0);
        //RobotController::getInstance().MoveArm('u', 0.0);
        break;
      }
  };

  // Enter here exit cleanup code.
  
  return 0;
}
