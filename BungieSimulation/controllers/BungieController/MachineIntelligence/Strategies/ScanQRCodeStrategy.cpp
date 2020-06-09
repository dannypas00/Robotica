#include "ScanQRCodeStrategy.h"
#include <iostream>

namespace bungie {
ScanQRCodeStrategy::ScanQRCodeStrategy(){
}

int ScanQRCodeStrategy::ExecuteStrategy()
{
	VisionController vision;
	RobotController& controller = RobotController::getInstance();

	// Get the QR result from the shown QR code
	//auto Result = vision.GetQRResult();
	std::string Result = "SCHOPPEN";

	// Subscribe to the to vision with the result
	// vision.Subscribe(Result);
	// Now we need to look around and find the the correct card
	//const Vector3 visionCard = vision.See(); //Temporarily a vector to substitute the vision object struct
	// Move 1m forwards to reach the correct shape
	//controller.Drive('f', 1.0);
	// Done

		switch (stage) {
		case 0:
		 	if (Result == "RUITEN") {
				RobotController::getInstance().Rotate(320);
		 	} else if (Result == "SCHOPPEN") {
				RobotController::getInstance().Rotate(110);
				std::cout << "dwadawdstrategy!" << std::endl;
		 	} else if (Result == "HARTEN") {
				RobotController::getInstance().Rotate(180);
		 	} else if (Result == "KLAVEREN") {
				RobotController::getInstance().Rotate(260);
		 	}
		 	break;
		case 1:
			//controller.DriveUnits('f', 0.5, 8);
		 	break;
		}
		return 0;
}

// Check if the gotten result is one that we expect to get, if false we retry the scan
// TODO: need vision and controller to make full implementation
bool ScanQRCodeStrategy::Exists(std::string& Result)
{
	std::string words[4];
	words[0] = "HARTEN";
	words[1] = "KLAVEREN";
	words[2] = "SCHOPPEN";
	words[3] = "RUITEN";

	for (size_t n = 0; words && (n < words->size()); ++n)
	{
		if (words[n] == Result)
			return true;
	}

	return false;
}
}