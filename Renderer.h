#ifndef RENDERER_H
#define RENDERER_H
#include "Object.h"
#include "Camera.h"

class Renderer {
    Renderer(Object* scene, Camera* camera);

    private:
    Object* scene;
    Object* camera;

};

#endif