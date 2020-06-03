#include "GateStrategy.h"

namespace bungie {
int GateStrategy::ExecuteStrategy()
{
	RobotController& controller = RobotController::getInstance();
	if (wait > 0) {
		if (distanceMoved < toMove) {
			//Move 0.45m forwards to reach the rock
			controller.Drive('f', 1.5);
			if (distanceMoved++ >= toMove) wait = 1000;
		}
		else if (rotated == 0 && distanceMoved >= toMove && !hasRotatedFully) {
			controller.Drive('r', 3);
			rotated++;
		}
		else if (rotated >= toRotate) {
			controller.Drive('f', 0);
			hasRotatedFully = true;
			distanceMoved = 0;
			rotated = 0;
		}
		else if (!hasRotatedFully && rotated < toRotate) {
			//Rotate 90 deg to the right
			controller.Drive('r', 3);
			if (rotated++ >= toRotate) wait = 1000;
		}
	} else {
		controller.Drive('f', 0);
		wait++;
	}
	return 0;
}
}