#include "ThreeDimensionalShape.h"


// Have constructor set initial x, y, and coordinates.
ThreeDimensionalShape::ThreeDimensionalShape(float x_val, float y_val, float z_val) {
    x = x_val;
    y = y_val;
    z = z_val;
}


// x coordinate getter.
float ThreeDimensionalShape::get_x() {
    return x;
}


// y coordinate getter.
float ThreeDimensionalShape::get_y() {
    return y;
}


// z coordinate getter.
float ThreeDimensionalShape::get_z() {
    return z;
}


// x coordinate setter.
void ThreeDimensionalShape::set_x(float x_val) {
    x = x_val;
}


// y coordinate setter.
void ThreeDimensionalShape::set_y(float y_val) {
    y = y_val;
}


// z coordinate setter.
void ThreeDimensionalShape::set_z(float z_val) {
    z = z_val;
}

