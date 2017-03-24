#ifndef THREEDIMENSIONALSHAPE_H
#define THREEDIMENSIONALSHAPE_H
#include "Shape.h"

class ThreeDimensionalShape : public Shape {

    public:
        ThreeDimensionalShape(float x_val, float y_val, float z_val);
        float get_x();
        void set_x(float x_val);
        float get_y();
        void set_y(float y_val);
        float get_z();
        void set_z(float z_val);

    private:
        float x;
        float y;
        float z;

};

#endif
