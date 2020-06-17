#ifndef RACE_STRATEGY
#define RACE_STRATEGY

#include "..\MIStrategy.h"
#include "..\..\RobotController\RobotController.hpp"

namespace bungie {
class RaceStrategy : public MIStrategy {
public:
	int ExecuteStrategy() override;

private:
	const double toMove = 450;
	double distanceMoved = 0;
};
}

#endif