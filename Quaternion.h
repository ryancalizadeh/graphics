#ifndef QUATERNION_H
#define QUATERNION_H

class Quaternion {
    public:
    double a, b, c, d;

    Quaternion();
    Quaternion(
        double _a,
        double _b,
        double _c,
        double _d
    );
};

Quaternion::Quaternion() {
    a = 1.0;
    b = 0.0;
    c = 0.0;
    d = 0.0;
}

Quaternion::Quaternion(
    double _a,
    double _b,
    double _c,
    double _d
) {
    a = _a;
    b = _b;
    c = _c;
    d = _d;
}

#endif