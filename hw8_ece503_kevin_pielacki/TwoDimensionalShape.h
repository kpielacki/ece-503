#ifndef TWODIMENSIONALSHAPE_H
#define TWODIMENSIONALSHAPE_H
#include "Shape.h"

class TwoDimensionalShape : public Shape {

    public:
        TwoDimensionalShape(float x_val, float y_val);
        float get_x();
        void set_x(float x_val);
        float get_y();
        void set_y(float y_val);

    private:
        // No need to set to protected. Let getters and
        // setters handle interaction.
        float x;
        float y;

};

#endif
