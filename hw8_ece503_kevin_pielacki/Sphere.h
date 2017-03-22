#ifndef SPHERE_H
#define SPHERE_H
#include "ThreeDimensionalShape.h"


class Sphere : public ThreeDimensionalShape {
    
    public:
        Sphere(float x_val, float y_val, float z_val, float radius_val);
        float get_radius();
        void set_radius(float radius_val);
        float get_area();
    
    private:
        float radius;

};


#endif
