#include <iostream>
#include <vector>
#include <cmath>

const double PI = 2.0 * acos(0.0);
const double EPSILON = 1e-14;

struct vector2 {
    double x, y;

    explicit vector2(double x_ = 0, double y_ = 0) : x(x_), y(y_) {}

    bool operator == (const vector2& rhs) const {
        return x == rhs.x && y == rhs.y;
    }

    bool operator < (const vector2& rhs) const {
        return x != rhs.x ? x < rhs.x : y < rhs.y;
    }

    vector2 operator + (const vector2& rhs) const {
        return vector2(x + rhs.x, y + rhs.y);
    }

    vector2 operator - (const vector2& rhs) const {
        return vector2(x - rhs.x, y - rhs.y);
    }

    vector2 operator * (double rhs) const {
        return vector2(x * rhs, y * rhs);
    }

    double norm() const {
        return hypot(x, y);
    }

    vector2 normalize() const {
        return vector2(x / norm(), y / norm());
    }

    double polar() const {
        return fmod(atan2(y, x) + 2*PI, 2*PI);
    }

    double dot(const vector2& rhs) const {
        return x * rhs.x + y * rhs.y;
    }

    double cross(const vector2& rhs) const {
        return x * rhs.y - rhs.x * y;
    }

    vector2 project(const vector2& rhs) const {
        vector2 r = rhs.normalize();
        return r * r.dot(*this);
    }
};

double ccw(vector2 a, vector2 b) {
    return a.cross(b);
}

double ccw(vector2 p, vector2 a, vector2 b) {
    return ccw(a-p, b-p);
}

bool lineIntersection(vector2 a, vector2 b, vector2 c, vector2 d, vector2& x) {
    double det = (b-a).cross(d-c);

    if(fabs(det) < EPSILON) return false;
    x = a + (b-a) * ((c-a).cross(d-c) / det);
    return true;
}
