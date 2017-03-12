#include <iostream>
#include <string>
#include "Polynomial.h"

using namespace std;


int main() {
    Polynomial poly_1(true);
    Polynomial poly_2(true);

    cout << "The first polynomial is: " << poly_1 << endl;
    cout << "The second polynomial is: " << poly_2 << endl;


    cout << "Adding the two polynomials yields: " << poly_1 + poly_2 << endl;
    return 0;
}


