#include <iostream>
#include "ThreeDimensionalShape.h"
#include "Tetrahedron.h"


// Call parent class ThreeDimensionalShape constructor to set x, y, and z coordinates.
// Call setter for side_length value.
Tetrahedron::Tetrahedron(float x_val, float y_val, float z_val, float side_length_val) : ThreeDimensionalShape(x_val, y_val, z_val) {
    Tetrahedron::set_side_length(side_length_val);
}


// side_length value getter.
float Tetrahedron::get_side_length() {
    return side_length;
}


// Set side_length to passed value if non-negative otherwise set to zero.
void Tetrahedron::set_side_length(float side_length_val) {
    if ( side_length_val >= 0 ) {
        side_length = side_length_val;
    } else {
        side_length = 0;
        std::cout << "Side length must be non-negative." << std::endl;
    }
}


// Return regular tetrahedron surface area formula: sqrt(3) * side_length^2
float Tetrahedron::get_area() {
    // 1.732... Is the calculated sqrt(3)
    return 1.7320508075688772 * ( Tetrahedron::get_side_length() * Tetrahedron::get_side_length() );
}


// Return regular tetrahedron volume formula:  side_length^3 / ( 6 * sqrt(2) )
float Tetrahedron::get_volume() {
    // 8.48... is 6 * sqrt(2)
    return ( Tetrahedron::get_side_length() * Tetrahedron::get_side_length() * Tetrahedron::get_side_length() ) / 8.485281374238571;
}
