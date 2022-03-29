#ifndef PLANE_H
#define PLANE_H
#include "Vector3.h"

// Hessian Normal Form
class Plane {
    public:
    Vector3* normal;
    double constant;

    Plane();
    Plane(Vector3* normal, double constant);
    double distance(Vector3* position);
};

Plane::Plane() {
    this->normal = new Vector3(1, 0, 0);
    constant = 0;
}

Plane::Plane(Vector3* normal, double constant) {
    this->normal = normal;
    this->constant = constant;
}

#endif