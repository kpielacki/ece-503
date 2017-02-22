using namespace std;

#include <iostream>
#include <string>


int get_char_cnt(string s, char c) {
	// Checks if first char in string s is equal to char
	// c and returns the result + the result of itself
	// until the string is empty.
	int char_cnt = 0;
	char first_char = s[0];
	string s_cut = s.erase(0, 1);

	// Check if first string character is the search char.
	if (first_char == c) {
		char_cnt++;
	}

	// If string is empty no need to call to get count.
	if (s_cut.empty()) {
		return char_cnt;
	}
	// Return the char counter and the result of this function.
	return char_cnt + get_char_cnt(s_cut, c);
}


int main() {
	string input_string;
	char input_char;
	int char_cnt;

	// Get user input for string.
	cout << "Enter a input string: ";
	cin >> input_string;
	// Get user input for char to search in string.
	cout << "Enter a search character: ";
	cin >> input_char;

	// Get count that char appears in string.
	char_cnt = get_char_cnt(input_string, input_char);

	cout << "The number of times '" << input_char << "' appears in '" << input_string << "' is " << char_cnt << "." << endl;
	return 0;
}