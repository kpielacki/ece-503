#ifndef SHAPE_H
#define SHAPE_H


class Shape {

    public:
        Shape();
        // Virutal functions for polymorphism.
        virtual float get_area();
        virtual float get_volume();

};

#endif
