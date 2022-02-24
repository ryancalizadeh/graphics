#ifndef SPHERE_H
#define SPHERE_H
#include "Vector3.h"

class Sphere {
    Vector3* position;
    double radius;

    Sphere();
    Sphere(Vector3* _position, double _radius);
};

Sphere::Sphere() {
    this->position = new Vector3();
    this->radius = 1.0;
}

Sphere::Sphere(Vector3* _position, double _radius) {
    this->position = _position;
    this->radius = _radius;
}

#endif