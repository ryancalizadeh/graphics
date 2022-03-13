#ifndef VECTOR3_H
#define VECTOR3_H
#include <cmath>

class Vector3 {
    public:
    double x, y, z;

    // Constructors
    Vector3();
    Vector3(double x, double y, double z);
    Vector3* normalizeVector();
    Vector3* clone();
    Vector3* crossVector(Vector3 *other);
    Vector3* addVector(Vector3 *other);
    Vector3* subVector(Vector3 *other);
    Vector3* multScalarVector(double scalar);
    Vector3* projVector(Vector3 *other);

    // Modifiers
    void add(Vector3 *other);
    void multScalar(double scalar);
    void normalize();

    // Getters
    double length();
    double lengthSq();
    double dot(Vector3 *other);
    double scalarProj(Vector3 *other);
    double dist(Vector3 *other);
};

Vector3::Vector3() {
    x = 0.0;
    y = 0.0;
    z = 0.0;
}

Vector3::Vector3(double _x, double _y, double _z) {
    x = _x;
    y = _y;
    z = _z;
}

void Vector3::add(Vector3 *other) {
    this->x += other->x;
    this->y += other->y;
    this->z += other->z;
}

Vector3* Vector3::addVector(Vector3 *other) {
    return new Vector3(
        this->x + other->x,
        this->y + other->y,
        this->z + other->z
    );
}

Vector3* Vector3::subVector(Vector3 *other) {
    return new Vector3(
        this->x - other->x,
        this->y - other->y,
        this->z - other->z
    );
}

double Vector3::dist(Vector3* other) {
    std::sqrt(
        std::pow(this->x - other->x, 2) +
        std::pow(this->y - other->y, 2) +
        std::pow(this->z - other->z, 2)
    );
}

double Vector3::dot(Vector3 *other) {
    return  this->x * other->x +
            this->y * other->y +
            this->z * other->z;
}

Vector3* Vector3::crossVector(Vector3 *other) {
    return new Vector3(
        this->y * other->z - this->z * other->y,
        this->z * other->x - this->x * other->z,
        this->x * other->y - this->y * other->x
    );
}

void Vector3::normalize() {
    double len = this->length();
    this->multScalar(1 / len);
}

Vector3* Vector3::normalizeVector() {
    double len = this->length();
    return this->multScalarVector(1 / len);
}

Vector3* Vector3::clone() {
    return new Vector3(this->x, this->y, this->z);
}

double Vector3::length() {
    return std::sqrt(this->lengthSq());
}

double Vector3::lengthSq() {
    return  this->x * this->x +
            this->y * this->y +
            this->z * this->z;
}

void Vector3::multScalar(double scalar) {
    this->x *= scalar;
    this->y *= scalar;
    this->z *= scalar;
}

Vector3* Vector3::multScalarVector(double scalar) {
    return new Vector3(
        this->x * scalar,
        this->y * scalar,
        this->z * scalar
    );
}

Vector3* Vector3::projVector(Vector3 *other) {
    Vector3 *newVector3 = other->clone();
    newVector3->multScalar(
        this->dot(other) / other->lengthSq()
    );
    return newVector3;
}

double Vector3::scalarProj(Vector3 *other) {
    return this->dot(other) / other->length();
}

#endif

// TODO
//  Memory Management
//  Organize implementations
//  