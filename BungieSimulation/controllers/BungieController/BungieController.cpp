// File:           bungie_controller.cpp
// Date:           10/06/2020
// Description:    Main class for the controller
// Author:         Ghosts
// Modifications:

#include <RobotController/RobotController.hpp>
#include <webots/Keyboard.hpp>

#include <iostream>

#include "MachineIntelligence/NSA.h"
#include "MachineIntelligence/MeasureWeightController.h"
#include "MachineIntelligence/Strategies/TransportRockStrategy.h"
#include "MachineIntelligence/Strategies/GateStrategy.h"
#include "MachineIntelligence/Strategies/MoonSurvivalStrategy.h"
#include "MachineIntelligence/Strategies/ScanQRCodeStrategy.h"
#include "MachineIntelligence/Strategies/DynamicDanceStrategy.h"
#include "MachineIntelligence/Strategies/TraverseMoonStrategy.h"
#include "MachineIntelligence/Strategies/RaceStrategy.h"

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
  // int timeStep = (int)RobotController::getInstance().getRobot().getBasicTimeStep();
  bool executingStrategy = false;
  bool manualControlls = true;

  // get the time step of the current world.
  int timeStep = (int)RobotController::getInstance().getRobot().getBasicTimeStep();
  Keyboard keyboard = Keyboard();
  keyboard.enable(32);
  RobotController::getInstance().setLED(255, 255, 255);
  
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
  
  while (RobotController::getInstance().getRobot().step(timeStep) != -1) {
    // Get pressed key, -1 = none pressed
    int pressed_key = keyboard.getKey();
    // std::cout << RobotController::getInstance().getDistanceFront() << std::endl;
    // Data for telemetry site
    // std::cout << "[DATA] [POS] position!" << std::endl;
    // std::cout << "[DATA] [ROT] rotation!" << std::endl;
    
    // If the user chooses to run an strategy we stop all manual inputs untill its done
    // Afterwards it should automatically turn "manualControlls" to true, but for now you
    // Have to press "R" to regain manual controll untill we can fix this
    switch(pressed_key){
      case Keyboard::UP:
        if (manualControlls) {
          RobotController::getInstance().Drive('f', 1.0);
        }
        break;
      case Keyboard::DOWN:
        if (manualControlls) {
          RobotController::getInstance().Drive('b', 1.0);
        }
        break;
      case Keyboard::LEFT:
        if (manualControlls) {
          RobotController::getInstance().Drive('l', 1.0);
        }
        break;
      case Keyboard::RIGHT:
        if (manualControlls) {
          RobotController::getInstance().Drive('r', 1.0);
        }
        break;    
      case 'G':
        if (manualControlls) 
        {
          RobotController::getInstance().Grab();          
        }    
        break;
      case '1': // base turn left
        if (manualControlls) 
        {
          RobotController::getInstance().BaseTurnLeft();          
        }    
        break;
      case '2': //base turn right
        if (manualControlls) 
        {
          RobotController::getInstance().BaseTurnRight();         
        }    
        break;
      case '3': // shoulder turn left
        if (manualControlls) 
        {
          RobotController::getInstance().ShoulderTurnLeft();          
        }    
        break;
      case '4': // shoulder turn right
        if (manualControlls) 
        {
          RobotController::getInstance().ShoulderTurnRight();          
        }    
        break;
      case '5': // elbow turn left
        if (manualControlls) 
        {
          RobotController::getInstance().ElbowTurnLeft();          
        }    
        break;
      case '6': // elbow turn right
        if (manualControlls) 
        {
          RobotController::getInstance().ElbowTurnRight();          
        }    
        break;
      case '7': // wrist turn left
        if (manualControlls) 
        {
          RobotController::getInstance().WristTurnLeft();          
        }    
        break;
      case '8': // wrist turn right
        if (manualControlls) 
        {
          RobotController::getInstance().WristTurnRight();          
        }    
        break;
      case 'W':
        if (!executingStrategy)
        {
          double weight = RobotController::getInstance().getWeightOfStoredObject();
          
          std::cout << "[ACTION] weight of object: " << weight << std::endl;
        } 
        break;
      case 'R':
        if (executingStrategy) {
          std::cout << "[ACTION] Stopped running strategy!" << std::endl;
          std::cout << "[DATA] [MODE] Manual!" << std::endl;
          executingStrategy = false;
          manualControlls = true;
        }
        break;
      case 'U':
        if (!executingStrategy) {
          executingStrategy = true;
          manualControlls = false;
          RobotController::getInstance().Turn(90);
        }
        break;
      case 'I':
        if (!executingStrategy) {
          executingStrategy = true;
          manualControlls = false;
          nsa.ExecuteAssignment(ms_strategy);
        }
        break;
      case 'O':
        if (!executingStrategy) {
          executingStrategy = true;
          manualControlls = false;        
          // nsa.ExecuteAssignment(tr_strategy);
        }
        break;
      case 'H':
        if (!executingStrategy) {
          executingStrategy = true;
          manualControlls = false;
          nsa.ExecuteAssignment(gt_strategy);
        }
        break;
      case 'J':
        if (!executingStrategy) {
          executingStrategy = true;
          manualControlls = false;
          nsa.ExecuteAssignment(dance_strategy);
        }
        break;
      case 'K':
        if (!executingStrategy) {
          executingStrategy = true;
          manualControlls = false;
          nsa.ExecuteAssignment(traverse_moon);
        }
        break;
      case 'L':
        if (!executingStrategy) {
          executingStrategy = true;
          manualControlls = false;
          nsa.ExecuteAssignment(qr_strategy);
        }
        break;
      default:
        if (manualControlls && !executingStrategy) {
          // TODO: werkt niet met strategies, moven pleurt uit elkaar
          RobotController::getInstance().Drive('f', 0.0);
        }
        break;
      }
  };
  // Exit and cleanup code.
  return 0;
}
