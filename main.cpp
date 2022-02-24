#include <iostream>
#include "Vector3.h"

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