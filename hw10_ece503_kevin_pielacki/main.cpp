#include <iostream>
#include <string>
#include "LinkedList.h"
#include "Node.h"


void show_menu() {
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


int main() {
    int menu_selection;

    do {
        show_menu();
        std::cin >> menu_selection;
        switch (menu_selection) {
            case 1: {
                std::cout << 1 << std::endl;
                break;
            } case 2: {
                std::cout << 2 << std::endl;
                break;
            } case 3: {
                std::cout << 3 << std::endl;
                break;
            } case 4: {
                std::cout << 4 << std::endl;
                break;
            } case 5: {
                std::cout << 5 << std::endl;
                break;
            } case 6: {
                std::cout << 6 << std::endl;
                break;
            } case 7: {
                std::cout << 7 << std::endl;
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
