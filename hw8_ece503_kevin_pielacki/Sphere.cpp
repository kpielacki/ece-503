#include <iostream>
#include "Sphere.h"


Sphere::Sphere(float x_val, float y_val, float z_val, float radius_val) : ThreeDimensionalShape(x_val, y_val, z_val) {
    pi = 3.141592653589793;
    Sphere::set_radius(radius_val);
}


float Sphere::get_radius() {
    return radius;
}


void Sphere::set_radius(float radius_val) {
    if ( radius_val >= 0 ) {
        radius = radius_val;
    } else {
        radius = 0;
        std::cout << "Radius value must be non-negative." << std::endl;
    }
}


float Sphere::get_area() {
    return 4 * pi * ( Sphere::get_radius() * Sphere::get_radius() );
}


float Sphere::get_volume() {
    return ( 4.0 / 3.0 ) * pi * ( Sphere::get_radius() * Sphere::get_radius() * Sphere::get_radius() );
}
