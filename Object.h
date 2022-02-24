#ifndef OBJECT_H
#define OBJECT_H
#include "Vector3.h"
#include <vector>

class Object {
    public:
    Vector3* position;
    // Quaternion orientation;
    std::vector<Object*> children;
};

#endif