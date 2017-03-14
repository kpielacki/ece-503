#ifndef Polynomial_H
#define Polynomial_H


class Polynomial {

    public:
        Polynomial(bool set_terms);
        ~Polynomial();

        // Overloaded functions must be freinds to access private members.
        friend std::ostream& operator<<(std::ostream&, const Polynomial&);
        friend Polynomial operator+(const Polynomial& poly_1, const Polynomial& poly_2);
        friend Polynomial operator-(const Polynomial& poly_1, const Polynomial& poly_2);
        friend Polynomial operator*(const Polynomial& poly_1, const Polynomial& poly_2);
        Polynomial& operator=(const Polynomial& poly_2);
        Polynomial& operator+=(const Polynomial& poly_2);
        Polynomial& operator-=(const Polynomial& poly_2);
        Polynomial& operator*=(const Polynomial& poly_2);

    private:
        int min_term_cnt;
        int max_term_cnt;
        char var;

        // I'm initializing the array size to be 36 even though the term count
        // max is set to be 6. The reason why is the maximum amount of terms
        // that can occur after the multiplication operation is 36 if all
        // resulting exponents are unique.
        // I could of just refused the operation if the resulting Polynomial
        // had too many terms but I think a better solution is to allow
        // operations that can result in more terms access to the max_term_cnt
        // by declaring them friends and return a Polynomial with that value.
        // Problem is if the user keeps applying these operations afterwards
        // the result can have even more terms so without creating a dynamic
        // array to handle this new limit the operation would result in an
        // error.
        int coeffs[36];
        int expons[36];
        int term_cnt;

        void set_term_cnt();
        void set_term(int term_idx);
        void sort_by_expons();
};

#endif
