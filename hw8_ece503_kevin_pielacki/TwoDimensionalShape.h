#ifndef TWODIMENSIONALSHAPE_H
#define TWODIMENSIONALSHAPE_H
#include "Shape.h"

class TwoDimensionalShape : public Shape {

    public:
        TwoDimensionalShape(float x, float y);
        float get_x();
        void set_x(float x);
        float get_y();
        void set_y(float y);

    protected:
        float x;
        float y;

};

#endif
