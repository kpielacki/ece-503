#include "TwoDimensionalShape.h"
#include "Triangle.h"


Triangle::Triangle(float x_val, float y_val, float side_length_val) : TwoDimensionalShape(x_val, y_val) {
    Triangle::set_side_length(side_length_val);
}


float Triangle::get_side_length() {
    return side_length;
}


void Triangle::set_side_length(float side_length_val) {
    side_length = side_length_val;
}


float Triangle::get_area() {
    // To not involve height calculation used simplified formula show at:
    // http://www.mathopenref.com/triangleequilateralarea.html
    // 0.433... Is the calculated sqrt(3) / 4.
    return 0.4330127018922193 * ( Triangle::get_side_length() * Triangle::get_side_length() );
}
