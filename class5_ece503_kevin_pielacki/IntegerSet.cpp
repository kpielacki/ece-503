// IntegerSet.cpp
// Member-function definitions for class IntegerSet.

#include <iostream>
#include <iomanip>
using namespace std;

/* Write include directive for IntegerSet.h here */
#include "IntegerSet.h"

// constructor
IntegerSet::IntegerSet() {
	for (int i = 0; i < 101; i++) {
		set[i] = 0;
	}
} // end IntegerSet constructor


IntegerSet::IntegerSet(int set[101]) {
	for (int i; i < 101; i++) {
		if (validEntry(i)) {
			set[i] = 1;
		} else {
			set[i] = 0;
		}
	}
}


// input a set from the user
void IntegerSet::inputSet() {
	int number;
	do {
		cout << "Enter an element (-1 to end): ";
		cin >> number;

		if (validEntry(number)) {
			set[number] = 1;
		} else if (number != -1) {
			cout << "Invalid Element\n";
		}
	} while (number != -1); // end do...while

	cout << "Entry complete\n";
} // end function inputSet


// prints the set to the output stream
void IntegerSet::printSet() const {
	cout << "{ ";
	for (int u = 0; u < 101; u++) {
		if (set[u]) {
			cout << u << " "; 
		}
	}
	cout << "}" << endl;
} // end function printSet


/* Write definition for unionOfSets */
void IntegerSet::unionOfSets(IntegerSet set_2) {
	for (int i = 0; i < 100; i++) {
		// cout << IntegerSet::set[i]
		if (set[i] or set_2.set[i]) {
			// No need to validate entry since built off other sets.
			set[i] = 1;
		} else {
			set[i] = 0;
		}
	}
}


/* Write definition for intersectionOfSets */
void IntegerSet::intersectionOfSets(IntegerSet set_2) {
	for (int i = 0; i < 100; i++) {
		// cout << IntegerSet::set[i]
		if (set[i] and set_2.set[i]) {
			// No need to validate entry since built off other sets.
			set[i] = 1;
		} else {
			set[i] = 0;
		}
	}
}