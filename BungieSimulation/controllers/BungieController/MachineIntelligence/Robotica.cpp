#include <iostream>
#include "NSA.h"
#include "Strategies/TransportRockStrategy.h"
#include "Strategies/MoonSurvivalStrategy.h"

namespace bungie {
int main2()
{
    std::cout << "Hello, world!";
    NSA nsa = NSA();
    MeasureWeightController weightController = MeasureWeightController();
    TransportRockStrategy strategy = TransportRockStrategy(weightController);
    //MoonSurvivalStrategy strategy = MoonSurvivalStrategy();
    nsa.ExecuteAssignment(strategy);
    return 0;   
}
}