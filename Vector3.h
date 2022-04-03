#ifndef VECTOR3_H
#define VECTOR3_H
#include <cmath>
#include <memory>

using std::unique_ptr;

class Vector3 {
    public:
    double x, y, z;

    // Constructors
    Vector3();
    Vector3(double x, double y, double z);

    // Generators
    unique_ptr<Vector3> normalizeVector();
    unique_ptr<Vector3> clone();
    unique_ptr<Vector3> crossVector(unique_ptr<Vector3> &other);
    unique_ptr<Vector3> addVector(unique_ptr<Vector3> &other);
    unique_ptr<Vector3> subVector(unique_ptr<Vector3> &other);
    unique_ptr<Vector3> multScalarVector(double scalar);
    unique_ptr<Vector3> projVector(unique_ptr<Vector3> &other);

    // Modifiers
    void add(unique_ptr<Vector3> &other);
    void multScalar(double scalar);
    void normalize();

    // Getters
    double length();
    double lengthSq();
    double dot(unique_ptr<Vector3> &other);
    double scalarProj(unique_ptr<Vector3> &other);
    double dist(unique_ptr<Vector3> &other);
};

Vector3::Vector3() {
    x = 0.0;
    y = 0.0;
    z = 0.0;
}

Vector3::Vector3(double x_, double y_, double z_) {
    x = x_;
    y = y_;
    z = z_;
}

void Vector3::add(unique_ptr<Vector3> &other) {
    this->x += other->x;
    this->y += other->y;
    this->z += other->z;
}

unique_ptr<Vector3> Vector3::addVector(unique_ptr<Vector3> &other) {
    return std::make_unique<Vector3>(
        this->x + other->x,
        this->y + other->y,
        this->z + other->z
    );
}

unique_ptr<Vector3> Vector3::subVector(unique_ptr<Vector3> &other) {
    return std::make_unique<Vector3>(
        this->x - other->x,
        this->y - other->y,
        this->z - other->z
    );
}

double Vector3::dist(unique_ptr<Vector3> &other) {
    return std::sqrt(
        std::pow(this->x - other->x, 2) +
        std::pow(this->y - other->y, 2) +
        std::pow(this->z - other->z, 2)
    );
}

double Vector3::dot(unique_ptr<Vector3> &other) {
    return  this->x * other->x +
            this->y * other->y +
            this->z * other->z;
}

unique_ptr<Vector3> Vector3::crossVector(unique_ptr<Vector3> &other) {
    return std::make_unique<Vector3>(
        this->y * other->z - this->z * other->y,
        this->z * other->x - this->x * other->z,
        this->x * other->y - this->y * other->x
    );
}

void Vector3::normalize() {
    double len = this->length();
    this->multScalar(1 / len);
}

unique_ptr<Vector3> Vector3::normalizeVector() {
    double len = this->length();
    return this->multScalarVector(1 / len);
}

unique_ptr<Vector3> Vector3::clone() {
    return std::make_unique<Vector3>(this->x, this->y, this->z);
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

unique_ptr<Vector3> Vector3::multScalarVector(double scalar) {
    return std::make_unique<Vector3>(
        this->x * scalar,
        this->y * scalar,
        this->z * scalar
    );
}

unique_ptr<Vector3> Vector3::projVector(unique_ptr<Vector3> &other) {
    unique_ptr<Vector3> newVector3 = other->clone();
    newVector3->multScalar(
        this->dot(other) / other->lengthSq()
    );
    return newVector3;
}

double Vector3::scalarProj(unique_ptr<Vector3> &other) {
    return this->dot(other) / other->length();
}

#endif

// TODO
//  Organize implementations
//  

