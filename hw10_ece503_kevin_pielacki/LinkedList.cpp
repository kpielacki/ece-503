#include <iostream>
#include "LinkedList.h"
#include "Node.h"

LinkedList::LinkedList() {
    mySize = 0;
}


LinkedList::~LinkedList() {

}


int LinkedList::size() const {
    return mySize;
}


void LinkedList::printList() {
    Node *item;
    item = myHead;
    for (int i = 0; i < mySize; i++) {
        std::cout << item->itemNo << "\t" << item->itemName << std::endl;
        item = item->next;
    }
}


void LinkedList::addToStart(Node *new_node) {
    if (size() == 0) {
        myHead = myTail = new_node;
        new_node->next = NULL;
    } else {
        new_node->next = myHead;
        myHead = new_node;
    }
    mySize++;
}
