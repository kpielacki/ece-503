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
static int matrix_1[10][10];
static int matrix_2[10][10];
static int result_matrix[10][10];
static int matrix_1_rows;
static int matrix_1_cols;
static int matrix_2_rows;
static int matrix_2_cols;
static int result_matrix_rows;
static int result_matrix_cols;

void print_matrix(int matrix[][10], int matrix_num) {
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
			cout << "Bad matrix print choice." << endl;
			return;
		}
	}

    for (int row_index=0; row_index < row_num; row_index++) {
        for (int col_index=0; col_index < col_num; col_index++) {
            cout << matrix[row_index][col_index] << "\t";
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

    cout << "Enter matrix element values:" << endl;
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
    		cout << "Bad matrix creation number choice." << endl;
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
		// Same size so just use one matrix dimensions.
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
		// First matrix iteration.
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
		cout << "First matrix column count must match second matrix row count." << endl;
		return 1;
	}
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
				create_matrix(2);
				multiply_matrices();
				break;
			}
			case 4 : {
				create_matrix(1);
				// result_matrix = transpose_matrix(matrix_1);
				cout << "The result is:" << endl;
				// print_matrix(result_matrix);
				break;
			}
			case 5 : {
				int det;
				create_matrix(1);
				// det = get_determinant_3x3(matrix_1);
				cout << "The result is:" << det << endl;
				break;
			}
			case 6 : {
				create_matrix(1);
				// get_inverse_3x3(matrix_1);
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
