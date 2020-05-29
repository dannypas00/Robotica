#ifndef NSA_H
#define NSA_H

#include "MIStrategy.h"

namespace bungie {
class NSA {
public:
    void DisplayWeight(float weight);
    int ExecuteAssignment(MIStrategy& assignment);
private:
    int display;
};
}

#endif