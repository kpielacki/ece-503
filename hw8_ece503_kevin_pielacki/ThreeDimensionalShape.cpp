#include "ThreeDimensionalShape.h"


ThreeDimensionalShape::ThreeDimensionalShape(float x_val, float y_val, float z_val) {
    x = x_val;
    y = y_val;
    z = z_val;
}


float ThreeDimensionalShape::get_x() {
    return x;
}


float ThreeDimensionalShape::get_y() {
    return y;
}


float ThreeDimensionalShape::get_z() {
    return z;
}


void ThreeDimensionalShape::set_x(float x_val) {
    x = x_val;
}


void ThreeDimensionalShape::set_y(float y_val) {
    y = y_val;
}


void ThreeDimensionalShape::set_z(float z_val) {
    z = z_val;
}
