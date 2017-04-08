#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <string>
#include "kevin_pielacki_Node.h"

class LinkedList {

    public:
        LinkedList();
        ~LinkedList();
        int size() const;
        void addToStart(Node *);
        void addToEnd(Node *);
        void printList();
        bool removeFromStart();
        bool removeFromEnd();
        void removeNodeFromList(int);
        void removeNodeFromList(std::string);

    private:
        Node *myHead;
        Node *myTail;
        int mySize;
};

#endif
