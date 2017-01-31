using namespace std;
#include <iostream>


int main() {
	int num_stars;
	int diamond_center;

	cout << "Enter the maximum number of stars in each line: ";
	cin >> num_stars;

	// Used to check left, right, top, and bottom center of diamond.
	diamond_center = (num_stars - 1) / 2;

	// Check if user entered an odd number.
	if ( num_stars % 2 == 1 ) {
		// Iterate through row index
		for ( int line_num = 0; line_num < num_stars; line_num++ ) {
			// Iterate through  column index.
			for ( int col_num = 0; col_num < num_stars; col_num++ ) {
				// If true print top half of diamond.
				if ( line_num <= diamond_center  ) {
					// Constrain star print to center of diamond depending on line number.
					// LH: Start point of stars
					// RH: End point of stars increment as a fucntion of line_num
					if ( col_num >= diamond_center - line_num and col_num <= diamond_center + line_num ) {
						cout << "*";
					} else {
						cout << " ";
					}
				} else {
					// Constrain star print to center of diamond depending on line number.
					// LH: Start point of stars
					// RH: End point of stars decrement as a fucntion of line_num
					if ( col_num >= line_num - diamond_center and col_num <=  3 * diamond_center - line_num ) {
						cout << "*";
					} else {
						cout << " ";
					}
				}
			}
			// Move to new line
			cout << endl;
		}
	} else {
		// Ask user to enter an odd number.
		cout << "Please only enter an odd number" << endl;
	}


	return 0;
}
