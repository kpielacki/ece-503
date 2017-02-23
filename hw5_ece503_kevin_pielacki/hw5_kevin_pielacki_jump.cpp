#include <iostream>
#include <string>
using namespace std;

int board_size = 9;


bool check_jump_solution(int board[], int pos) {
	int move_num = board[pos];
	bool check_forward = false;
	bool check_backward = false;

	// Set current position to -1 to skip rechecking.
	board[pos] = -1;

	// Check if board position now negative from other calls.
	if (move_num >= 0) {
		// Can only win by moving to the right.
		// If new space value is zero you are on the right most
		// peg and won the game.
		if (board[pos + move_num] == 0) {
			return true;
		} else {
			int new_pos = pos + move_num;

			// Check forward move.
			if (new_pos < board_size) {
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
	int puzzle[board_size] = {3, 2, 3, 1, 6, 2, 5, 1, 0};
	int start_pos = 0;
	bool solvable;

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