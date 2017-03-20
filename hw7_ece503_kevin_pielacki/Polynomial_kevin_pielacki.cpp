#include <iostream>
#include <sstream>
#include <string>
#include "Polynomial_kevin_pielacki.h"

using namespace std;


string int_to_string (int num) {
    // Opens string stream to convert int value to string.
    // Used to build r_string in "<<" overload.
    ostringstream ss;
    ss << num;
    return ss.str();
}


// Constructor
Polynomial::Polynomial() {
    // Assuming we will allow a zero term polynomial.
    Polynomial::min_term_cnt = 0;
    Polynomial::max_term_cnt = 6;

    // I wanted to write a skeleton where the term capacity can be increased
    // if needed by calling handle_term_capacity method. If we wanted to use
    // dynamic arrays it makes more sense to increase your array size more than
    // one element since increasing array size is a resource expensive call.
    Polynomial::term_capacity = 36;

    // Default variable value of 'x'.
    //  Can be changed by calling set_var.
    // At one point I wanted to have the class handle different variables but
    // it's not required by the assignment. This really should be a matrix for
    // every possible combination of variables you could multiply by and that
    // would also require coeffecients exponents to be a matrix which is far
    // beyond the assignment requirements. So if now if you try an operator on
    // two Polynomials with different variables it will return a error message
    // with an empty Polynomial saying it's not supported.
    Polynomial::var = 'x';

    // Initialize term count to 0.
    //  User calls set_terms to fill values needed for Polynomial.
    //  Friends can access term counts and individual terms freely to by pass
    //    constraints. This allows us to handle situations where the term count
    //    exceeds the intented value of 6.
    Polynomial::term_cnt = 0;
}


// Destructor
Polynomial::~Polynomial() {
    // I didn't use anything that requires to be deleted so for the sake of
    // demonstrating a destructor I'll adjust the values to represent an empty
    // polynomial.
    Polynomial::min_term_cnt = 0;
    Polynomial::max_term_cnt = 0;
    Polynomial::term_capacity = 0;
    Polynomial::var = '\0';
    Polynomial::term_cnt = 0;
}

void Polynomial::set_term_cnt() {
    Polynomial::term_cnt = -1;
    while (Polynomial::term_cnt < Polynomial::min_term_cnt || Polynomial::term_cnt > Polynomial::max_term_cnt) {
        cout << "Enter the number of polynomial terms: ";
        cin >> Polynomial::term_cnt;
        if (Polynomial::term_cnt > Polynomial::max_term_cnt) {
            cout << "Max term count is " << Polynomial::max_term_cnt << endl;
        } else if (Polynomial::term_cnt < Polynomial::min_term_cnt) {
            cout << "Min term count is " << Polynomial::min_term_cnt << endl;
        }
    }
}


// Returns term at index.
// Note that all polynomials are sorted by exponent value in ascending order so
// a user might enter in any order but it will be ordered immediately.
string Polynomial::get_term(int term_idx) {
    string r_string = "";
    if (term_idx >= Polynomial::term_cnt || term_idx < Polynomial::min_term_cnt) {
            return "Invalid term index.";
    } else {
        int coeff_val = Polynomial::coeffs[term_idx];
        int exp_val = Polynomial::expons[term_idx];
        // Handle sign print between terms.
        if (coeff_val == 0) {
            // Skip value of zero.
            return r_string;
        } else {
            // Don't add "+" sign for first term and don't add space for
            // "-" sign if first term.
            r_string = int_to_string(coeff_val);
        }

        if (exp_val == 0) {
            // Return only coefficient if exponent value is zero.
             return r_string;
        } else if (exp_val == 1) {
            // Return only variable if exponent value is zero.
            r_string = r_string + Polynomial::var;
        } else {
            r_string = r_string + Polynomial::var + "^" + int_to_string(exp_val);
        }
    }
    return r_string;
}


// Private method used to check user input on term with specific index.
//  Forces each term to have a unique exponent.
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


// Public method called by user to prompt for term count and all terms.
void Polynomial::set_terms() {
    Polynomial::set_term_cnt();
    for (int i = 0; i < Polynomial::term_cnt; i++) {
        Polynomial::set_term(i);
    }
    // Order exponents in ascending order.
    // I think this makes the print easier to read.
    Polynomial::sort_by_expons();
    return;
}


// Getter for variable name.
char Polynomial::get_var() {
    return Polynomial::var;
}


// Sets variable used for polynomial.
// I also made sure that when combining common terms to check for the same
// variable name. This way a polynomial like the one below can exist:
//  a^2 + 2x^2
void Polynomial::set_var(char var_name) {
    Polynomial::var = var_name;
    return;
}


int Polynomial::get_min_term_cnt() {
    return Polynomial::min_term_cnt;
}


int Polynomial::get_max_term_cnt() {
    return Polynomial::max_term_cnt;
}


int Polynomial::get_term_cnt() {
    return Polynomial::term_cnt;
}


int Polynomial::get_term_capacity() {
    return Polynomial::term_capacity;
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


// Call to handle when trying to insert new element past term_capacity.
// Right now prints capacity exceeded but in future could be used to
// dynamically set coeffs and expons array length.
void Polynomial::handle_term_capacity() {
    cout << "Operation Overflow: Max allowed terms resulting from an operation is " << Polynomial::term_capacity << ". Not all results shown." << endl;
}


ostream& operator<<(ostream& os, const Polynomial& poly) {
    string r_string = "";
    bool first_term = true;
    for (int term_idx = 0; term_idx < poly.term_cnt; term_idx++) {
        if (term_idx >= poly.term_cnt || term_idx < poly.min_term_cnt) {
            os << "Invalid term index.";
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
            } else if (coeff_val > 0 && term_idx > 0) {
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
    Polynomial poly_add;
    // An example output showed that in the case where the two polynomials do
    // not share the same exponent that the output is composed of both terms
    // meaning that the the assumption for max term count of 6 will not apply
    // for Polynomial operations.
    // First Polynomial is : 2x^2 + 3x^3
    // Second Polynomial is : 1x + 2x^2 + 3x^3

    if (poly_1.var != poly_2.var) {
        cout << "Operator must use Polynomials with the same var value." << endl;
        return poly_add;
    }

    // The max possible term count after adding two Polynomial types is doubled
    // in the case where all the exponents are unique so modify max_term_cnt to
    // allow for 12 term Polynomial creation.
    int skip_idx_1[6] = {false, false, false, false, false, false};
    int skip_idx_2[6] = {false, false, false, false, false, false};
    poly_add.max_term_cnt *= 2;

    // Handle addition of shared exponent values.
    for (int idx_1 = 0; idx_1 < poly_1.term_cnt; idx_1++) {
        for (int idx_2 = 0; idx_2 < poly_2.term_cnt; idx_2++) {
            if (poly_1.expons[idx_1] == poly_2.expons[idx_2] && poly_1.var == poly_2.var) {
                // Add term for common exponents.
                poly_add.coeffs[poly_add.term_cnt] = poly_1.coeffs[idx_1] + poly_2.coeffs[idx_2];
                poly_add.expons[poly_add.term_cnt] = poly_1.expons[idx_1];
                poly_add.term_cnt += 1;
                if (poly_add.term_cnt >= poly_add.term_capacity) {
                    poly_add.handle_term_capacity();
                    return poly_add;
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
            poly_add.coeffs[poly_add.term_cnt] = poly_1.coeffs[idx_1];
            poly_add.expons[poly_add.term_cnt] = poly_1.expons[idx_1];
            poly_add.term_cnt += 1;
            if (poly_add.term_cnt >= poly_add.term_capacity) {
                poly_add.handle_term_capacity();
                return poly_add;
            }
        }
    }
    for (int idx_2 = 0; idx_2 < poly_2.term_cnt; idx_2++) {
        if (skip_idx_2[idx_2]) {
            continue;
        } else {
            poly_add.coeffs[poly_add.term_cnt] = poly_2.coeffs[idx_2];
            poly_add.expons[poly_add.term_cnt] = poly_2.expons[idx_2];
            poly_add.term_cnt += 1;
            if (poly_add.term_cnt >= poly_add.term_capacity) {
                poly_add.handle_term_capacity();
                return poly_add;
            }
        }
    }
    poly_add.sort_by_expons();
    return poly_add;
}


Polynomial operator-(const Polynomial& poly_1, const Polynomial& poly_2) {
    Polynomial poly_sub;

    if (poly_1.var != poly_2.var) {
        cout << "Operator must use Polynomials with the same var value." << endl;
        return poly_sub;
    }

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
            if (poly_1.expons[idx_1] == poly_2.expons[idx_2] && poly_1.var == poly_2.var) {
                // Subtract term for common exponents.

                // Skip if subtraction leads to zero value.
                int poly_coeff;
                poly_coeff = poly_1.coeffs[idx_1] - poly_2.coeffs[idx_2];
                if (poly_coeff != 0) {
                    poly_sub.coeffs[poly_sub.term_cnt] = poly_coeff;
                    poly_sub.expons[poly_sub.term_cnt] = poly_1.expons[idx_1];
                    poly_sub.term_cnt += 1;
                    if (poly_sub.term_cnt >= poly_sub.term_capacity) {
                        poly_sub.handle_term_capacity();
                        return poly_sub;
                    }
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
            if (poly_sub.term_cnt >= poly_sub.term_capacity) {
                poly_sub.handle_term_capacity();
                return poly_sub;
            }
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
            if (poly_sub.term_cnt >= poly_sub.term_capacity) {
                poly_sub.handle_term_capacity();
                return poly_sub;
            }
        }
    }
    poly_sub.sort_by_expons();
    return poly_sub;
}


Polynomial operator*(const Polynomial& poly_1, const Polynomial& poly_2) {
    // Keep poly_mult empty and fill term by term with poly_temp.
    Polynomial poly_mult;
    Polynomial poly_temp;
    // Max terms that can be returned by multiplying two polynomials is the
    // term count squared.
    // I'm using the max term count which is defaulted to 6 and cannot be
    // changed outside a method.

    if (poly_1.var != poly_2.var) {
        cout << "Operator must use Polynomials with the same var value." << endl;
        return poly_mult;
    }

    poly_mult.max_term_cnt *= poly_mult.max_term_cnt;

    // Multiply one term at a time and add to poly_mult.
    // By using addition the terms with the same exponents will be combined.
    for (int idx_1 = 0; idx_1 < poly_1.term_cnt; idx_1++) {
        for (int idx_2 = 0; idx_2 < poly_2.term_cnt; idx_2++) {
            Polynomial poly_temp;
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
            if (poly_mult.term_cnt >= poly_mult.term_capacity) {
                // No need to call handle term capcity since print message will
                // be called from the addition operator. Just return the
                // current polynomial calculated.
                return poly_mult;
            }
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
