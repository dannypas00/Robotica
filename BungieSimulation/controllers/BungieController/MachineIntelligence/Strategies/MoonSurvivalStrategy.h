#ifndef MOON_SURVIVAL_STRATEGY
#define MOON_SURVIVAL_STRATEGY
#include "..\MIStrategy.h"
#include "..\..\RobotController\RobotController.hpp"

namespace bungie {
class MoonSurvivalStrategy : public MIStrategy {
public:
	int ExecuteStrategy() override;
};
}

#endif