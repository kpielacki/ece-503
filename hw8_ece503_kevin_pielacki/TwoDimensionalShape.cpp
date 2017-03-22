#include "TwoDimensionalShape.h"


TwoDimensionalShape::TwoDimensionalShape(float x_val, float y_val) {
    x = x_val;
    y = y_val;
}


float TwoDimensionalShape::get_x() {
    return x;
}


float TwoDimensionalShape::get_y() {
    return y;
}


void TwoDimensionalShape::set_x(float x_val) {
    x = x_val;
}


void TwoDimensionalShape::set_y(float y_val) {
    y = y_val;
}
