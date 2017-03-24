#include <iostream>
#include "twodimensionalshape.h"
#include "triangle.h"


// Call parent class TwoDimensionalShape constructor to set x and y coordinates.
// Set side_length value using setter.
Triangle::Triangle(float x_val, float y_val, float side_length_val) : TwoDimensionalShape(x_val, y_val) {
    Triangle::set_side_length(side_length_val);
}


// side_length value getter.
float Triangle::get_side_length() {
    return side_length;
}


// Set passed side_length value if non-negative otherwise set to zero.
void Triangle::set_side_length(float side_length_val) {
    if ( side_length_val >= 0 ) {
        side_length = side_length_val;
    } else {
        side_length = 0;
        std::cout << "Side length must be non-negative." << std::endl;
    }
}


// Return equilateral triangle formula: ( sqrt(3) / 4 ) * side_length^2
float Triangle::get_area() {
    // To not involve height calculation used simplified formula show at:
    // http://www.mathopenref.com/triangleequilateralarea.html
    // 0.433... Is the calculated sqrt(3) / 4.
    return 0.4330127018922193 * ( Triangle::get_side_length() * Triangle::get_side_length() );
}
