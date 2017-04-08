#include <iostream>
#include "LinkedList.h"
#include "Node.h"

LinkedList::LinkedList() {
    mySize = 0;
    myHead = NULL;
    myTail = NULL;
}


LinkedList::~LinkedList() {

}


// Getter for mySize.
int LinkedList::size() const {
    return mySize;
}


void LinkedList::printList() {
    // Check if list is empty.
    if (mySize == 0) {
        std::cout << "Your list is empty." << std::endl;
    } else {
        Node *item;
        item = myHead;
        
        // Print field header.
        std::cout << "Item No\tItem Name" << std::endl;
        // Use mySize to keep track of how many pointers to reference.
        // This could of been achieved with using a while condition until
        // a NULL entry is found meaning the last node was found but I chose
        // to use mySize instead.
        for (int i = 0; i < mySize; i++) {
            // Print item number and item name.
            std::cout << item->itemNo << "\t" << item->itemName << std::endl;
            item = item->next;
        }
    }
}


void LinkedList::addToStart(Node *new_node) {
    if (size() == 0) {
        // Make sure last node's next pointer points to NULL.
        new_node->next = NULL;
        // If first node set head and tail to new node.
        myHead = myTail = new_node;
    } else {
        // Set new node's next pointer to the former head.
        new_node->next = myHead;
        // Set head to new node entry.
        myHead = new_node;
    }
    mySize++;
}


void LinkedList::addToEnd(Node *new_node) {
    // Make sure last node's next pointer points to NULL.
    new_node->next = NULL;

    // If first node just set head and tail to new entry.
    if (size() == 0) {
        myHead = myTail = new_node;
    } else {
        // Assign former tail to new node entry.
        myTail->next = new_node;
        // Set tail to new node entry.
        myTail = new_node;
    }
    mySize++;
}


bool LinkedList::removeFromStart() {
    if (size() == 0) {
        // Return false when nothing to delete.
        return false;
    } else {
        Node *temp_item;
        temp_item = myHead;
   
        if (size() == 1) {
            // Set first node to NULL if only node in list.
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


bool LinkedList::removeFromEnd() {
    if (size() == 0) {
        // Return false when nothing to delete.
        return false;
    } else {
        Node * prev_item;
        Node *temp_item;
        prev_item = myHead;
        temp_item = myTail;
    
        if (size() == 1) {
            // Set first node to NULL if only node in list.
            myHead = myTail = NULL;
            // Delete only node to freem memory.
            delete temp_item;
        } else {
            // Get second to last node in linked list.
            for (int i = 0; i < mySize - 2; i++) {
               prev_item = prev_item->next;
            }
            // Delete last node to free memory.
            delete temp_item;
            // Set second to last node next point to NULL and
            // update myTail making it the new last node.
            prev_item->next = NULL;
            myTail = prev_item;
        }

        // Track size change after node removed.
        mySize--;
        return true;
    }
}


void LinkedList::removeNodeFromList(int itemNo_rm) {

    if (size() > 0) {
        // Call removeFromStart until first node does not contain the item to
        // be removed.
        while (true) {
            // Break if no nodes left in list.
            if (myHead != NULL) {
                if (myHead->itemNo == itemNo_rm) {
                    // Let removeFromStart handle first node removal.
                    removeFromStart();
                } else {
                    // Break to move on to center nodes in list.
                    break;
                }
            } else {
                break;
            }
        }

        // Handle center nodes in linked list excluding myHead and myTail
        if (myHead != NULL) {
            Node *prev_item = myHead;
            Node *item = prev_item->next;

            // Keep the current size of the linked list to iterate through all
            // nodes. If a node is removed mySize is decremented causing one
            // less node to be checked.
            int current_size = size();
            for (int i = 1; i < current_size - 1; i++) {
                std::cout << item->itemName << std::endl;
                if (item->itemNo == itemNo_rm) {
                    // Change previous item's next to skip node to be deleted.
                    prev_item->next = item->next;
                    //std::cout << "Removing " << item->itemName << std::endl;
                    // Remove item with matching itemNo to free memory.
                    delete item;
                    // Set item to next node in linked list.
                    item = prev_item->next;
                    // Decrement mySize after node removal.
                    mySize--;
                } else {
                    prev_item = item;
                    item = item->next;
                }
            }
        }

        // Handle last node in linked list to update myTail.
        if (myTail != NULL) {
            if (myTail->itemNo == itemNo_rm) {
                removeFromEnd();
            }
        }
    }
} 

