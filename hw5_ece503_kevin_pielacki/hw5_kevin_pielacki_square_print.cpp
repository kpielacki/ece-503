#include <iostream>
#include <vector>
using namespace std;


void recurse_square_print(int n) {
	// Takes int value and prints square of odd numbers descending
	// followed by square of even number ascending with comma
	// seperated values.

	if (n >= 0) {
	    if (n % 2 == 1) {
	    	// Set pointer value to next odd number desc.
	    	int new_n = n - 2;
	    	int next_even_n = n - 1;

	    	// Check to add comma after square print.
	    	// During the positive print the comma will begin
	    	// the console output instead of end it.
	    	if (n == 1) {
	    		cout << n * n;
	    	}
	    	else {
		    	cout << n * n << ", ";
	    	}
		    recurse_square_print(new_n);
		    // Only print postive n.
		    if (next_even_n > 0) {
		    	cout << ", " << next_even_n * next_even_n;
		    }
	    } else {
	    	// Move to next odd number.
	    	int new_n = n - 1;
	    	// Odd number prints.
		    recurse_square_print(new_n);
		    // Need to print even number from first function call.
		    cout << ", " << n * n << endl;
	    }
	}
	return;
}


int main() {
	// Gets user input to call recursive square print.
	int n = -1;

	// Exclude non-positive integers.
    while (n <= 0) {
        cout << "Enter a positive integer: ";
        cin >> n;
        if (n <= 0) {
        	// Tell user integers must be positive.
            cout << "Integer must be positive." << endl;
        }
    }
    recurse_square_print(n);
    return 0;
}
