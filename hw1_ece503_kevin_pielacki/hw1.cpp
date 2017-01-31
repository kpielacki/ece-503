#include <iostream>
#include <string>
#include <sstream>

using namespace std;


int main() {
    // Used to store user input for min/max comparison.
    int temp_number;
    // Stores max and min of user input.
    int max_number;
    int min_number;

    // Initially assign first number to be the max number.
    cout << "Enter your first number" << endl;
    cin >> max_number;

    // Prompt for second number into temporary variable.
    cout << "Enter your second number" << endl;
    cin >> temp_number;

    // If the first number is greater than the second number assign min_number to
    // second number otherwise assign the second number to max_number after
    // assigning the first number to min_number.
    if ( max_number > temp_number ) {
        min_number = temp_number;
    } else {
        min_number = max_number;
        max_number = temp_number;
    }

    // Ask for new number.
    cout << "Enter your third number" << endl;
    cin >> temp_number;

    // Assign new new number to either max_number or min_number if value greater
    // or less than current max_number or min_number respectively.
    if ( max_number < temp_number ) {
        max_number = temp_number;
    } else if ( min_number > temp_number ) {
        min_number = temp_number;
    }

    // Ask for new number.
    cout << "Enter your fourth number" << endl;
    cin >> temp_number;

    // Assign new new number to either max_number or min_number if value greater
    // or less than current max_number or min_number respectively.
    if ( max_number < temp_number ) {
        max_number = temp_number;
    } else if ( min_number > temp_number ) {
        min_number = temp_number;
    }

    // Ask for new number.
    cout << "Enter your fifth number" << endl;
    cin >> temp_number;

    // Assign new new number to either max_number or min_number if value greater
    // or less than current max_number or min_number respectively.
    if ( max_number < temp_number ) {
        max_number = temp_number;
    } else if ( min_number > temp_number ) {
        min_number = temp_number;
    }
    cout << "Minimum: " << min_number << endl;
    cout << "Maximum: " << max_number << endl;
}
