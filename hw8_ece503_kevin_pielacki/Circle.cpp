#include <iostream>
#include "Circle.h"


Circle::Circle(float x, float y, float radius) {
       Circle::x = x;
       Circle::y = y;
       Circle::radius = radius;
}


float Circle::get_radius() {
    return radius;
}


void Circle::set_radius(float radius) {
    Circle::radius = radius;
}
