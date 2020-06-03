#ifndef GATE_STRATEGY
#define GATE_STRATEGY

#include "..\MIStrategy.h"
#include "..\..\RobotController\RobotController.hpp"

namespace bungie {
class GateStrategy : public MIStrategy {
public:
	int ExecuteStrategy() override;

private:
	double rotated = 0;
};
}

#endif