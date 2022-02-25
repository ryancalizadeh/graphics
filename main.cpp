#include <iostream>
#include "Vector3.h"

#ifdef NANOVG_GLEW
#  include <GL/glew.h>
#endif
#define GLFW_INCLUDE_GLEXT
#include <GLFW/glfw3.h>
#include "nanovg-master/src/nanovg.h"
#define NANOVG_GL2_IMPLEMENTATION
#include "nanovg-master/src/nanovg_gl.h"
#include "nanovg-master/example/demo.h"

int main() {
    Vector3 *a = new Vector3(1.0, 2.0, 3.7);
    Vector3 *b = new Vector3(2.0, -0.2, 8.0);
    Vector3 *c = a->crossVector(b);
    a->add(b);
    double scalar = a->dot(c);

    std::cout << c->x << ", " << c->y << ", " << c->z << std::endl;
    std::cout << scalar << std::endl;

    delete a;
    delete b;

    return 0;
}