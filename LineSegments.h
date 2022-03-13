#ifndef LINESEGMENTS_H
#define LINESEGMENTS_H
#include "Vector3.h"
#include "Object.h"
#include <vector>

class LineSegments {
    public:
    std::vector<Vector3*> points;   // points are connected
                                    // IN ORDER

    LineSegments();
    LineSegments(Vector3* p1, Vector3* p2);
    LineSegments(std::vector<Vector3*> _points);

    int fromParameterization(
        Vector3* (*pFunc)(double),
        double a,
        double b,
        int n
    );
    Object* toObject();
    double length();
};

LineSegments::LineSegments() {
    points = {};
}

LineSegments::LineSegments(Vector3* p1, Vector3* p2) {
    points = {};
    points.push_back(p1);
    points.push_back(p2);
}

LineSegments::LineSegments(std::vector<Vector3*> _points) {
    points = _points;
}

int LineSegments::fromParameterization(
    Vector3* (*pFunc)(double),
    double a,
    double b,
    int n
) {
    double t;
    if (b <= a || n <= 1) {
        return 0;
    }

    double dt = (b - a) / (n - 1);
    for (int i = 0; i < n; i++) {
        t = a + i*dt;
        points.push_back(pFunc(t));
    }
}

Object* LineSegments::toObject() {
    Object* obj = new Object();
    obj->points = this->points; // this is definitely bad
    
    for (int i = 0; i < this->points.size() - 1; i++) {
        obj->edgeList.push_back({i, i+1});
    }
    return obj;
}

double LineSegments::length() {
    double length = 0;
    for (int i = 0; i< this->points.size() - 1; i++) {
        length += this->points[i]->dist(this->points[i+1]);
    }
}

#endif