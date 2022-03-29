#ifndef CAMERA_H
#define CAMERA_H
#include "Object.h"
#include "Plane.h"
#include <math.h>
#ifndef PI
#define PI 3.14159265
#endif

class Camera: public Object {
    public:
    double near;
    double far;
    double fov;
    double aspect_ratio;
    std::vector<Plane *> planes;

    Camera();
    Camera(
        Vector3* position,
        Quaternion* orientation,
        double near,
        double far,
        double fov,
        double aspect_ratio
    );

    int calculate_planes();
};

Camera::Camera(
    Vector3* position,
    Quaternion* orientation,
    double near,
    double far,
    double fov,
    double aspect_ratio
) : Object(position, orientation) {

    this->near = near;
    this->far = far;
    this->fov = fov * PI / 180;
    this->aspect_ratio = aspect_ratio;

    this->calculate_planes();
}

int Camera::calculate_planes() {
    double half_fov = this->fov / 2;
    double vertical_fov = atan( tan(fov) / aspect_ratio );
    double half_vertical = vertical_fov / 2;
    
    Plane* p1 = new Plane(
        new Vector3(
            sin( half_fov ),
            cos( half_fov ),
            0.0
        ),
        0.0
    );

    Plane* p2 = new Plane(
        new Vector3(
            sin( half_fov ),
            - cos( half_fov ),
            0.0
        ),
        0.0
    );

    Plane* p3 = new Plane(
        new Vector3(
            sin( half_vertical ),
            0.0,
            cos( half_vertical )
        ),
        0.0
    );

    Plane* p4 = new Plane(
        new Vector3(
            sin( half_vertical ),
            0.0,
            - cos( half_vertical )
        ),
        0.0
    );

    Plane* p5 = new Plane( new Vector3(1.0, 0.0, 0.0), -near );
    Plane* p6 = new Plane( new Vector3(-1.0, 0.0, 0.0), far );

    this->planes;
}


#endif