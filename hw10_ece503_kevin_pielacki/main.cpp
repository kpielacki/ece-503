#include <iostream>
#include <string>
#include "LinkedList.h"
#include "Node.h"


void show_menu() {

    std::cout << std::endl;
    std::cout << "Menu Selection:" << std::endl;
    std::cout << "  1. Add a shopping item at the beginning" << std::endl;
    std::cout << "  2. Add a new shopping item at the end" << std::endl;
    std::cout << "  3. Remove the beginning shopping item" << std::endl;
    std::cout << "  4. Remove the end shopping item" << std::endl;
    std::cout << "  5. Remove a shopping item from the list by entering an item number" << std::endl;
    std::cout << "  6. Remove a shopping item from the list by entering an item name" << std::endl;
    std::cout << "  7. Print out shopping list" << std::endl;
    std::cout << "  8. Quit" << std::endl << std::endl;
    std::cout << "Please select an option: ";
}


// Prompts user to enter an item name and returns selection.
std::string prompt_item_name() {
    std::string item_name;
    std::cout << "Please enter the item name: ";
    std::cin >> item_name;
    return item_name;
}


// Prompts user to enter an item number and returns selection.
int prompt_item_number() {
    int item_number;
    std::cout << "Please enter the item number: ";
    std::cin >> item_number;
    return item_number;
}


int main() {
    int menu_selection, item_number;
    bool del_success;
    std::string item_name;
    LinkedList shopping_list;

    // Show menu selection until user quits.
    do {
        show_menu();
        std::cin >> menu_selection;
        switch (menu_selection) {
            case 1: {
                std::cout << "Adding new item to beginning of list." << std::endl;
                item_number = prompt_item_number();
                item_name = prompt_item_name();

                // Create new node to put at start of shopping list.
                Node* new_item = new Node(item_name, item_number);
                shopping_list.addToStart(new_item);
                break;
            } case 2: {
                std::cout << "Adding new item to end of list." << std::endl;
                item_number = prompt_item_number();
                item_name = prompt_item_name();

                // Create new node to put at end of shopping_list.
                Node* new_item = new Node(item_name, item_number);
                shopping_list.addToEnd(new_item);
                break;
            } case 3: {
                // Try to remove first item in shopping list.
                del_success = shopping_list.removeFromStart();

                // Print if item removal was successful.
                if (del_success) {
                    std::cout << "Removed item from beginning of list." << std::endl;
                } else {
                    std::cout << "Your shopping list is already empty." << std::endl;
                }
                break;
            } case 4: {
                // Try to remove last item in shopping_list.
                del_success = shopping_list.removeFromEnd();

                // Print if item removal was successful.
                if (del_success) {
                    std::cout << "Removed item from end of list." << std::endl;
                } else {
                    std::cout << "Your shopping list is already empty." << std::endl;
                }
                break;
            } case 5: {
                std::cout << "Removing shopping list item by item number." << std::endl;
                item_number = prompt_item_number();

                // Remove any nodes with entered item number.
                shopping_list.removeNodeFromList(item_number);
                break;
            } case 6: {
                std::cout << "Removing shopping list item by item name." << std::endl;
                item_name = prompt_item_name();
                                                                                         
                // Remove any nodes with entered item name.
                shopping_list.removeNodeFromList(item_name);
                break;
            } case 7: {
                shopping_list.printList();
                break;
            } case 8: {
                std::cout << "Quitting" << std::endl;
                break;
            } default: {
                std::cout << "Invalid menu selection. Please try again."<< std::endl;
            }
        }

    } while (menu_selection != 8);

    return 0;
}
