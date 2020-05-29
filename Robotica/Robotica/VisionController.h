#pragma once
#include <string>

#include "Vector3.h"

class VisionController
{
public:
	void Subscribe(std::string object);
	Vector3 See(); //Temporary function to substitute observer signal
};

