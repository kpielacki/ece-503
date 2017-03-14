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

    private:
        int min_term_cnt;
        int max_term_cnt;
        char var;
        int coeffs[6];
        int expons[6];
        int term_cnt;

        void set_term_cnt();
        void set_term(int term_idx);
};

#endif
