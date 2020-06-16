#include "ScanQRCodeStrategy.h"
#include <iostream>

namespace bungie {
ScanQRCodeStrategy::ScanQRCodeStrategy(){
}

int ScanQRCodeStrategy::ExecuteStrategy()
{
	VisionController vision;
	RobotController& controller = RobotController::getInstance();
	std::cout << "[ACTION] Running Vision!" << std::endl;
           
	// Get the QR result from the shown QR code
	// TODO: replace this with result from website / controller
	std::string searchForCard = "SCHOPPEN";
	
	// While attempting to recognize image, keep running this
  	while (!done) {
      	    // Keep the timestep running, otherwise it will freeze the robot
  	    controller.getRobot().step(1);
    	    //Temporary code while vision is not implemented yet
  		switch (stage) {
		case 0:
          
		 	if (searchForCard == "RUITEN") {
				RobotController::getInstance().Rotate(320);
		 	} else if (searchForCard == "SCHOPPEN") {
				RobotController::getInstance().Rotate(110);
				std::cout << "rotate 1!" << std::endl;
		 	} else if (searchForCard == "HARTEN") {
				RobotController::getInstance().Rotate(180);
		 	} else if (searchForCard == "KLAVEREN") {
				RobotController::getInstance().Rotate(260);
		 	}
		 	stage++;
		 	break;
		case 1:
		done = true;
		std::cout << "Done running QR Strategy!" << std::endl;
		break;
		}
            }
            
            return 0;
}
}