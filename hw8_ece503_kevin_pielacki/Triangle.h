#ifndef TRIANGLE_H
#define TRIANGLE_H

class Triangle : public TwoDimensionalShape {

    public:
        Triangle(float x_val, float y_val, float side_length_val);
        float get_side_length();
        void set_side_length(float side_length_val);
        float get_area();

    private:
        float side_length;

};

#endif
