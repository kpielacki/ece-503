#include "threedimensionalpoint.h"

ThreeDimensionalPoint::ThreeDimensionalPoint(){
	setx(0);
	sety(0);
	setz(0);
}

ThreeDimensionalPoint::ThreeDimensionalPoint(int xin, int yin, int zin) : Point(xin, yin){
	//please implement this constructor to set the x, y and z values to the input parameter values
    
    // Call parent class constructor to set x and y.
    // Take zin and set to private variable z using setter.
    setz(zin);
}
int ThreeDimensionalPoint::getz(){
	//please implement this function to get the z value
	
	// Return private variable z.
	// No need for scope since z is the only variable defined in that name.
	return z;
}
void ThreeDimensionalPoint::setz(int zin){
	//please implement this function to set z value
	
	// Take zin and set to private variable z.
	// No need for scope since z is the only variable defined in that name.
	z = zin;
}

void ThreeDimensionalPoint::addPoints(ThreeDimensionalPoint pointin){
	//please implement this function to add the x,y and z values of point1 to values of the calling instance of the object
	
	// Use the inherited and defined getters to get the value in pointin
	// and use the setters to set this object's values to pointin.
	setx(pointin.getx());
	sety(pointin.gety());
    setz(pointin.getz());
}
