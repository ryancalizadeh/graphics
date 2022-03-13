#ifndef CAMERA_H
#define CAMERA_H
#include <Object.h>

class Camera: public Object {
    public:
    double close;
    double far;
    double fov;
};


#endif