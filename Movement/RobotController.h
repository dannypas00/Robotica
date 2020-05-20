#ifndef ROBOTICA_MOVEMENT_H
#define ROBOTICA_MOVEMENT_H

#include "../Vector3.cpp"


static class RobotController {
private:
    RobotController instance;

public:
    RobotController GetInstance();
    void Drive(Char direction);
    void UseBreaks(double strength);
    void GatherObject(bool liquid, double sensitivity, Vector3 object_position);
    void Dance();
};


#endif //ROBOTICA_MOVEMENT_H
