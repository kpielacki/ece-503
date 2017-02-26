#include <iostream>
#include <string>
using namespace std;


int get_board_size(int a[]) {
	// Gets size of array but expects all arrays to end
	// with value NULL.

	// I would of preferred to pass the array size to the
	// jump solution method but wasn't sure if that was
	// allowed and I don't want to assume.
	
	// Start at zero to ignore NULL value at end.
	int len = 0;
	bool check = true;
	while (check) {
		len++;
		if (not(a[len])) {
			check = false;
		}
	}
	return len;
}

bool check_jump_solution(int board[], int pos) {
	int move_num = board[pos];
	bool check_forward = false;
	bool check_backward = false;
	int board_size;

	// Find board size.
	board_size = get_board_size(board);

	// Set current position to -1 to skip rechecking.
	board[pos] = -1;

	// Check if board position now negative from other calls.
	if (move_num >= 0) {
		// Can only win by moving to the right.
		// If new space value is zero you are on the right most
		// peg and won the game.
		int new_pos = pos + move_num;
		if (pos + move_num == board_size - 1) {
			return true;
		} else {
			// Check forward move.
			if (new_pos < board_size - 1) {
				check_forward = check_jump_solution(board, new_pos);
			}

			// Check backward move.
			new_pos = pos - move_num;
			if (new_pos > 0) {
				check_backward = check_jump_solution(board, new_pos);
			}
		}
	} else {
		// Return unsolvable for already checked posiions.
		return false;
	}

	// Check if any forward or backward moves win the game.
	if (check_backward or check_forward) {
		return true;
	} else {
		return false;
	}
}

int main() {
	int board_size;
	int start_pos = 0;
	bool solvable;

	cout << "Enter a board size: ";
	cin >> board_size;
	// int puzzle[10] = {3, 2, 3, 1, 6, 2, 5, 1, 0, '\0'};
	int puzzle[board_size + 1];

	cout << "Enter the first " << board_size - 1 << " elements (must be positive): ";
	// Build board array.
	for (int i = 0; i < board_size - 1; i++) {
		cin >> puzzle[i];
		if (puzzle[i] < 0) {
			cout << "First elements must be postive." << endl;
			i--;
		}
	}
	// Set last board element to zero.
	puzzle[board_size] = 0;
	// Use NULL to calculate array length within function.
	puzzle[board_size + 1] = '\0';

	// Pass puzzle array and start position of zero.
	solvable = check_jump_solution(puzzle, start_pos);

	// Print if board is solvable or not.
	if (solvable) {
		cout << "This board is SOLVABLE!" << endl;
	} else {
		cout << "You can NOT solve this board." << endl;
	}

	return 0;
}