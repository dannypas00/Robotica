#ifndef SCAN_QR_CODE_STRATEGY
#define SCAN_QR_CODE_STRATEGY
#include "..\MIStrategy.h"
#include "..\VisionController.h"
#include "..\..\RobotController\RobotController.hpp"

namespace bungie {
class ScanQRCodeStrategy : public MIStrategy {
public:
	ScanQRCodeStrategy();

	bool Exists(std::string& Result);
	int ExecuteStrategy() override;
private:
	int stage = 0;
	int toRotate = 1868;
	int rotated = 0;
            bool done = false;
};
}

#endif