#include "MoonSurvivalStrategy.h"
#include <iostream>

namespace bungie {
int MoonSurvivalStrategy::ExecuteStrategy()
{
	RobotController& controller = RobotController::getInstance();
	if (wait <= 0) {
		switch (stage) {
			case 0:
				if (distanceMoved < toMoveUp) {
					controller.Drive('f', 3);
					if (distanceMoved % 10 == 0) wait = 10;
					if (distanceMoved++ >= toMoveUp) wait = 1000;
				} else {
					controller.Drive('f', 0);
					stage++;
					distanceMoved = 0;
				}
			case 1:
				if (distanceMoved < toMoveOver) {
					controller.Drive('f', 5);
					if (distanceMoved % 10 == 0) wait = 10;
					if (distanceMoved++ >= toMoveOver) wait = 1000;
				} else {
					controller.Drive('f', 0);
					stage++;
					distanceMoved = 0;
				}
		}
	} else {
		//controller.Drive('f', 0);
		wait--;
	}
	return 0;
}
}