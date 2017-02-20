using namespace std;
#include <iostream>
#include <sstream>
#include <string>

// I might be misuderstanding what you meant by using matrices but I
// interpretted that as using 2D arrays. Returning a 2D array causes you to
// knowing all the dimensions. There's a few ways around this but I'm assuming
// we can't dynmaically allocate memeory for creating the arrays so I'm
// defining two input arrays with the max allowed dimensions and integer
// variables to keep track of their dimensions. These are all global variables
// so they can be shared for all the functions but it would make more senese if
// they were included as a structure or object.
static float matrix_1[10][10];
static float matrix_2[10][10];
static float result_matrix[10][10];
static int matrix_1_rows;
static int matrix_1_cols;
static int matrix_2_rows;
static int matrix_2_cols;
static int result_matrix_rows;
static int result_matrix_cols;

void print_matrix(float matrix_1[][10], int matrix_num) {
	int row_num;
	int col_num;
	switch (matrix_num) {
		case 1: {
			row_num = matrix_1_rows;
			col_num = matrix_1_cols;
			break;
		} case 2: {
			row_num = matrix_2_rows;
			col_num = matrix_2_cols;
			break;
		} case 3: {
			row_num = result_matrix_rows;
			col_num = result_matrix_cols;
			break;
		}
		default : {
			cout << "Bad matrix_1 print choice." << endl;
			return;
		}
	}

    for (int row_index=0; row_index < row_num; row_index++) {
        for (int col_index=0; col_index < col_num; col_index++) {
            cout << matrix_1[row_index][col_index] << "\t";
        }
        cout << endl;
    }
}


void create_matrix(int matrix_num) {
    int row_count = 11;
    int col_count = 11;
    int matrix_values[10][10];

    while ( row_count > 10 ) {
        cout << "Enter number of rows 10 or less: ";
        cin >> row_count;
        if ( row_count > 10 ) {
            cout << "To many rows entered." << endl;
        }
        if ( row_count < 1 ) {
            cout << "matrix_1 must have 1 or more rows." << endl;
        }
    }
    while ( col_count > 10 ) {
        cout << "Enter number of columns 10 or less: ";
        cin >> col_count;
        if ( col_count > 10 ) {
            cout << "To many columns entered." << endl;
        }
        if ( col_count < 1 ) {
            cout << "matrix_1 must have 1 or more columns." << endl;
        }
    }

    cout << "Enter matrix_1 element values:" << endl;
    // Fill row and column values

    switch (matrix_num) {
    	case 1: {
		    matrix_1_rows = row_count;
		    matrix_1_cols = col_count;
		    for (int row_index=0; row_index < row_count; row_index++) {
		        for (int col_index=0; col_index < col_count; col_index++) {
		            cin >> matrix_1[row_index][col_index];
		        }
		    }
		    break;
    	} case 2: {
		    matrix_2_rows = row_count;
		    matrix_2_cols = col_count;
    		for (int row_index=0; row_index < row_count; row_index++) {
		        for (int col_index=0; col_index < col_count; col_index++) {
		            cin >> matrix_2[row_index][col_index];
		        }
		    }
		    break;
    	} default : {
    		cout << "Bad matrix_1 creation number choice." << endl;
    		return;
    	}
    }
    return;
}


int add_sub_matrices(bool sub=false) {
	int mult;

	// Optional arugment to perform subtraction.
	if ( sub ) {
		mult = -1;
	} else {
		mult = 1;
	}

	// Check if matrices same dimensions.
	if ( matrix_1_rows == matrix_2_rows && matrix_1_cols == matrix_2_cols ) {
		for (int row_index=0; row_index < matrix_1_rows; row_index++) {
			for (int col_index=0; col_index < matrix_1_cols; col_index++) {
				result_matrix[row_index][col_index] = matrix_1[row_index][col_index] + mult * matrix_2[row_index][col_index];
			}
		}
		// Same size so just use one matrix_1 dimensions.
		result_matrix_rows = matrix_2_rows;
		result_matrix_cols = matrix_2_cols;
		cout << "The result is:" << endl;
		print_matrix(result_matrix, 3);
		return 0;
	} else {
		cout << "Matrices must have the same dimensions for this operation." << endl;
		return 1;
	}
}


int multiply_matrices() {
	// Check if multiplication possible.
	if ( matrix_1_cols == matrix_2_rows ) {
		// First matrix_1 iteration.
		for (int row_index=0; row_index < matrix_1_rows; row_index++) {
			// Store sum value of row by column multiplication.
			for (int col_index_2=0; col_index_2 < matrix_2_cols; col_index_2++) {
				int element_value = 0;
				for (int col_index=0; col_index < matrix_1_cols; col_index++) {
					// Add value until full matrix_1 columns iteration.
					element_value += matrix_1[row_index][col_index] * matrix_2[col_index][col_index_2];
				}
				// Store element_value to row_values.
				result_matrix[row_index][col_index_2] = element_value;
			}
		}
		result_matrix_rows = matrix_1_rows;
		result_matrix_cols = matrix_2_cols;
		cout << "The result is:" << endl;
		print_matrix(result_matrix, 3);
		return 0;
	} else {
		cout << "First matrix_1 column count must match second matrix_1 row count." << endl;
		return 1;
	}
}


void transpose_matrix() {
	// Iterate through columns and then rows. Similar to reassigning
	// col_index and row_index to each other's values.
	for ( int col_index=0; col_index < matrix_1_cols; col_index++ ) {
		// Reintialize to fill new row values through each column index.
		for ( int row_index=0; row_index < matrix_1_rows; row_index++ ) {
			result_matrix[col_index][row_index] = matrix_1[row_index][col_index];
		}
		// Assign row values to row in matrix_t.
	}
	// Opposite dimensions
	result_matrix_rows = matrix_1_cols;
	result_matrix_cols = matrix_1_rows;
	return;
}


int get_determinant_3x3() {
	// Ensure that the passed matrix_1 is a 3x3 matrix_1.
	// Might make sense to have this check before the function
	// to save the user time.
	float det;
	if ( matrix_1_rows == 3 && matrix_1_cols == 3 ) {
		// Since we're restricting input to 3x3 this is just a very blunt equation.
		det = (
			matrix_1[0][0] * (matrix_1[1][1] * matrix_1[2][2] - matrix_1[1][2] * matrix_1[2][1])
		) - (
			matrix_1[0][1] * (matrix_1[1][0] * matrix_1[2][2] - matrix_1[1][2] * matrix_1[2][0])
		) + (
			matrix_1[0][2] * (matrix_1[1][0] * matrix_1[2][1] - matrix_1[1][1] * matrix_1[2][0])
		);
		// It makes more sense for some of these print statements to be called
		// outside the function howerver I'm avoiding dupicate prints on bad
		// user input. The else statement should really be handled as an
		// exception instead.
		cout << "The result is: " << det << endl;
	} else {
		cout << "This operation only supports 3x3 matrices." << endl;
	}
	return det;
}


void get_inverse_3x3() {
	// Ensure that the passed matrix_1 is a 3x3 matrix_1.
	// Might make sense to have this check before the function
	// to save the user time.
	if ( matrix_1_rows == 3 && matrix_1_cols == 3 ) {
		// Calculate 3x3 adjoint of input matrix_1.
		int row_offset_1;
		int row_offset_2;
		int col_offset_1;
		int col_offset_2;
		int coeff = 1;
		float det;
		det = get_determinant_3x3();

		// Calculate the adjoint of the matrix_1 over the determinant and transpose.
		// http://www.mathwords.com/a/adjoint.htm
		// http://www.purplemath.com/modules/mtrxinvr.htm
		for (int row = 0; row < matrix_1_cols; row++) {

			// Offsets values for cross mult.
			row_offset_1 = row - 1;
			row_offset_2 = row + 1;
			if (row_offset_1 < 0) {
				row_offset_1 = 1;
				row_offset_2 = row_offset_1 + 1;
			} else if (row_offset_2 >= matrix_1_cols) {
				row_offset_1 = 0;
				row_offset_2 = row_offset_1 + 1;
			}
			for (int col = 0; col < matrix_1_rows; col++) {
				// Offsets values for cross mult.
				col_offset_1 = col - 1;
				col_offset_2 = col + 1;
				if (col_offset_1 < 0) {
					col_offset_1 = 1;
					col_offset_2 = col_offset_1 + 1;
				} else if (col_offset_2 >= matrix_1_cols) {
					col_offset_1 = 0;
					col_offset_2 = col_offset_1 + 1;
				}
				// In my vectors version I had it call the traspose code but
				// it makes more sense just to swap the column and row values
				// here like this.
				result_matrix[col][row] = coeff/det * (matrix_1[row_offset_1][col_offset_1] * matrix_1[row_offset_2][col_offset_2] - matrix_1[row_offset_1][col_offset_2] * matrix_1[row_offset_2][col_offset_1]);
				// Toggle +- coeffecient.
				coeff *= -1;
			}
		}
		// Same size matrix if 3x3.
		result_matrix_rows = matrix_1_cols;
		result_matrix_cols = matrix_1_rows;
		cout << "The result is:" << endl;
		print_matrix(result_matrix, 3);
	} else {
		cout << "This operation only supports 3x3 matrices." << endl;
	}
	return;
}


int main() {
	bool show_menu = true;
	int menu_selection;

	while ( show_menu ) {
		cout << "Menu" << endl;
		cout << "\tChoice 1: Addition" << endl;
		cout << "\tChoice 2: Subtraction" << endl;
		cout << "\tChoice 3: Multiplication" << endl;
		cout << "\tChoice 4: Transpose" << endl;
		cout << "\tChoice 5: Determinant (3x3 Only)" << endl;
		cout << "\tChoice 6: Inverse (3x3 Only)" << endl;
		cout << "\tChoice 7: Quit" << endl;
		cout << "Enter your choice: ";

		cin >> menu_selection;
		// Menu selection for matrix_1 operations.
		switch(menu_selection) {
			case 1 : {
				create_matrix(1);
				cout << "Your input is:" << endl;
				print_matrix(matrix_1, 1);
				create_matrix(2);
				cout << "Your input is:" << endl;
				print_matrix(matrix_2, 2);

				// I'm using an additional argument to perform subtraction
				// since the addition and subtraction function is almost
				// exact aside from the operation.
				add_sub_matrices(false);
				break;
			}
			case 2 : {
				create_matrix(1);
				cout << "Your input is:" << endl;
				print_matrix(matrix_1, 1);
				create_matrix(2);
				cout << "Your input is:" << endl;
				print_matrix(matrix_2, 2);

				// I'm using an additional argument to perform subtraction
				// since the addition and subtraction function is almost
				// exact aside from the operation.
				add_sub_matrices(true);

				break;
			}
			case 3 : {
				create_matrix(1);
				cout << "Your input is:" << endl;
				print_matrix(matrix_1, 1);
				create_matrix(2);
				cout << "Your input is:" << endl;
				print_matrix(matrix_2, 2);
				multiply_matrices();
				break;
			}
			case 4 : {
				create_matrix(1);
				cout << "Your input is:" << endl;
				print_matrix(matrix_1, 1);
				transpose_matrix();
				cout << "The result is:" << endl;
				print_matrix(result_matrix, 3);
				break;
			}
			case 5 : {
				float det;
				create_matrix(1);
				cout << "Your input is:" << endl;
				print_matrix(matrix_1, 1);
				det = get_determinant_3x3();
				break;
			}
			case 6 : {
				create_matrix(1);
				cout << "Your input is:" << endl;
				print_matrix(matrix_1, 1);
				get_inverse_3x3();
				break;
			}
			case 7 : {
				// Exit while loop.
				show_menu = false;
				break;
			}
			default : cout << "Invalid choice, try again." << endl;
		}
	}

	return 0;
}
