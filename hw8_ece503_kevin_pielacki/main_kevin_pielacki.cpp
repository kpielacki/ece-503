#include <iostream>
#include <string>
#include "Shape.h"
#include "TwoDimensionalShape.h"
#include "ThreeDimensionalShape.h"
#include "Circle.h"
#include "Triangle.h"
#include "Sphere.h"


int main() {
    bool in_menu = true;
    int option;
    float x;
    float y;
    float z;
    float radius;
    float side_length;
    float width;
    float height;

    while (in_menu) {
        std::cout << "Please choose a shape or 0 to exit:" << std::endl;
        std::cout << "1. Circle" << std::endl;
        std::cout << "2. Triangle" << std::endl;
        std::cout << "3. Sphere" << std::endl;
        std::cout << "4. Regular Tetrahedron " << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "Choice: ";
        std::cin >> option;

        switch (option) {
            case 0: {
                in_menu = false;
                break;
            } case 1: {
                std::cout << "Please enter the center of the circle (x-coordinate and then the y-coordinate): ";
                std::cin >> x;
                std::cin >> y;
                std::cout << "Please enter the radius of the circle: ";
                std::cin >> radius;
                Circle circle(x, y, radius);
                std::cout << "The circle with radius " << circle.get_radius() << " that is located at (" << circle.get_x() << ", " << circle.get_y() << ") has:" << std::endl;
                std::cout << "An area of: " << circle.get_area() << std::endl;
                break;
            } case 2: {
                std::cout << "Please enter the center of the triangle (x-coordinate and then the y-coordinate): ";
                std::cin >> x;
                std::cin >> y;
                std::cout << "Please enter the side length of the triangle: ";
                std::cin >> side_length;
                Triangle triangle(x, y, side_length);
                std::cout << "The triangle with side length " << triangle.get_side_length() << " that is located at (" << triangle.get_x() << ", " << triangle.get_y() << ") has:" << std::endl;
                std::cout << "An area of: " << triangle.get_area() << std::endl;
                break;
            } case 3: {
                std::cout << "Please enter the center of the sphere (x-coordinate, y-coordinate, and then the z-coordinate): ";
                std::cin >> x;
                std::cin >> y;
                std::cin >> z;
                std::cout << "Please enter the radius of the sphere: ";
                std::cin >> radius;
                Sphere sphere(x, y, z, radius);
                std::cout << "The sphere with radius " << sphere.get_radius() << " that is located at (" << sphere.get_x() << ", " << sphere.get_y() << ", " << sphere.get_z() << ") has:" << std::endl;
                std::cout << "A surface area of: " << sphere.get_area() << std::endl;
                std::cout << "A volume of: " << sphere.get_area() << std::endl;
                break;
            } case 4: {
                std::cout << "Regular Tetrahedron" << std::endl;
                break;
            } default: {
                std::cout << "Invalid selection" << std::endl;
            }
        }
    }
    return 0;
}
