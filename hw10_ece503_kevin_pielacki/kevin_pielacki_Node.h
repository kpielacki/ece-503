#ifndef NODE_H_
#define NODE_H_

#include <string>

class Node {

    friend class LinkedList;

    public:
        Node(std::string& name, int no):itemName(name), itemNo(no) {
            this->next=NULL;
        }
    private:
        std::string itemName;
        int itemNo;
        Node *next;
};

#endif
