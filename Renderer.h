#ifndef RENDERER_H
#define RENDERER_H
#include "Object.h"
#include "Camera.h"
#include "Vector3.h"
#include "nanovg-master/src/nanovg.h"


class Renderer {
    Renderer(Object* scene, Camera* camera);

    private:
    Object* scene;
    Object* camera;
    NVGcontext* vg;
    void drawTriangle(Vector3* a, Vector3* b, Vector3* c);
    void render();
};

void Renderer::drawTriangle(Vector3* a, Vector3* b, Vector3* c) {
    nvgBeginPath(this->vg);

    nvgMoveTo(vg, a->x, a->y);
    nvgLineTo(vg, b->x, b->y);
    nvgLineTo(vg, c->x, c->y);

    nvgFill(vg);
}

void Renderer::render() {
    
}

#endif