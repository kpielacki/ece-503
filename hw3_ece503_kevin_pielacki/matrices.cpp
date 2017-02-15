using namespace std;
#include <iostream>
#include <sstream>
#include <vector>


int *[10] create_matrix() {
	int row_count = 11;
	int col_count = 11;

	while ( row_count > 10 ) {
		cout << "Enter number of rows 10 or less: ";
		cin >> row_count;
		if ( row_count > 10 ) {
			cout << "To many rows entered." << endl;
		}
		if ( row_count < 1 ) {
			cout << "Matrix must have 1 or more rows." << endl;
		}
	}
	while ( col_count > 10 ) {
		cout << "Enter number of columns 10 or less: ";
		cin >> col_count;
		if ( col_count > 10 ) {
			cout << "To many columns entered." << endl;
		}
		if ( col_count < 1 ) {
			cout << "Matrix must have 1 or more columns." << endl;
		}
	}
	
	// Create empty matrix with input size
	int matrix_values[row_count][col_count];

	cout << "Enter matrix element values:" << endl;
	// Fill row and column values
	for (int row_index=0; row_index < row_count; row_index++) {
		for (int col_index=0; col_index < col_count; col_index++) {
			cin >> matrix_values[row_index][col_index];
		}
	}
	return matrix_values;
}


// void print_matrix(int matrix) {
// 	int row_count = sizeof(matrix[0]) / sizeof(int);
// 	int col_count = sizeof(matrix) / (row_count * sizeof(int));
	
// 	for (int row_index=0; row_index < row_count; row_index++) {
// 		for (int col_index=0; col_index < col_count; col_index++) {
// 			cout << matrix_values[row_index][col_index] << "\t";
// 		}
// 		cout << endl;
// 	}
// }

int main() {
	int ** matrix_1;

	matrix_1 = create_matrix();
	// print_matrix(matrix);
	return 0;
}
