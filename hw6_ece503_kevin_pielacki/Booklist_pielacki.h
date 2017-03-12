#ifndef BookList_H
#define BookList_H


class BookList {

    public:
        BookList();
        bool max_books();
        void insert(int isbn);
        void insert_at(int at_position, int isbn);
        int find_book(int isbn);
        int find_book_binary(int isbn);
        void delete_at(int at_position);
        void delete_isbn(int isbn);
        void sort_books_selection();
        void sort_books_bubble();
        void print_list();
        // Public getter to avoid user modifying.
        bool get_sorted();

    private:
        int max_book_cnt;
        int books[20];
        int book_cnt;
        bool sorted;

        // For the sake of having a setter.
        void set_sorted(bool is_sorted);
};

#endif
