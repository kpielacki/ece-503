#include "TwoDimensionalShape.h"


TwoDimensionalShape::TwoDimensionalShape(float x, float y) {
    TwoDimensionalShape::x = x;
    TwoDimensionalShape::y = y;
}


float TwoDimensionalShape::get_x() {
    return x;
}


float TwoDimensionalShape::get_y() {
    return y;
}


void TwoDimensionalShape::set_x(float x) {
    x = x;
}


void TwoDimensionalShape::set_y(float y) {
    y = y;
}
