#ifndef CIRCLE_H
#define CIRCLE_H
#include "TwoDimensionalShape.h"


class Circle : public TwoDimensionalShape {
    
    public:
        Circle(float x, float y, float radius);
        float get_radius();
        void set_radius(float radius);
    
    private:
        float radius;

};


#endif
