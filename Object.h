#ifndef OBJECT_H
#define OBJECT_H
#include "Vector3.h"
#include "Quaternion.h"
#include <vector>

class Object {
    public:
    Vector3* position;
    Quaternion orientation;

    std::vector<Object*> children;
    std::vector<Vector3*> points;
    std::vector<std::vector<int>> edgeList;
    std::vector<std::vector<int>> triangles;
};

#endif