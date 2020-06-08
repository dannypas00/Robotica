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
	std::string Result = "KLAVEREN";

	//if (Exists(Result))
	//{
		// Subscribe to the to vision with the result
		vision.Subscribe(Result);
		// Now we need to look around and find the the correct card
		//const Vector3 visionCard = vision.See(); //Temporarily a vector to substitute the vision object struct
		// Move 1m forwards to reach the correct shape
		//controller.Drive('f', 1.0);
		// Done

		// switch (stage) {
		// 	case 0:
		// 		controller.Drive('r', 10);
		// 		rotated++;
		// 		if (rotated >= toRotate) {
		// 			stage++;
		// 			controller.Drive('r', 0);
		// 		}
		// 		break;
		// 	case 1:
		// 		if (Result == "KLAVEREN") {
		// 			toRotate = 1491;
		// 		} else if (Result == "HARTEN") {
		// 			toRotate = 0;
		// 		} else if (Result == "SCHOPPEN") {
		// 			toRotate = 467;
		// 		} else if (Result == "RUITEN") {
		// 			toRotate = 994;
		// 		}
		// 		stage++;
		// 		rotated = 0;
		// 		break;
		// 	case 2:
		// 		controller.Drive('r', 3);
		// 		if (rotated >= toRotate) {
		// 			stage++;
		// 		}
		// 		break;
		// }
		// return 0;
	//} else
	//{
		// Do something when the result isn't correct
	//	return 1;
	//}

/* 	// Check if Result equals what we expect to get, to check if the gotten qr code result is correct
	if (Exists(Result))
	{
		// Subscribe to the to vision with the result
		vision.Subscribe(Result);
		// Now we need to look around and find the the correct card
		const Vector3 visionCard = vision.See(); //Temporarily a vector to substitute the vision object struct
		// Move 1m forwards to reach the correct shape
		controller.Drive('f', 1.0);
		// Done
		return 0;
	} else
	{
		// Do something when the result isn't correct
		return 1;
	} */
	return 1;
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