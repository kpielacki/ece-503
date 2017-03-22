#include <iostream>
#include "Sphere.h"


Sphere::Sphere(float x_val, float y_val, float z_val, float radius_val) : ThreeDimensionalShape(x_val, y_val, z_val) {
    Sphere::set_radius(radius_val);
}


float Sphere::get_radius() {
    return radius;
}


void Sphere::set_radius(float radius_val) {
    radius = radius_val;
}


float Sphere::get_area() {
    return 4 * 3.14 * ( Sphere::get_radius() * Sphere::get_radius() );
}


float Sphere::get_volume() {
    return ( 4.0 / 3.0 ) * 3.14 * ( Sphere::get_radius() * Sphere::get_radius() * Sphere::get_radius() );
}
