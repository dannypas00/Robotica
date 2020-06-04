#ifndef TRANSPORT_ROCK_STRATEGY
#define TRANSPORT_ROCK_STRATEGY

#include "..\MeasureWeightController.h"
#include "..\MIStrategy.h"
#include "..\VisionController.h"
#include "..\..\RobotController\RobotController.hpp"

namespace bungie {
class TransportRockStrategy : public MIStrategy {
public:
	MeasureWeightController measureWeightController;
	
	TransportRockStrategy(MeasureWeightController _measureWeightController);
	
	int ExecuteStrategy() override;
};
}

#endif