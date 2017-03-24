#include <iostream>
#include "Circle.h"


// Call parent class constructor to set x and y coordinates.
// Set pi value for area calculation
// Set initial radius value.
Circle::Circle(float x_val, float y_val, float radius_val) : TwoDimensionalShape(x_val, y_val) {
        pi = 3.141592653589793;
        Circle::set_radius(radius_val);
}


// radius value getter.
float Circle::get_radius() {
    return radius;
}


// Set passed value as radius if non-negative otherwise set to zero.
void Circle::set_radius(float radius_val) {
    if ( radius_val >= 0 ) {
        radius = radius_val;
    } else {
        radius = 0;
        std::cout << "Radius value must be non-negative." << std::endl;
    }
}


// Return circle area formula: pi * radius^2
float Circle::get_area() {
    return pi * ( Circle::get_radius() * Circle::get_radius() );
}
