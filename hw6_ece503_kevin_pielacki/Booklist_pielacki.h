#ifndef BookList_H
#define BookList_H


class BookList {

    public:
        BookList();
        bool max_books();
        void insert(int isbn);
        void insert_at(int at_position, int isbn);
        int find_book(int isbn);
        void delete_at(int at_position);
        void delete_isbn(int isbn);
        void sort_books_selection();
        void print_list();

    private:
        int max_book_cnt;
        int books[20];
        int book_cnt;
};

#endif
