#ifndef TETRAHEDRON_H
#define TETRAHEDRON_H
#include "ThreeDimensionalShape.h"


class Tetrahedron : public ThreeDimensionalShape {
    
    public:
        Tetrahedron(float x_val, float y_val, float z_val, float side_length_val);
        float get_side_length();
        void set_side_length(float side_length_val);
        float get_area();
        float get_volume();
    
    private:
        float side_length;

};


#endif
