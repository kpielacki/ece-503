#include "Booklist_pielacki.h"
#include <iostream>


BookList::BookList() {
    // Set initial book count to zero.
    book_cnt = 0;

    // Set max book count. Possibly reinitate books to
    // this size as a passed value. Also helpful for
    // handling max book capacity.
    max_book_cnt = 5;

    return;
}

bool BookList::max_books() {
    // Return true if book_list at max books.
    if (BookList::book_cnt >= BookList::max_book_cnt) {
        return true;
    }
    return false;
}

int BookList::find_book(int isbn) {
    // Return index of first found passed isbn in books
    // otherwise return larger than possible value.
    // Object variable books should always contain a unique
    // list of books.
    for (int i = 0; i < BookList::book_cnt; i++) {
        if (books[i] == isbn) {
            return i;
        }
    }
    return BookList::max_book_cnt + 1;
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
    if (dup_index < BookList::max_book_cnt) {
        std::cout << "Duplicate book found. Shifting to end of list." << std::endl;
        // Delete duplicate book. Book count decrement handled in method.
        BookList::delete_at(dup_index + 1);
    }
    BookList::books[BookList::book_cnt] = isbn;
    BookList::book_cnt++;
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
        if (dup_index < BookList::max_book_cnt) {
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
            std::cout << i << std::endl;
            BookList::books[i] = BookList::books[i - 1];
        }

        // Set passed postion to passed isbn.
        BookList::books[at_position - 1] = isbn;
        BookList::book_cnt++;
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


void BookList::print_list() {
    std::cout << "--- Book List ---" << std::endl;
    for (int i = 0; i < BookList::book_cnt; i++) {
        std::cout << i + 1 << ") " << BookList::books[i] << std::endl;
    }
    std::cout << "-----------------" << std::endl << std::endl;
    return;
}
