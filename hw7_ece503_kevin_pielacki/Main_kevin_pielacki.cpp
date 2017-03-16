#include <iostream>
#include <string>
#include "Polynomial.h"

using namespace std;


int main() {
    Polynomial poly_1;
    poly_1.set_terms();
    Polynomial poly_2;
    poly_2.set_terms();
    Polynomial poly_1_temp;

    cout << "The first polynomial is: " << poly_1 << endl;
    cout << "The second polynomial is: " << poly_2 << endl;


    cout << "Adding the two polynomials yields: " << poly_1 + poly_2 << endl;
    // Use overloaded assignment operator to hold the value of poly_1 for "+="
    // operator. I don't want to overwrite the values for the other operator
    // demonstartions.
    poly_1_temp = poly_1;
    poly_1_temp += poly_2;
    cout << "+= the polynomials yields : " << poly_1_temp << endl;


    cout << "Subtracting the two polynomials yields: " << poly_1 - poly_2 << endl;
    // Use overloaded assignment operator to hold the value of poly_1 for "-="
    // operator. I don't want to overwrite the values for the other operator
    // demonstartions.
    poly_1_temp = poly_1;
    poly_1_temp -= poly_2;
    cout << "-= the polynomials yields : " << poly_1_temp << endl;


    cout << "Multiplying the two polynomials yields: " << poly_1 * poly_2 << endl;
    // Use overloaded assignment operator to hold the value of poly_1 for "*="
    // operator. I don't want to overwrite the values for the other operator
    // demonstartions.
    poly_1_temp = poly_1;
    poly_1_temp *= poly_2;
    cout << "*= the polynomials yields : " << poly_1_temp << endl;

    return 0;
}


