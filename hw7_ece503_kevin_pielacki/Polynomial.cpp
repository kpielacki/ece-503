#include <iostream>
#include <sstream>
#include "Polynomial.h"

using namespace std;


// Constructor
Polynomial::Polynomial(bool set_terms) {
    // Assuming we will allow a zero term polynomial.
    Polynomial::min_term_cnt = 0;
    Polynomial::max_term_cnt = 6;
    // Default variable value of 'x'.
    Polynomial::var = 'x';

    if (set_terms) {
        Polynomial::set_term_cnt();
        for (int i = 0; i < Polynomial::term_cnt; i++) {
            Polynomial::set_term(i);
        }
        // Order exponents in ascending order.
        // I think this makes the print easier to read.
        Polynomial::sort_by_expons();
    } else {
        Polynomial::term_cnt = 0;
    }
}


// Destructor
Polynomial::~Polynomial() {

}

void Polynomial::set_term_cnt() {
    Polynomial::term_cnt = -1;
    while (Polynomial::term_cnt < Polynomial::min_term_cnt or Polynomial::term_cnt > Polynomial::max_term_cnt) {
        cout << "Enter the number of polynomial terms: ";
        cin >> Polynomial::term_cnt;
        if (Polynomial::term_cnt > Polynomial::max_term_cnt) {
            cout << "Max term count is " << Polynomial::max_term_cnt << endl;
        } else if (Polynomial::term_cnt < Polynomial::min_term_cnt) {
            cout << "Min term count is " << Polynomial::min_term_cnt << endl;
        }
    }
}


void Polynomial::set_term(int term_idx) {
    int coeff = 0;
    int exp;
    // Keep track of the current set exponents.

    // I'm forcing terms to have a non-zero value. The overloaded "<<" will
    // skip zero coeffecient terms but I think it would be confusing to for the
    // term count not to match what's seen in the console print.
    // I'm also forcing the different terms to have unqiue exponents. I could
    // of performed the overloaded addition to combine terms but again I don't
    // want to assure the set term count is visible to the user.
    while (coeff == 0) {
        cout << "Enter a coeffecient and exponent for term " << term_idx + 1 << ": ";
        cin >> coeff;
        cin >> exp;

        if (coeff == 0) {
            cout << "Coeffecient must be non-zero" << endl;
        } else {
            // Ensure for unique exponents.
            for (int i = 0; i < term_idx; i++) {
                if (exp == Polynomial::expons[i]) {
                    cout << "Another term with exponent value \"" << exp << "\" already exists." << endl;
                    // Force while condition for term value prompt.
                    coeff = 0;
                }
            }
            Polynomial::coeffs[term_idx] = coeff;
            Polynomial::expons[term_idx] = exp;
        }
    }

}


// Use bubble sorting to order exponents ascending after operations that return
// polynomials in a mixed order.
void Polynomial::sort_by_expons() {
    int *expons_val;
    int *coeffs_val;
    int *_val;
    int temp_expon;
    int temp_coeff;
    expons_val = Polynomial::expons;
    coeffs_val = Polynomial::coeffs;

    for (int i = 0; i < Polynomial::term_cnt; i++) {
        // Iterate to last element - sorted max elements - 1 for offset.
        for (int j = 0; j < Polynomial::term_cnt - i - 1; j++) {
            // Swap current and current + 1 element if greater moving max
            // value to end of list.
            if (*(expons_val + j) > *(expons_val + j + 1)) {
                temp_expon = *(expons_val + j);
                temp_coeff = *(coeffs_val + j);
                *(expons_val + j) = *(expons_val + j + 1);
                *(expons_val + j + 1) = temp_expon;
                *(coeffs_val + j) = *(coeffs_val + j + 1);
                *(coeffs_val + j + 1) = temp_coeff;
            }
        }
    }
    return;
}


string int_to_string (int num) {
    // Opens string stream to convert int value to string.
    // Used to build r_string in "<<" overload.
    ostringstream ss;
    ss << num;
    return ss.str();
}


ostream& operator<<(ostream& os, const Polynomial& poly) {
    string r_string = "";
    bool first_term = true;
    for (int term_idx = 0; term_idx < poly.term_cnt; term_idx++) {
        if (term_idx > poly.term_cnt or term_idx < poly.min_term_cnt) {
            os << "Invalid term index. ";
        } else {
            int coeff_val = poly.coeffs[term_idx];
            int exp_val = poly.expons[term_idx];
            // Handle sign print between terms.
            if (coeff_val == 0) {
                // Skip value of zero.
                continue;
            } else if (first_term) {
                // Don't add "+" sign for first term and don't add space for
                // "-" sign if first term.
                r_string = int_to_string(coeff_val);
                first_term = false;
            } else if (coeff_val > 0 and term_idx > 0) {
                r_string = r_string + " + " + int_to_string(coeff_val);
            } else {
                // Force positive to space out "-" print.
                r_string = r_string + " - " + int_to_string(-coeff_val);
            }

            if (exp_val == 0) {
                // Return only coefficient if exponent value is zero.
                 continue;
            } else if (exp_val == 1) {
                // Return only variable if exponent value is zero.
                r_string = r_string + poly.var;
            } else {
                r_string = r_string + poly.var + "^" + int_to_string(exp_val);
            }
        }
    }
    os << r_string;
    return os;
}


Polynomial operator+(const Polynomial& poly_1, const Polynomial& poly_2) {
    // Skip prompt for setting terms. Will be handled within function call.
    Polynomial poly_add(false);
    // An example output showed that in the case where the two polynomials do
    // not share the same exponent that the output is composed of both terms
    // meaning that the the assumption for max term count of 6 will not apply
    // for Polynomial operations.
    // First Polynomial is : 2x^2 + 3x^3
    // Second Polynomial is : 1x + 2x^2 + 3x^3

    // The max possible term count after adding two Polynomial types is doubled
    // in the case where all the exponents are unique so modify max_term_cnt to
    // allow for 12 term Polynomial creation.
    int skip_idx_1[6] = {false, false, false, false, false, false};
    int skip_idx_2[6] = {false, false, false, false, false, false};
    poly_add.max_term_cnt *= 2;

    // Handle addition of shared exponent values.
    for (int idx_1 = 0; idx_1 < poly_1.term_cnt; idx_1++) {
        for (int idx_2 = 0; idx_2 < poly_2.term_cnt; idx_2++) {
            if (poly_1.expons[idx_1] == poly_2.expons[idx_2]) {
                // Add term for common exponents.
                poly_add.coeffs[poly_add.term_cnt] = poly_1.coeffs[idx_1] + poly_2.coeffs[idx_2];
                poly_add.expons[poly_add.term_cnt] = poly_1.expons[idx_1];
                poly_add.term_cnt += 1;

                // Keep track of common terms when adding uncommon terms.
                skip_idx_1[idx_1] = true;
                skip_idx_2[idx_2] = true;
            }
        }
    }

    // Include terms with ucommon exponents.
    for (int idx_1 = 0; idx_1 < poly_1.term_cnt; idx_1++) {
        if (skip_idx_1[idx_1]) {
            continue;
        } else {
            poly_add.coeffs[poly_add.term_cnt] = poly_1.coeffs[idx_1];
            poly_add.expons[poly_add.term_cnt] = poly_1.expons[idx_1];
            poly_add.term_cnt += 1;
        }
    }
    for (int idx_2 = 0; idx_2 < poly_2.term_cnt; idx_2++) {
        if (skip_idx_2[idx_2]) {
            continue;
        } else {
            poly_add.coeffs[poly_add.term_cnt] = poly_2.coeffs[idx_2];
            poly_add.expons[poly_add.term_cnt] = poly_2.expons[idx_2];
            poly_add.term_cnt += 1;
        }
    }
    poly_add.sort_by_expons();
    return poly_add;
}


Polynomial operator-(const Polynomial& poly_1, const Polynomial& poly_2) {
    // Skip prompt for setting terms. Will be handled within function call.
    Polynomial poly_sub(false);
    // An example output showed that in the case where the two polynomials do
    // not share the same exponent that the output is composed of both terms
    // meaning that the the assumption for max term count of 6 will not apply
    // for Polynomial operations.
    // First Polynomial is : 2x^2 + 3x^3
    // Second Polynomial is : 1x + 2x^2 + 3x^3

    // The max possible term count after subtracking two Polynomial types is
    // doubled in the case where all the exponents are unique so modify
    // max_term_cnt to allow for 12 term Polynomial creation.
    int skip_idx_1[6] = {false, false, false, false, false, false};
    int skip_idx_2[6] = {false, false, false, false, false, false};
    poly_sub.max_term_cnt *= 2;

    // Handle addition of shared exponent values.
    for (int idx_1 = 0; idx_1 < poly_1.term_cnt; idx_1++) {
        for (int idx_2 = 0; idx_2 < poly_2.term_cnt; idx_2++) {
            if (poly_1.expons[idx_1] == poly_2.expons[idx_2]) {
                // Subtract term for common exponents.

                // Skip if subtraction leads to zero value.
                int poly_coeff;
                poly_coeff = poly_1.coeffs[idx_1] - poly_2.coeffs[idx_2];
                if (poly_coeff != 0) {
                    poly_sub.coeffs[poly_sub.term_cnt] = poly_coeff;
                    poly_sub.expons[poly_sub.term_cnt] = poly_1.expons[idx_1];
                    poly_sub.term_cnt += 1;
                }

                // Keep track of common terms when adding uncommon terms.
                skip_idx_1[idx_1] = true;
                skip_idx_2[idx_2] = true;
            }
        }
    }

    // Include terms with ucommon exponents.
    for (int idx_1 = 0; idx_1 < poly_1.term_cnt; idx_1++) {
        if (skip_idx_1[idx_1]) {
            continue;
        } else {
            poly_sub.coeffs[poly_sub.term_cnt] = poly_1.coeffs[idx_1];
            poly_sub.expons[poly_sub.term_cnt] = poly_1.expons[idx_1];
            poly_sub.term_cnt += 1;
        }
    }
    // Subtract second argument uncommon exponent terms.
    for (int idx_2 = 0; idx_2 < poly_2.term_cnt; idx_2++) {
        if (skip_idx_2[idx_2]) {
            continue;
        } else {
            poly_sub.coeffs[poly_sub.term_cnt] = -poly_2.coeffs[idx_2];
            poly_sub.expons[poly_sub.term_cnt] = poly_2.expons[idx_2];
            poly_sub.term_cnt += 1;
        }
    }
    poly_sub.sort_by_expons();
    return poly_sub;
}


Polynomial operator*(const Polynomial& poly_1, const Polynomial& poly_2) {
    // Keep poly_mult empty and fill term by term with poly_temp.
    Polynomial poly_mult(false);
    Polynomial poly_temp(false);
    // Max terms that can be returned by multiplying two polynomials is the
    // term count squared.
    // I'm using the max term count which is defaulted to 6 and cannot be
    // changed outside a method.
    poly_mult.max_term_cnt *= poly_mult.max_term_cnt;

    // Multiply one term at a time and add to poly_mult.
    // By using addition the terms with the same exponents will be combined.
    for (int idx_1 = 0; idx_1 < poly_1.term_cnt; idx_1++) {
        for (int idx_2 = 0; idx_2 < poly_2.term_cnt; idx_2++) {
            Polynomial poly_temp(false);
            int poly_coeff;
            int poly_exp;
            // Multiply current coefficients.
            poly_temp.coeffs[poly_temp.term_cnt] = poly_1.coeffs[idx_1] * poly_2.coeffs[idx_2];
            // Add current exponents.
            poly_temp.expons[poly_temp.term_cnt] = poly_1.expons[idx_1] + poly_2.expons[idx_2];
            // Techinically not needed but want to keep track.
            poly_temp.term_cnt += 1;

            // Let addition deal with common exponent terms and term counting.
            poly_mult = poly_mult + poly_temp;
        }
    }
    poly_mult.sort_by_expons();
    return poly_mult;
}


Polynomial& Polynomial::operator=(const Polynomial& poly_2) {
    // Copy class parameters to LH Polynomial.
    this->var = poly_2.var;
    this->min_term_cnt = poly_2.min_term_cnt;
    this->max_term_cnt =  poly_2.max_term_cnt;
    this->term_cnt =  poly_2.term_cnt;
    for (int idx = 0; idx < poly_2.term_cnt; idx++) {
        this->coeffs[idx] =  poly_2.coeffs[idx];
        this->expons[idx] =  poly_2.expons[idx];
    }
    return *this;
}


Polynomial& Polynomial::operator+=(const Polynomial& poly_2) {
    // Reuse overloaded addition operator.
    *this = *this + poly_2;
    return *this;
}


Polynomial& Polynomial::operator-=(const Polynomial& poly_2) {
    // Reuse overloaded subtraction operator.
    *this = *this - poly_2;
    return *this;
}


Polynomial& Polynomial::operator*=(const Polynomial& poly_2) {
    // Reuse overloaded multiply operator.
    *this = *this * poly_2;
    return *this;
}
