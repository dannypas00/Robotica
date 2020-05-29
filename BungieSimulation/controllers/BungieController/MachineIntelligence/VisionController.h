#ifndef VISION_CONTROLLER
#define VISION_CONTROLLER
#include <string>

#include "Vector3.h"

namespace bungie {
class VisionController
{
public:
	void Subscribe(std::string object);
	Vector3 See(); //Temporary function to substitute observer signal
};
}

#endif