#include <iostream>
#include <string>
#include "Booklist_pielacki.h"


int main() {
    bool in_menu = true;
    int user_selection;
    int isbn_select = 0;
    int pos_select;

    // Instantiate object of type BookList.
    BookList mybooks;

    while (in_menu) {
        // Menu print for method selection.
        std::cout << "-----Select an Option-----" << std::endl;
        std::cout << " 1. Insert new book at the end of the list" << std::endl;
        std::cout << " 2. Insert new book at a certain position" << std::endl;
        std::cout << " 3. Find a book (with its ISBN number and list its position) using linear search" << std::endl;
        std::cout << " 4. Find a book (with its ISBN number and list its position) of a sorted list using binary search" << std::endl;
        std::cout << " 5. Delete a book that is at a certain position" << std::endl;
        std::cout << " 6. Delete a book by using its ISBN number" << std::endl;
        std::cout << " 7. Sort the list of books by the ISBN numbers (using selection sort)" << std::endl;
        std::cout << " 8. Sort the list of books by the ISBN numbers (using bubble sort)" << std::endl;
        std::cout << " 9. Print out the list" << std::endl;
        std::cout << " 10. Quit" << std::endl;
        std::cout << "\nPlease select a menu option: ";

        // Get user selection and call proper BookList method for operation.
        std::cin >> user_selection;
        switch (user_selection) {
            case 1 : {
                std::cout << "Select ISBN number to insert: ";
                std::cin >> isbn_select;
                mybooks.insert(isbn_select);
                break;
            }
            case 2 : {
                std::cout << "Select ISBN number to insert: ";
                std::cin >> isbn_select;
                std::cout << "Select a position to insert into: ";
                std::cin >> pos_select;
                mybooks.insert_at(pos_select, isbn_select);
                break;
            }
            case 3 : {
                std::cout << "Select ISBN number to find: ";
                std::cin >> isbn_select;
                pos_select = mybooks.find_book(isbn_select);
                if (pos_select < 0) {
                    std::cout << "No book found for ISBN " << isbn_select << "."
                    << std::endl;
                } else {
                    // Returning user friendly index + 1.
                    std::cout << "ISBN " << isbn_select << " is in position "
                    << pos_select + 1 << "." << std::endl;
                }
                break;
            }
            case 4 : {
                // Check if the list is sorted.
                if (mybooks.get_sorted()) {
                    std::cout << "Select ISBN number to find: ";
                    std::cin >> isbn_select;
                    pos_select = mybooks.find_book_binary(isbn_select);
                    if (pos_select < 0) {
                        std::cout << "No book found for ISBN " << isbn_select << "."
                        << std::endl;
                    } else {
                        // Returning user friendly index + 1.
                        std::cout << "ISBN " << isbn_select << " is in position "
                        << pos_select + 1 << "." << std::endl;
                    }
                } else {
                    std::cout << "Your book list needs to be sorted before using this operation." << std::endl;
                }
                break;
            }
            case 5 : {
                std::cout << "Select a position to delete: ";
                std::cin >> pos_select;
                mybooks.delete_at(pos_select);
                break;
            }
            case 6 : {
                std::cout << "Select an ISBN to delete from your list: ";
                std::cin >> isbn_select;
                mybooks.delete_isbn(isbn_select);
                break;
            }
            case 7 : {
                mybooks.sort_books_selection();
                break;
            }
            case 8 : {
                mybooks.sort_books_bubble();
                break;
            }
            case 9 : {
                mybooks.print_list();
                break;
            }
            case 10 : {
                in_menu = false;
                break;
            }
            default : {
                std::cout << "Invalid menu option." << std::endl;
            }
        }
    }
    return 0;
}
