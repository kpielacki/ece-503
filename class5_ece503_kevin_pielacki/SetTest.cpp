// SetTest.cpp
// Driver program for class IntegerSet.

#include <iostream>
#include <string>
using namespace std;

#include "IntegerSet.h" // IntegerSet class definition

int main() {
	IntegerSet a;
	IntegerSet b;

	cout << "Enter set A:\n";
	a.inputSet();
	cout << "\nSet A is:\n";
	a.printSet();

	cout << "\nEnter set B:\n";
	b.inputSet();
	cout << "\nSet B is:\n";
	b.printSet();

	/* Write call to unionOfSets for object a, passing b as argument and assigning the result to c */
	a.unionOfSets(b);
	IntegerSet c(a);

	cout << "\nUnion of A and B is:\n";
	c.printSet();

	/* Write call to intersectionOfSets for object a, passing b as argument and assigning the result to d */
	cout << "\nIntersection of A and B is:\n";
	a.intersectionOfSets(b);
	IntegerSet d(a);
	d.printSet();

	return 0;
}
