#ifndef PLANT_FLAG_STRATEGY
#define PLANT_FLAG_STRATEGY
#include "..\MIStrategy.h"
#include "..\..\RobotController\RobotController.hpp"

namespace bungie {
class PlantFlagStrategy : public MIStrategy {
public:
	PlantFlagStrategy();

	int ExecuteStrategy() override;
};
}

#endif