#include "TwoDimensionalShape.h"


// Have class constructor set shape coordinates.
TwoDimensionalShape::TwoDimensionalShape(float x_val, float y_val) {
    x = x_val;
    y = y_val;
}


// x coordinate getter.
float TwoDimensionalShape::get_x() {
    return x;
}


// y coordinate getter.
float TwoDimensionalShape::get_y() {
    return y;
}


// x coordinate setter.
void TwoDimensionalShape::set_x(float x_val) {
    x = x_val;
}


// y coordinate setter.
void TwoDimensionalShape::set_y(float y_val) {
    y = y_val;
}
