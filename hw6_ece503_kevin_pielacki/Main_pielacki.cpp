#include <iostream>
#include <string>
#include "Booklist_pielacki.h"


int main() {
    bool in_menu = true;
    int user_selection;
    int isbn_select = 0;
    int pos_select;

    BookList mybooks;

    while (in_menu) {
        std::cout << "-----Select an Option-----" << std::endl;
        std::cout << "\t1. Insert new book at the end of the list" << std::endl;
        std::cout << "\t2. Insert new book at a certain position" << std::endl;
        std::cout << "\t3. Find a book (with its ISBN number and list its position) using linear search" << std::endl;
        std::cout << "\t4. Find a book (with its ISBN number and list its position) of a sorted list using binary search" << std::endl;
        std::cout << "\t5. Delete a book that is at a certain position" << std::endl;
        std::cout << "\t6. Delete a book by using its ISBN number" << std::endl;
        std::cout << "\t7. Sort the list of books by the ISBN numbers (using selection sort)" << std::endl;
        std::cout << "\t8. Sort the list of books by the ISBN numbers (using bubble sort)" << std::endl;
        std::cout << "\t9. Print out the list" << std::endl;
        std::cout << "\t10. Quit" << std::endl;
        std::cout << "\nPlease select a menu option: ";

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
                break;
            }
            case 4 : {
                break;
            }
            case 5 : {
                std::cout << "Select a position to delete: ";
                std::cin >> pos_select;
                mybooks.delete_at(pos_select);
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
