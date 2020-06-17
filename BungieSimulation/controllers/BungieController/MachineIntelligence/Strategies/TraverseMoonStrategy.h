#ifndef TRAVERSE_MOON_STRATEGY
#define TRAVERSE_MOON_STRATEGY
#include "..\MIStrategy.h"
#include "..\..\RobotController\RobotController.hpp"

namespace bungie {
class TraverseMoonStrategy : public MIStrategy {
public:
	int ExecuteStrategy() override;

private:
	const int toMoveUp = 5500;
	const int toMoveOver = 1000;
	int stage = 0;
	int distanceMoved = 0;
	int wait = 0;
};
}

#endif