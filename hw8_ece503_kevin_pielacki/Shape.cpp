#include "Shape.h"
#include <iostream>


Shape::Shape() {

}


// Allow child classes to modify return value.
float Shape::get_area() {
    return 0;
}


// Allow child classes to modify return value.
float Shape::get_volume() {
    return 0;
}

