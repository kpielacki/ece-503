using namespace std;
#include <iostream>
#include <vector>
#include <string>


void print_matrix(vector<vector<int>> matrix) {
	for (int row_index=0; row_index < matrix.size(); row_index++) {
		for (int col_index=0; col_index < matrix[row_index].size(); col_index++) {
			cout << matrix[row_index][col_index] << "\t";
		}
		cout << endl;
	}
}


vector<vector<int>> create_matrix() {
	int row_count = 11;
	int col_count = 11;
	vector<vector<int>> matrix_values;
	int element_value;

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
	// Fill row and column values.
	for (int row_index=0; row_index < row_count; row_index++) {
		// Values for the entire row.
		vector<int> row_values;
		for (int col_index=0; col_index < col_count; col_index++) {
			cin >> element_value;
			row_values.push_back(element_value);
		}
		matrix_values.push_back(row_values);
	}
	cout << "Your input is:" << endl;
	print_matrix(matrix_values);
	return matrix_values;
}


int add_sub_matrices(vector<vector<int>> matrix_1, vector<vector<int>> matrix_2, bool sub=false) {
	int mult;
	vector<vector<int>> result_matrix;
	
	// Optional arugment to perform subtraction.
	if ( sub ) {
		mult = -1;
	} else {
		mult = 1;
	}
	
	// Check if matrices same dimensions.
	if ( matrix_1.size() == matrix_2.size() && matrix_1[0].size() == matrix_2[0].size() ) {
		for (int row_index=0; row_index < matrix_1.size(); row_index++) {
			vector<int> row_values;
			for (int col_index=0; col_index < matrix_1[row_index].size(); col_index++) {
				row_values.push_back(matrix_1[row_index][col_index] + mult * matrix_2[row_index][col_index]);
			}
			result_matrix.push_back(row_values);
		}
		cout << "The result is:" << endl;
		print_matrix(result_matrix);
		return 0;
	} else {
		cout << "Matrices must have the same dimensions for this operation." << endl;
		return 1;
	}
}


int multiply_matrices(vector<vector<int>> matrix_1, vector<vector<int>> matrix_2) {
	vector<vector<int>> result_matrix;

	// Check if multiplication possible.
	if ( matrix_1[0].size() == matrix_2.size() ) {
		// First matrix iteration.
		for (int row_index=0; row_index < matrix_1.size(); row_index++) {
			// Result vector for entire row in result matrix.
			vector<int> row_values;
			// Store sum value of row by column multiplication.
			for (int col_index_2=0; col_index_2 < matrix_2[0].size(); col_index_2++) {
				int element_value = 0;
				for (int col_index=0; col_index < matrix_1[row_index].size(); col_index++) {
					// Add value until full matrix_1 columns iteration.
					element_value += matrix_1[row_index][col_index] * matrix_2[col_index][col_index_2];
				}
				// Store element_value to row_values.
				row_values.push_back(element_value);
			}
			// Assign new row values to result_matrix.
			result_matrix.push_back(row_values);
		}
		cout << "The result is:" << endl;
		print_matrix(result_matrix);
		return 0;
	} else {
		cout << "First matrix column count must match second matrix row count." << endl;
		return 1;
	}
}


vector<vector<int>> transpose_matrix(vector<vector<int>> matrix) {
	// Initiate transposed matrix.
	vector<vector<int>> matrix_t;
	// Used to condition interation through input matrix.
	const int row_cnt_in = matrix.size();
	const int col_cnt_in = matrix[0].size();
	
	// Iterate through columns and then rows. Similar to reassigning
	// col_index and row_index to each other's values.
	for ( int col_index=0; col_index < col_cnt_in; col_index++ ) {
		// Reintialize to fill new row values through each column index.
		vector<int> row_values;
		for ( int row_index=0; row_index < row_cnt_in; row_index++ ) {
			row_values.push_back(matrix[row_index][col_index]);
		}
		// Assign row values to row in matrix_t.
		matrix_t.push_back(row_values);
	}
	return matrix_t;
}


int get_determinant_3x3(vector<vector<int>> matrix) {
	// Ensure that the passed matrix is a 3x3 matrix.
	// Might make sense to have this check before the function
	// to save the user time.
	int det;
	if ( matrix.size() == 3 && matrix[0].size() == 3 ) {
		// Since we're restricting input to 3x3 this is just a very blunt equation.
		det = (
			matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1])
		) - (
			matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0])
		) + (
			matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0])
		);
	} else {
		cout << "This operation only supports 3x3 matrices." << endl;
	}
	return det;
}


void get_inverse_3x3(vector<vector<int>> matrix) {
	// Ensure that the passed matrix is a 3x3 matrix.
	// Might make sense to have this check before the function
	// to save the user time.
	if ( matrix.size() == 3 && matrix[0].size() == 3 ) {
		// Calculate 3x3 adjoint of input matrix.
		vector<vector<int>> result_matrix;

		int row_offset_1;
		int row_offset_2;
		int col_offset_1;
		int col_offset_2;
		int coeff = 1;
		int det;
		det = get_determinant_3x3(matrix);

		// Calculate the adjoint of the matrix over the determinant and transpose.
		// http://www.mathwords.com/a/adjoint.htm
		// http://www.purplemath.com/modules/mtrxinvr.htm
		for (int row = 0; row < matrix[0].size(); row++) {

			// Offsets values for cross mult.
			row_offset_1 = row - 1;
			row_offset_2 = row + 1;
			if (row_offset_1 < 0) {
				row_offset_1 = 1;
				row_offset_2 = row_offset_1 + 1;
			} else if (row_offset_2 >= matrix[0].size()) {
				row_offset_1 = 0;
				row_offset_2 = row_offset_1 + 1;
			}
			// Stores entire row values.
			vector<int> row_values;
			for (int col = 0; col < matrix.size(); col++) {
				// Offsets values for cross mult.
				col_offset_1 = col - 1;
				col_offset_2 = col + 1;
				if (col_offset_1 < 0) {
					col_offset_1 = 1;
					col_offset_2 = col_offset_1 + 1;
				} else if (col_offset_2 >= matrix[0].size()) {
					col_offset_1 = 0;
					col_offset_2 = col_offset_1 + 1;
				}

				row_values.push_back(coeff/det * (matrix[row_offset_1][col_offset_1] * matrix[row_offset_2][col_offset_2] - matrix[row_offset_1][col_offset_2] * matrix[row_offset_2][col_offset_1]));
				// Toggle +- coeffecient.
				coeff *= -1;
			}
			result_matrix.push_back(row_values);
		}
		// Using previous transpose function.
		result_matrix = transpose_matrix(result_matrix);
		cout << "The result is:" << endl;
		print_matrix(result_matrix);
	} else {
		cout << "This operation only supports 3x3 matrices." << endl;
	}
	return;
}

int main() {
	bool show_menu = true;
	int menu_selection;
	// All functions require at most 2 matrices.
	// No need to reinitialize at new menu selection.
	vector<vector<int>> matrix_1;
	vector<vector<int>> matrix_2;
	vector<vector<int>> result_matrix;
	

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
				matrix_1 = create_matrix();
				matrix_2 = create_matrix();

				add_sub_matrices(matrix_1, matrix_2);
				break;
			}
			case 2 : {
				matrix_1 = create_matrix();
				matrix_2 = create_matrix();

				// I'm using an additional argument to perform subtraction
				// since the addition and subtraction function is almost
				// exact aside from the operation.
				add_sub_matrices(matrix_1, matrix_2, true);
				break;
			}
			case 3 : {
				matrix_1 = create_matrix();
				matrix_2 = create_matrix();
				multiply_matrices(matrix_1, matrix_2);
				break;
			}
			case 4 : {
				matrix_1 = create_matrix();
				result_matrix = transpose_matrix(matrix_1);
				cout << "The result is:" << endl;
				print_matrix(result_matrix);
				break;
			}
			case 5 : {
				int det;
				matrix_1 = create_matrix();
				det = get_determinant_3x3(matrix_1);
				cout << "The result is:" << det << endl;
				break;
			}
			case 6 : {
				matrix_1 = create_matrix();
				get_inverse_3x3(matrix_1);
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
