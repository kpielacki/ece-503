#ifndef CIRCLE_H
#define CIRCLE_H
#include "TwoDimensionalShape.h"


class Circle : public TwoDimensionalShape {
    
    public:
        Circle(float x_val, float y_val, float radius_val);
        float get_radius();
        void set_radius(float radius_val);
        float get_area();
    
    private:
        float radius;

};


#endif
