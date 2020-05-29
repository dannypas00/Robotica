#pragma once
#include "MIStrategy.h"
#include "RobotController.h"

class ScanQRCodeStrategy : public MIStrategy {
public:
	ScanQRCodeStrategy();

	bool Exists(std::string& Result);
	int ExecuteStrategy() override;
};

