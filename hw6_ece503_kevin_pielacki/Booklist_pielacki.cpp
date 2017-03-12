#include "Booklist_pielacki.h"
#include <iostream>
#include <string>


BookList::BookList() {
    // Set initial book count to zero.
    book_cnt = 0;

    // Set max book count. Possibly reinitate books to
    // this size as a passed value. Also helpful for
    // handling max book capacity.
    max_book_cnt = 20;

    // Set book list to be sorted initially since empty.
    sorted = true;

    return;
}


bool BookList::max_books() {
    // Return true if book_list at max books.
    if (BookList::book_cnt >= BookList::max_book_cnt) {
        return true;
    }
    return false;
}


bool BookList::get_sorted() {
    // Public access value of sorted.
    return BookList::sorted;
}


void BookList::set_sorted(bool is_sorted) {
    // Private set value of sorted.
    // Not really needed since it's private but for the sake
    // of showing a setter.
    BookList::sorted = is_sorted;
    return;
}


int BookList::find_book(int isbn) {
    // Return index of first found passed isbn in books
    // otherwise return negative value.
    // Instance variable books should always contain a unique
    // list of books.
    for (int i = 0; i < BookList::book_cnt; i++) {
        // If element found return position.
        if (books[i] == isbn) {
            return i;
        }
    }
    return -1;
}


int BookList::find_book_binary(int isbn) {
    // Return index of first found passed isbn in books
    // otherwise return negative value using binary search.
    // Instance variable books should always contain a unique
    // list of books.
    int center_pos = BookList::book_cnt / 2;
    int new_center_pos = BookList::book_cnt / 2;
    int high_pos = BookList::book_cnt;
    int low_pos = 0;

    // Refuse to search unsorted list.
    if (BookList::sorted) {
        // Keep searching if there are unchecked elements that could
        // hold the needed value or value found.
        while (true) {
            if (books[center_pos] == isbn) {
                // If center_pos index is search isbn return index.
                return center_pos;
            } else if (books[center_pos] > isbn) {
                // If search isbn smaller than center_pos.
                high_pos = center_pos;
                new_center_pos = low_pos + (high_pos - low_pos) / 2;
            } else {
                // If search isbn larger than center_pos.
                low_pos = center_pos;
                new_center_pos = low_pos + (high_pos - low_pos) / 2;
            }
            // If new calculated postion is the same return -1 to indicate
            // search isbn does not exist in book list.
            if (center_pos == new_center_pos) {
                return -1;
            } else {
                // Assign new calculated position to check next iteration.
                center_pos = new_center_pos;
            }
        }
    }
    return -1;
}


void BookList::insert(int isbn) {

    if (BookList::max_books()) {
        std::cout << "Cannot add book to list. Max book limit of "
        << BookList::max_book_cnt << "." << std::endl;
        return;
    }
    int dup_index;
    dup_index = BookList::find_book(isbn);
    // Handle book already in list.
    if (dup_index >= 0) {
        std::cout << "Duplicate book found. Shifting to end of list." << std::endl;
        // Delete duplicate book. Book count decrement handled in method.
        BookList::delete_at(dup_index + 1);
    }
    BookList::books[BookList::book_cnt] = isbn;
    BookList::book_cnt++;

    // If list is sorted and more than one book check if new value breaks sorting.
    if (BookList::sorted and BookList::book_cnt > 1) {
        if (BookList::books[BookList::book_cnt - 1] < BookList::books[BookList::book_cnt - 2]) {
            // Set sorted to false when new insert breaks sorting.
            BookList::set_sorted(false);
        }
    }
    return;
}


void BookList::insert_at(int at_position, int isbn) {
    if (BookList::max_books()) {
        std::cout << "Cannot add book to list. Max book limit of "
        << BookList::max_book_cnt << "." << std::endl;
        return;
    }

    // Only allow insert up to current number of books + 1.
    if (at_position > BookList::book_cnt + 1) {
        std::cout << "Cannot add book to index " << at_position << ". Currently only "
        << BookList::book_cnt << " in list." << std::endl;
    } else if (at_position < 1) {
        // Tell user the valid number selections.
        std::cout << "Must select a number from 1 to " << BookList::book_cnt + 1 << "."
        << std::endl;
    } else {
        // Handle book already in list.
        int dup_index;
        dup_index = BookList::find_book(isbn);
        if (dup_index >= 0) {
            if (at_position > BookList::book_cnt) {
                std::cout << "Cannot add duplicated book into new index." << std::endl;
                return;
            }
            std::cout << "Duplicate book found. Shifting to new index." << std::endl;
            // Delete duplicate book. Book count decrement handled in method.
            BookList::delete_at(dup_index + 1);
        }
        // Iterate backward to shift all books up.
        for (int i = BookList::book_cnt; i >= at_position; i--) {
            BookList::books[i] = BookList::books[i - 1];
        }

        // Set passed postion to passed isbn.
        BookList::books[at_position - 1] = isbn;
        BookList::book_cnt++;

        // If list is sorted and more than one book check if new value breaks sorting.
        if (BookList::sorted and BookList::book_cnt > 1) {
            if (at_position == 1) {
                // Only need to compare element afterwards if insert at first index.
                if (BookList::books[at_position - 1] > BookList::books[at_position]) {
                    // Set sorted to false when new insert breaks sorting.
                    BookList::set_sorted(false);
                }
            } else if (BookList::book_cnt + 1 == at_position) {
                // If inserted at end of list only compare element before.
                if (BookList::books[at_position - 1] < BookList::books[at_position - 2]) {
                    // Set sorted to false when new insert breaks sorting.
                    BookList::set_sorted(false);
                }
            }
            else {
                // Check if new element breaks sorting left and right to index.
                if (BookList::books[at_position - 1] > BookList::books[at_position] or BookList::books[at_position - 1] < BookList::books[at_position - 2]) {
                    // Set sorted to false when new insert breaks sorting.
                    BookList::set_sorted(false);
                }   
            }
        }
    }
    return;
}


void BookList::delete_at(int at_position) {
    // Delete book at index specified (1 is first index).
    // If not valid position tell user.
    if (at_position > BookList::book_cnt) {
        std::cout << "Cannot delete book at index " << at_position << ". Currently only "
        << BookList::book_cnt << " in list." << std::endl;
    } else if (BookList::book_cnt == 0) {
        std::cout << "Your current book list is empty." << std::endl;
    } else if (at_position < 1) {
        // Tell user the valid number selections.
        std::cout << "Must select a number from 1 to " << BookList::book_cnt << "."
        << std::endl;
    } else{
        // Shift values down. Offset starting index by -1.
        for (int i = at_position - 1; i < BookList::book_cnt; i++) {
            if (i + 1 >= BookList::max_book_cnt) {
                // Set last index to invalid isbn number.
                // This will never be read since the book_cnt will decrease.
                BookList::books[i] = -1;
            } else {
                // Shift values down.
                BookList::books[i] = BookList::books[i + 1];
            }
        }
        BookList::book_cnt--;
    }
    return;
}


void BookList::delete_isbn(int isbn) {
    // Delete book with passed isbn.
    for (int i = 0; i < BookList::book_cnt; i++) {
        // If index contains passed isbn call delete_at for that index + 1.
        if (BookList::books[i] == isbn) {
            BookList::delete_at(i + 1);
            std::cout << "ISBN " << isbn << " removed from your list." << std::endl;
            return;
        }
    }
    // If no book was found with that ISBN let user know.
    std::cout << "No book found in your list with ISBN " << isbn << "." << std::endl;
    return;
}


void BookList::sort_books_selection() {
    int temp;
    int *array_val;
    int swap_index;

    // Set pointer to books array.
    array_val = BookList::books;
    for (int i = 0; i < BookList::book_cnt; i++) {
        // Set initial value to first element.
        // Use iterator offset to access elements.
        int current_min = *(array_val + i);
        // Set swap to current index. Will overwrite if lesser value found.
        swap_index = i;
        for (int j = i + 1; j < BookList::book_cnt; j++) {
            // Select min element and set to first value with
            // offset to ignore sorted elements.
            if (*(array_val + j) < current_min) {
                current_min = *(array_val + j);
                swap_index = j;
            }
        }
        // Swap current min with current unsorted element.
        *(array_val + swap_index) = *(array_val + i);
        *(array_val + i) = current_min;
    }
    // Set sorted to true.
    BookList::set_sorted(true);
    return;
}


void BookList::sort_books_bubble() {
    int *array_val;
    int temp;
    array_val = BookList::books;

    for (int i = 0; i < BookList::book_cnt; i++) {
        // Iterate to last element - sorted max elements - 1 for offset.
        for (int j = 0; j < BookList::book_cnt - i - 1; j++) {
            // Swap current and current + 1 element if greater moving max
            // value to end of list.
            if (*(array_val + j) > *(array_val + j + 1)) {
                temp = *(array_val + j);
                *(array_val + j) = *(array_val + j + 1);
                *(array_val + j + 1) = temp;
            }
        }
    }
    // Set sorted to true.
    BookList::set_sorted(true);
    return;
}


void BookList::print_list() {
    // Print current book list
    std::cout << "----- Book List -----" << std::endl;
    for (int i = 0; i < BookList::book_cnt; i++) {
        std::cout << i + 1 << ") " << BookList::books[i] << std::endl;
    }
    std::cout << "---------------------" << std::endl << std::endl;
    return;
}
