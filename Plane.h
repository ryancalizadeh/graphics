#ifndef PLANE_H
#define PLANE_H
#include "Vector3.h"

// Hessian Normal Form
class Plane {
    Vector3* normal;
    double constant;

    Plane();
    Plane(Vector3* normal, double constant);
    double distance(Vector3* position);
};

#endif