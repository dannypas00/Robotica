#ifndef DYNAMIC_DANCE_STRATEGY
#define DYNAMIC_DANCE_STRATEGY
#include "..\MIStrategy.h"
#include "..\VisionController.h"
#include "..\..\RobotController\RobotController.hpp"

namespace bungie {
class DynamicDanceStrategy : public MIStrategy {
public:
	DynamicDanceStrategy();

	int ExecuteStrategy() override;
};
}

#endif