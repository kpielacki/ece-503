using namespace std;
#include <iostream>


int main() {
	int num_lines;

	cout << "Enter the number of lines to print: ";
	cin >> num_lines;

	for (int i = 0; i < num_lines; i++ ) {
		for ( int j = 0; j <= i; j++ ) {
			cout << "*";
		}
		cout << endl;
	}

	return 0;
}