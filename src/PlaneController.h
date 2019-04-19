//
// Created by filip on 19.04.19.
//

#ifndef FLIGHTSIMULATOR_PLANECONTROLLER_H
#define FLIGHTSIMULATOR_PLANECONTROLLER_H

#include <memory>
#include "Plane.h"
#include "Models/PhysicalModel.h"

class PlaneController {
public:

    PlaneController(Plane *p,PhysicalModel *m): model(m), plane(p){};
    void simulate();
    void waitForUsersAction();


private:
    std::unique_ptr<Plane> plane;
    std::unique_ptr<PhysicalModel> model;
    const int FPS = 30;

    void moveAilerons(double value);
    void moveElevators(double value);
    void moveRudder(double value);
    void throttle(double value);
};


#endif //FLIGHTSIMULATOR_PLANECONTROLLER_H
