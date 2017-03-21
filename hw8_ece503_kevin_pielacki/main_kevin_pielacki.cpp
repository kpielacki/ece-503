#include <iostream>
#include <string>
#include "Shape.h"
#include "TwoDimensionalShape.h"


int main() {
    bool in_menu = true;
    int option;
    int x;
    int y;
    int radius;
    int width;
    int height;

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
                TwoDimensionalShape circle(x, y);
                std::cout << "The circle with radius " << circle.get_x() << " that is located at (" << circle.get_x() << ", " << circle.get_y() << ") has:" << std::endl;
                std::cout << "An area of: " << circle.get_area() << std::endl;
                break;
            } case 2: {
                std::cout << "Triangle" << std::endl;
                break;
            } case 3: {
                std::cout << "Sphere" << std::endl;
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
