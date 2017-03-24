#include <iostream>
#include "Sphere.h"


// Call parent class ThreeDimensionalShape constructor to set x, y, and z coordinates.
// Set pi value for area and volume calculation.
// Pass init radius to radius setter.
Sphere::Sphere(float x_val, float y_val, float z_val, float radius_val) : ThreeDimensionalShape(x_val, y_val, z_val) {
    pi = 3.141592653589793;
    Sphere::set_radius(radius_val);
}


// radius value getter.
float Sphere::get_radius() {
    return radius;
}


// Set radius to passed value if non-negative otherwise set to zero.
void Sphere::set_radius(float radius_val) {
    if ( radius_val >= 0 ) {
        radius = radius_val;
    } else {
        radius = 0;
        std::cout << "Radius value must be non-negative." << std::endl;
    }
}


// Return sphere area formula: 4 * pi * radius^2
float Sphere::get_area() {
    return 4 * pi * ( Sphere::get_radius() * Sphere::get_radius() );
}


// Return sphere volume formula: ( 4 / 3 ) * pi * r^3
float Sphere::get_volume() {
    return ( 4.0 / 3.0 ) * pi * ( Sphere::get_radius() * Sphere::get_radius() * Sphere::get_radius() );
}
