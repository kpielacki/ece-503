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
    if (mySize == 0) {
        std::cout << "Your list is empty." << std::endl;
    } else {
        Node *item;
        item = myHead;
        for (int i = 0; i < mySize; i++) {
            std::cout << item->itemNo << "\t" << item->itemName << std::endl;
            item = item->next;
        }
    }
}


void LinkedList::addToStart(Node *new_node) {
    if (size() == 0) {
        new_node->next = NULL;
        myHead = myTail = new_node;
    } else {
        new_node->next = myHead;
        myHead = new_node;
    }
    mySize++;
}


void LinkedList::addToEnd(Node *new_node) {
    new_node->next = NULL;
    if (size() == 0) {
        myHead = myTail = new_node;
    } else {
        myTail->next = new_node;
        myTail = new_node;
    }
    mySize++;
}


bool LinkedList::removeFromStart() {
    if (size() == 0) {
        return false;
    } else {
        Node *temp_item;
        temp_item = myHead;
    
        if (size() == 1) {
            myHead = myTail = NULL;
        } else {
            myHead = temp_item->next;
        }

        // Free memory from removed item.
        delete temp_item;

        // Track size change after node removed.
        mySize--;
        return true;
    }
}
