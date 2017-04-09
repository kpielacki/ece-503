#include <iostream>
#include <string>
#include "Account.h"
#include "BankAccount.h"


int main() {
    int menu_selection;
    bool checking_menu = true;
    double amount;
    
    BankAccount checking;

    while (checking_menu) {

        std::cout << std::endl << "Please select an option:" << std::endl;
        std::cout << "1. View account balance" << std::endl;
        std::cout << "2. Deposit money" << std::endl;
        std::cout << "3. Withdraw money" << std::endl;
        std::cout << "4. Print out history" << std::endl;
        std::cout << "5. Return to previous menu" << std::endl << std::endl;
        std::cout << "Option: ";
        std::cin >> menu_selection;

        switch (menu_selection) {
            case 1: {
               checking.view_account_balance();
               break;
            } case 2: {
                std::cout << "Please select the amount you wish to deposit: $";
                std::cin >> amount;
                checking.deposit(amount);
                break;
            } case 3: {
                std::cout << "Please select the amount you with to withdraw: $";
                std::cin >> amount;
                checking.withdraw(amount);
                break;
            } case 4: {
                std::cout << 4 << std::endl;
                break;
            } case 5: {
                std::cout << "Exiting checking menu." << std::endl;
                checking_menu = false;
                break;
            } default: {
                std::cout << "Invalid menu selection" << std::endl;
            }
        }
    }

    return 0;
}
