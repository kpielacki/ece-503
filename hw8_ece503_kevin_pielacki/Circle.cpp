#include <iostream>
#include "Circle.h"


Circle::Circle(float x_val, float y_val, float radius_val) : TwoDimensionalShape(x_val, y_val) {
        pi = 3.141592653589793;
        Circle::set_radius(radius_val);
}


float Circle::get_radius() {
    return radius;
}


void Circle::set_radius(float radius_val) {
    radius = radius_val;
}


float Circle::get_area() {
    return pi * ( Circle::get_radius() * Circle::get_radius() );
}
