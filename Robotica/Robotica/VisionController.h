#pragma once
#include <string>

#include "Vector3.h"

class VisionController
{
public:
	void Subscribe(std::string object);
	int See(); //Temporary function to substitute observer signal
};

