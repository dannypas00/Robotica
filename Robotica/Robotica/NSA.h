#pragma once

#include "MIStrategy.h"
#include "TransportRockStrategy.h"


static class NSA {
public:
    static void main();
    void DisplayWeight(float weight);
    int ExecuteAssignment(TransportRockStrategy assignment);
private:
    int display;
};
