using namespace std;
#include <iostream>


int main() {
	// Store user input for number of lines to print.
	int num_lines;

	cout << "Enter the number of lines to print: ";
	cin >> num_lines;

	// Iterate through lines
	for (int i = 0; i < num_lines; i++ ) {
		// Iterate through star print.
		for ( int j = 0; j <= i; j++ ) {
			cout << "*";
		}
		// After star print begin new line.
		cout << endl;
	}

	return 0;
}