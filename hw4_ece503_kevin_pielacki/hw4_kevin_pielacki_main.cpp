using namespace std;
#include <iostream>
#include <vector>
#include <string>


const int max_books = 20;

void insert(int list[], int *num_in_list, int new_element) {
    // Indicate that the the insert already exists if non-negative.
    int shift_index = -1;
    // Check if more than 20 books.
    if (*num_in_list > max_books) {
        cout << "Cannot exceed more than " << max_books << " books." << endl;
        return;
    }

    for (int i = 0; i < *num_in_list; i++) {
        // Remove element, shift list, add item to last, and don't increment if
        // ISBN already exists.
        if (list[i] == new_element) {
            cout << "ISBN value " << new_element << " already exists. Moving to end of list." << endl;
            shift_index = i;
        }
    }

    if (shift_index >= 0) {
        // Shift all elements down.
        for (int i = shift_index; i < *num_in_list - 1; i++) {
            int *last = list + i;
            last = list + i + 1;
        }
        // List size did not change so subtract one.
        int *last = list + *num_in_list - 1;
        *last = new_element;
    }
    else {
        int *last = list + *num_in_list;
        *num_in_list = *num_in_list + 1;
        *last = new_element;
    }
    return;
};


void insert_at(int list[], int *num_in_list, int at_position, int new_element) {
    // For the insert_at function I'm constratining all the at_position value
    // to be within the current list's element count. Since the assignment
    // requires the initial insert to be at zero and the element counter would
    // be off otherwise I think this makes the most sense.

    // Indicate that the the insert already exists if non-negative.
    int shift_index = -1;
    // Check if more than 20 books.
    if (*num_in_list > max_books) {
        cout << "Cannot exceed more than " << max_books << " books." << endl;
        return;
    }

    // Fail if postion selection to large of negative.
    if (*num_in_list < at_position) {
        cout << "There's only " << *num_in_list << " books. The position you specified is too great." << endl;
        return;
    }
    else if (at_position < 0) {
        cout << "Position selection most be non-negative." << endl;
        return;
    }

    for (int i = 0; i < *num_in_list; i++) {
        // Remove element, shift list, add item to last, and don't increment if
        // ISBN already exists.
        if (list[i] == new_element) {
            cout << "ISBN value " << new_element << " already exists. Removing that entry and shifting to new position." << endl;
            shift_index = i;
        }
    }

    if (shift_index >= 0) {
        // Remove existing element and shift all elements down.
        for (int i = shift_index; i < *num_in_list - 1; i++) {
            int *last = list + i;
            last = list + i + 1;
            // Reduce list item count allows to reuse the next block of code
            // to insert the element to it's new position.
            *num_in_list = *num_in_list - 1;
        }
    }

    // Iterate backwards to shift elements up.
    for (int i = *num_in_list - 1; i >= at_position; i--) {
        // Remove element, shift list, add item to last, and don't increment if
        // ISBN already exists.
        cout << i << endl;
        int *last = list + i + 1;
        *last = list[i];
    }


    // Assign element to postion.
    int *last = list + at_position;
    *last = new_element;

    // Increment list item count.
    *num_in_list = *num_in_list + 1;
    return;

}



void print_list(int list[], int num_in_list) {
    for (int i=0; i < num_in_list; i++) {
        cout << list[i] << endl;
    }
};


int main() {
    bool in_menu = true;
    int user_selection;
    int books[20];
    int num_books = 0;
    int isbn_select = 0;
    int insert_pos;

    while (in_menu) {
        cout << "-----Select an Option-----" << endl;
        cout << "\t1. Insert new book at the end of the list" << endl;
        cout << "\t2. Insert new book at a certain position" << endl;
        cout << "\t3. Find a book (with its ISBN number and list its position) using linear search" << endl;
        cout << "\t4. Find a book (with its ISBN number and list its position) of a sorted list using binary search" << endl;
        cout << "\t5. Delete a book that is at a certain position" << endl;
        cout << "\t6. Delete a book by using its ISBN number" << endl;
        cout << "\t7. Sort the list of books by the ISBN numbers (using selection sort)" << endl;
        cout << "\t8. Sort the list of books by the ISBN numbers (using bubble sort)" << endl;
        cout << "\t9. Print out the list" << endl;
        cout << "\t10. Quit" << endl;
        cout << "\nPlease select a menu option: ";

        cin >> user_selection;
        switch (user_selection) {
            case 1 : {
                cout << "Select ISBN number to insert: ";
                cin >> isbn_select;
                insert(books, &num_books, isbn_select);
                break;
            }
            case 2 : {
                cout << "Select ISBN number to insert: ";
                cin >> isbn_select;
                cout << "Select a position to insert into: ";
                cin >> insert_pos;
                insert_at(books, &num_books, insert_pos, isbn_select);
                break;
                break;
            }
            case 3 : {
                break;
            }
            case 4 : {
                break;
            }
            case 5 : {
                break;
            }
            case 6 : {
                break;
            }
            case 7 : {
                break;
            }
            case 8 : {
                break;
            }
            case 9 : {
                print_list(books, num_books);
                break;
            }
            case 10 : {
                in_menu = false;
                break;
            }
            default : {
                cout << "Invalid menu option." << endl;
            }
        }
    }

    return 0;
}
